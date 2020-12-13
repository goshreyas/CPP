


//======================================<Code Block(S)>======================================
#include<bits/stdc++.h>
using namespace std;

class BankAcc {
	int balance;
	mutex mtx;
	condition_variable cv;

public:
	BankAcc(): balance(0) {}

	void depositMoney(int amount) {
		lock_guard<mutex> lock(mtx);
		balance += amount;
		cout << "Amount Added to Current Balance: " << amount << endl;
		cv.notify_all();
		cout << "Curent Balance: " << balance << endl;
		return;
	}

	void withdrawMoney(int amount) {
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, [this]() {return (balance > 0);});
		if(balance >= amount) {
			balance -= amount;
			cout << "Amount Deducted: " << amount << endl;
		} else {
			cout << "Insufficient Balance." << endl;
		}
		cout << "Curent Balance: " << balance << endl;
		return;
	}
};

int main() {
	BankAcc acc1;
	thread t1(&BankAcc::depositMoney, &acc1, 10);
	thread t2(&BankAcc::withdrawMoney, &acc1, 5);
	if(t1.joinable()) t1.join();
	if(t2.joinable()) t2.join();
	return 0;
}


/*
srb-go3@slave-node:~/dev_space/CPP_concurrency$ g++ -std=c++11 -pthread -g 11_condition_variable_v2.cpp
srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
Amount Added to Current Balance: 10
Curent Balance: 10
Amount Deducted: 5
Curent Balance: 5
srb-go3@slave-node:~/dev_space/CPP_concurrency$ 

*/


//======================================<Code Block(E)>======================================




