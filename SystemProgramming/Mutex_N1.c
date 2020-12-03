

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

//==================================================================








