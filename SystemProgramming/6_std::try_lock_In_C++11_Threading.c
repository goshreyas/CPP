


//======================================<Code Block(S)>======================================


#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

int X=0, Y=0;
std::mutex m1, m2;

void doSomeWorkForSeconds(int seconds) { std::this_thread::sleep_for(std::chrono::seconds(seconds)); }

void incrementXY(int& XorY, std::mutex& m, const char* desc) {
	for(int i=0; i<5; ++i){
		m.lock();
		++XorY;
		cout << desc << XorY << '\n';
		m.unlock();
		doSomeWorkForSeconds(1);
	}
}

void consumeXY () {
	int useCount = 5;
	int XplusY = 0;
	while(1){
		int lockResult = std::try_lock(m1,m2);  // <---------------------- NOTE How to Use
		if(lockResult == -1) {  // <---------------------- NOTE How to Use
			if(X!=0 && Y!=0){
				--useCount;
				XplusY+=X+Y;
				X = 0;
				Y = 0;
				cout << "XplusY " << XplusY << '\n';
			}
			m1.unlock();  // <---------------------- NOTE How to Use
			m2.unlock();  // <---------------------- NOTE How to Use
			if(useCount == 0) break;
		}
	}
}

int main() {
	std::thread t1(incrementXY, std::ref(X), std::ref(m1), "X ");    // <------------ NOTE The use of ref()
	std::thread t2(incrementXY, std::ref(Y), std::ref(m2), "Y ");    // <------------ NOTE The use of ref()
	std::thread t3(consumeXY);

	t1.join();
	t2.join();
	t3.join();

	return 0;
} 


/*
Output:

srb-go3@slave-node:~/dev_space/CPP_concurrency$ g++ -std=c++11 -pthread -g 6_std_try_lock.cpp 
srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
X Y 1
1
XplusY 2
X 1
Y 1
XplusY 4
X 1
Y 1
XplusY 6
X 1
Y 1
XplusY 8
X 1
Y 1
XplusY 10
srb-go3@slave-node:~/dev_space/CPP_concurrency$ 

*/

//======================================<Code Block(E)>======================================



