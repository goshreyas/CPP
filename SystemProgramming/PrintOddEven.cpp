srb-go3@slave-node:~/system_programming$ cat print_odd_even.cpp
#include<bits/stdc++.h>
#include<thread>
#include<mutex>
using namespace std;

mutex mtx;
condition_variable cv;
int odd;

void printOdd(int num) {
	unique_lock<mutex> lock(mtx);
	for(int i=1; i<=num; i+=2) {
		cv.wait(lock, [&](){return (odd == 1);});
		printf("printOdd() Num: %d\n", i);
		odd = 0;
		cv.notify_all();
	}
}


void printEven(int num) {
	unique_lock<mutex> lock(mtx);
	for(int i=2; i<=num; i+=2) {
		cv.wait(lock, [&](){return (odd == 0);});
		printf("printEven() Num: %d\n", i);
		odd = 1;
		cv.notify_all();
	}
}


int main() {
	int N = 10;
	odd = 1;
	thread t1(printOdd, N), t2(printEven, N);
	t1.join();
	t2.join();
	return 0;
}
srb-go3@slave-node:~/system_programming$

srb-go3@slave-node:~/system_programming$ g++ -std=c++11 -pthread -g print_odd_even.cpp 
srb-go3@slave-node:~/system_programming$ ./a.out 
printOdd() Num: 1
printEven() Num: 2
printOdd() Num: 3
printEven() Num: 4
printOdd() Num: 5
printEven() Num: 6
printOdd() Num: 7
printEven() Num: 8
printOdd() Num: 9
printEven() Num: 10
srb-go3@slave-node:~/system_programming$ 
