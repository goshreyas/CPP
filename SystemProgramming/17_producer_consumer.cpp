

//======================================<Code Block(S)>======================================

#include<bits/stdc++.h>
using namespace std;

std::mutex mu;
std::condition_variable cond;
deque<int> buffer;
const unsigned int maxBufferSize = 50;
bool done = false;

void producer(int val) {
	std::thread::id my_id = std::this_thread::get_id(); // Get Thread ID
	cout << "\nProducer Thread ID: " << my_id << endl;
	while (val) {
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker, [](){return buffer.size() < maxBufferSize;});
		buffer.push_back(val);
		cout << "Produced: " << val << endl;
		//locker.unlock();
		//cond.notify_all();
		cond.notify_one();
		val--;
	} // while (vat)
	done = true;
}

void consumer() {
	std::thread::id my_id = std::this_thread::get_id(); // Get Thread ID
	cout << "\nConsumer Thread ID: " << my_id << endl;
	while (done == false) {
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker, [](){return buffer.size()>0;}); 
		int val = buffer.back();
		buffer.pop_back(); 
		cout << "Consumed: " << val << endl;
		//locker.unlock(); 
		//cond.notify_all();
		cond.notify_one();
	}
}

int main() {
	std::thread t1(producer, 100);
	std::thread t2(consumer);
	t1.join();
	t2.join();
	return 0;
}

/*
Output:
srb-go3@slave-node:~/dev_space/CPP_concurrency$ g++ -std=c++11 -pthread -g 17_producer_consumer.cpp 
srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
... <Sniped> ...
srb-go3@slave-node:~/dev_space/CPP_concurrency$
*/

//======================================<Code Block(E)>======================================


Ref:
https://www.youtube.com/watch?v=rKGq9AlfPR4&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=17



