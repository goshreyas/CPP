



//======================================<Code Block(S)>======================================

//#include<bits/std++.h>
#include <bits/stdc++.h>
//use namespece std;
using namespace std;

class my_thread_pool {
private:
    vector<thread> threads;
    atomic_bool done;
    queue<function<void()>> jobs;
    mutex mtx;
    condition_variable cv;

    void pool_job1() { // Issue: Thread never End.
        while(!done) {
            function<void()> work;
            unique_lock<mutex> locker(mtx);
            cv.wait(locker, [this](){return (jobs.size()>0);});
            work = jobs.front();
            jobs.pop();
            //cv.unlock();
            locker.unlock();
            cv.notify_all();
            work();
        }
    }


    bool getAJob(function<void()> &work) {
        lock_guard<mutex> lock(mtx);
        if(jobs.size() > 0) {
            work = jobs.front();
            jobs.pop();
            return true;
        }
        return false;
    }

    void pool_job() {
        while(!done) {
            function<void()> work;
            if(getAJob(work) == true) {
                work();
            } else{
                //this_thread::yeild();
                this_thread::yield();
            }
        }
    }

public:
	my_thread_pool(): done(false) {
		//int max_threads = thread::hardware_synchronization();   // ??
		int max_threads = thread::hardware_concurrency();
		try
		{
			for(int i=0; i<max_threads; i++)
			{
				thread th = thread(&my_thread_pool::pool_job, this);
				threads.push_back(move(th));
			}
		}
		catch(...)
		{
			cout << "Exception!, Terminating...\n";
			done = true;
		}

	}
	~my_thread_pool() {
        done = true;
        for(int i=0; i<threads.size(); i++) {
            if(threads[i].joinable())
                threads[i].join();
        }
    }
    //template<datatype F>   // ??
    template<typename F>   // ??
    void schedule_jobs(F functionTask) {
        //lock_block<mutex> lock(mtx);
        lock_guard<mutex> lock(mtx);
        cv.notify_all();
        jobs.push(functionTask);
    }
};

void job1() {
    cout << "Job1 InProgress\n";
    //this_thread::sleep();  // ?
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Job1 Completed\n";
    return;
}

void job2() {
    cout << "Job2 InProgress\n";
    //this_thread::sleep();  // ?
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Job2 Completed\n";
    return;
}

int main() {
    my_thread_pool thPool;
    thPool.schedule_jobs(job1);
    thPool.schedule_jobs(job2);
    return 0;
}


/*
Compile & Test:
#> g++ -std=c++11 -pthread -g my_thread_pool.cpp
#> a.out

Output:
srb-go3@slave-node:~/dev_space/CPP_concurrency$ g++ -std=c++11 -pthread -g my_thread_pool.cpp
srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
Job1 InProgress
Job2 InProgress
Job2 Completed
Job1 Completed
srb-go3@slave-node:~/dev_space/CPP_concurrency$

*/


//======================================<Code Block(E)>======================================




