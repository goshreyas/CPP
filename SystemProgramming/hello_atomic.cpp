


/*

*/

#include<bits/stdc++.h>
using namespace std;

mutex mtx;
atomic<int> cnt(0);

void updateCnt(int th, int n) {
	printf("Thread %d, going to sleep for %dSec\n", th, n);
	//cout<< "\nGoing to Sleep for :" << count << " seconds";
	this_thread::sleep_for(chrono::seconds(n));
	cnt++;
	printf(" Count %d\n", cnt.load());
}

int main() {
	//thread t1(updateCnt, 1, 100), t2(updateCnt, 2, 100), t3(updateCnt, 3, 100);
	vector<thread> threads;
	int threadCnt = 5;
	for(int t=0; t<threadCnt; ++t) {
		thread th = thread(updateCnt, t, 1);
		threads.push_back(move(th));
	}

	for(int t=0; t<threadCnt; ++t) {
		if(threads[t].joinable());
			threads[t].join();
	}

	return 0;
}


/*
go5@go5-virtual-machine:~/mySpace/system_programming$ g++ -std=c++11 -pthread -g hello_atomic.cpp 
go5@go5-virtual-machine:~/mySpace/system_programming$ ./a.out 
Thread 1, going to sleep for 1Sec
Thread 4, going to sleep for 1Sec
Thread 2, going to sleep for 1Sec
Thread 3, going to sleep for 1Sec
Thread 0, going to sleep for 1Sec
 Count 1
 Count 2
 Count 3
 Count 4
 Count 5
go5@go5-virtual-machine:~/mySpace/system_programming$

*/

