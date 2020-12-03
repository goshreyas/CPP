
/*
Syntax:

#include <mutex>
mutex m;
m.lock()    //<----------------  Blocking Call 
----  <Code Block>   -----
m.unlock()

*/

/*
How does #include <bits/stdc++.h> work in C++?
Ref:
- https://stackoverflow.com/questions/25311011/how-does-include-bits-stdc-h-work-in-c
- https://gcc.gnu.org/onlinedocs/gcc-4.8.0/libstdc++/api/a01541_source.html
*/

//==================================================================

#include<bits/stdc++.h>
//#include<thread>
//#include<mutex>

using namespace std;

int myAmount = 0;
mutex m;

void addMoney() {
	m.lock();
	++myAmount;
	m.unlock();
}

int main() {
	thread t1(addMoney);
	thread t2(addMoney);
	t1.join();
	t2.join();
	cout << myAmount << endl;
	return 0;
}
/*
Compile & Test:
#> g++ -std=c++11 -pthread -g mutex.cpp
#> g++ -std=c++11 -pthread -g mutex.cpp -o mutex.out
#> ./<binary:a.out/mutex.out>
*/

/*
Ref: 
https://www.youtube.com/watch?v=eZ8yKZo-PGw&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=4
*/

//==================================================================








