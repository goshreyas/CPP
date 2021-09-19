

/*

*/

#include<bits/stdc++.h>
using namespace std;

mutex mtx;
int cnt = 0;

void updateCnt(int th, int n) {
	mtx.lock();
	printf("Thread %d, going to sleep for %dSec\n", th, n);
	//cout<< "\nGoing to Sleep for :" << count << " seconds";
	this_thread::sleep_for(chrono::seconds(n));
	cnt++;
	printf(" Count %d\n", cnt);
	mtx.unlock();
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
go5@go5-virtual-machine:~/mySpace/system_programming$ g++ -std=c++11 -pthread -g hello_mutex.cpp 
go5@go5-virtual-machine:~/mySpace/system_programming$ ./a.out 
Thread 0, going to sleep for 1Sec
 Count 1
Thread 1, going to sleep for 1Sec
 Count 2
Thread 2, going to sleep for 1Sec
 Count 3
Thread 3, going to sleep for 1Sec
 Count 4
Thread 4, going to sleep for 1Sec
 Count 5
go5@go5-virtual-machine:~/mySpace/system_programming$

*/
