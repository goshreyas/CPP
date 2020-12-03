



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

int count = 0;
mutex mtx;

void increaseCountBy100000Times() {
	for(int i=0; i<100000; i++) {
		//if(mtx.lock()) {
	        if(mtx.try_lock()) {
			++count;
			mtx.unlock();
		}
	}
}

int main() {
	thread t1(increaseCountBy100000Times);
	thread t2(increaseCountBy100000Times);
	t1.join();
	t2.join();
	cout << "Count: " << count << endl;
	return 0;
}

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





