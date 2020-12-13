

//======================================<Code Block(S)>======================================

#include<bits/stdc++.h>
using namespace std;

int balance = 0;
mutex mtx;
condition_variable cv;

void depositMoney(int amount) {
	lock_guard<mutex> lock(mtx);
	balance += amount;
	cout << "Amount Added to Current Balance: " << amount << endl;
	cv.notify_all();
	cout << "Curent Balance: " << balance << endl;
	return;
}

void withdrawMoney1(int amount) {
	unique_lock<mutex> lock(mtx);
	int bal = balance;
	//cv.wait(lock, [&amount] () {return (balance >= amount);});  // Working
	//cv.wait(lock, [&amount, &bal] () {return (bal >= amount);}); // Working
	cv.wait(lock, [&amount, &bal] {return (bal >= amount);}); // Working
	balance -= amount;
	cout << "Curent Balance: " << balance << endl;
	return;
}

void withdrawMoney(int amount) {
	unique_lock<mutex> lock(mtx);
	cv.wait(lock, []() {return (balance > 0);});
	if(balance >= amount) {
		balance -= amount;
		cout << "Amount Deducted: " << amount << endl;
	} else {
		cout << "Insufficient Balance." << endl;
	}
	cout << "Curent Balance: " << balance << endl;
	return;
}



int main() {
	thread t1(depositMoney, 10);
	thread t2(withdrawMoney, 5);
	if(t1.joinable()) t1.join();
	if(t2.joinable()) t2.join();
	return 0;
}


/*
srb-go3@slave-node:~/dev_space/CPP_concurrency$ g++ -std=c++11 -pthread -g 11_condition_variable.cpp 
srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
Amount Added to Current Balance: 10
Curent Balance: 10
Amount Deducted: 5
Curent Balance: 5
srb-go3@slave-node:~/dev_space/CPP_concurrency$ 

*/

//======================================<Code Block(E)>======================================





