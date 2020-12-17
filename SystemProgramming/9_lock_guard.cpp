


//======================================<Code Block(S)>======================================

#include <bits/stdc++.h>
using namespace std;

mutex mtx;
int buffer = 0;

void task(const char* threadNumber, int loopFor) {
	//mtx.lock();
    lock_guard<mutex> lock(mtx);  // This is same as mutex lock
	for(int i=0; i<loopFor; i++) {
		buffer++;
		cout << threadNumber << buffer << endl;
	}
	//lock.unlock(); // <-------------- NOTE This will not work for lock_guard, but will work for unique_lock
	//mtx.unlock();
}

int main() {
	thread tl(task, "T1: ", 10);
	thread t2(task, "T2: ", 10);
	tl.join();
	t2.join();
	return 0;
}

/*
srb-go3@slave-node:~/dev_space/CPP_concurrency$ g++ -std=c++11 -pthread -g 9_lock_guard.cpp 
srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
T1: 1
T1: 2
T1: 3
T1: 4
T1: 5
T1: 6
T1: 7
T1: 8
T1: 9
T1: 10
T2: 11
T2: 12
T2: 13
T2: 14
T2: 15
T2: 16
T2: 17
T2: 18
T2: 19
T2: 20
srb-go3@slave-node:~/dev_space/CPP_concurrency$ 
*/

//======================================<Code Block(E)>======================================
