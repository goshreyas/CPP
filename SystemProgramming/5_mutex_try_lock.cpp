
/*
Syntax:

#include <mutex>
mutex m;
//m.lock()    //<----------------  Blocking Call 
m.try_lock()    //<----------------  Non Blocking Call: Return from this if unable to lock
----  <Code Block>   -----
m.unlock()
*/

//======================================<Code Block(S)>======================================


#include<bits/stdc++.h>
//#include<thread>
//#include<mutex>

using namespace std;

int cnt_try_lock = 0, cnt_lock = 0;
mutex mtx1, mtx2;

void increaseCountBy100000Times_try_lock() {
	for(int i=0; i<100000; i++) {
		if(mtx1.try_lock()) 
		{
			++cnt_try_lock;
			mtx1.unlock();
		}
	}
}

void increaseCountBy100000Times_lock() {
	for(int i=0; i<100000; i++) {
		mtx2.lock();
		++cnt_lock;
		mtx2.unlock();
	}
}


int main() {
	thread t1_1(increaseCountBy100000Times_try_lock);
	thread t1_2(increaseCountBy100000Times_try_lock);
	thread t2_1(increaseCountBy100000Times_lock);
	thread t2_2(increaseCountBy100000Times_lock);
	t1_1.join();
	t1_2.join();
	t2_1.join();
	t2_2.join();
	cout << "Count(Try Lock): " << cnt_try_lock << endl;
	cout << "Count(Lock): " << cnt_lock << endl;
	return 0;
}


/*
Run Results:
srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
Count(Try Lock): 92820
Count(Lock): 200000
srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
Count(Try Lock): 89228
Count(Lock): 200000
srb-go3@slave-node:~/dev_space/CPP_concurrency$ 
*/

//++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Compile & Test:
#> g++ -std=c++11 -pthread -g mutex.cpp
#> g++ -std=c++11 -pthread -g mutex.cpp -o mutex.out
#> ./<binary:a.out/mutex.out>
*/


//======================================<Code Block(E)>======================================


/*
Ref: https://www.youtube.com/watch?v=UgcyOBUaR6M&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=5

*/





