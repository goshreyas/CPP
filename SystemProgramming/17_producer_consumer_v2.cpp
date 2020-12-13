

//======================================<Code Block(S)>======================================

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, string> pi; 
priority_queue<pi> myJobQueue;
mutex mtx;
condition_variable cv;

void producer(int times) {
	//lock_guard<mutex> lock(mtx);
	unique_lock<mutex> lock(mtx, defer_lock);
	for(int i=0; i<times; i++) {
		//this_thread::sleep_for(chrono::seconds(2));
		this_thread::sleep_for(chrono::milliseconds(1));
		int r = rand()%times;
		//int r = rand();
		cout << "Adding Num: " << r << endl;
		lock.lock();
		myJobQueue.push({r, to_string(r)});
		lock.unlock();
		cv.notify_all();
		//lock.unlock();
	}
	return;	
}

void consumer(int times) {
	this_thread::sleep_for(chrono::milliseconds(2000));
	unique_lock<mutex> lock(mtx);
	for(int i=0; i<times; i++) {
		//this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "Waiting in consumer ...\n";
		cv.wait(lock, [] () {return !myJobQueue.empty();});
		//this_thread::sleep_for(chrono::milliseconds(2000));
		pi var = myJobQueue.top();
		myJobQueue.pop();
		//lock.unlock();  // Mistake: This is not Require. This means  multiple unlock() call, which turn into crash.
		cout << "Consumed: " << var.second << endl;
	}
	return;
}


int main() {
	int times = 5;
	thread t1(producer, times);	
	thread t2(consumer, times);	
	if(t1.joinable()) t1.join();
	if(t2.joinable()) t2.join();
	return 0;
}

/*
srb-go3@slave-node:~/dev_space/CPP_concurrency$ g++ -std=c++11 -pthread -g 17_producer_consumer_v2.cpp 
srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
Adding Num: 3
Adding Num: 1
Adding Num: 2
Adding Num: 0
Adding Num: 3
Waiting in consumer ...
Consumed: 3
Waiting in consumer ...
Consumed: 3
Waiting in consumer ...
Consumed: 2
Waiting in consumer ...
Consumed: 1
Waiting in consumer ...
Consumed: 0
srb-go3@slave-node:~/dev_space/CPP_concurrency$

*/


//======================================<Code Block(E)>======================================




