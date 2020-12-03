
TOPIC: Timed Mutex In C++ Threading (std::timed_mutex)
We have learned Mutex, Race Condition, Critical Section in previous videos.

NOTES:
0. std::timed_mutex is blocked till timeout_time or the lock is aquired and returns true if success 
   otherwise false.
1. Member Function:
   a. lock 
   b. try_lock
   c. try_lock_for    ---\ These two functions makes it different from mutex.
   d. try_lock_until  ---/ 
   e. unlock

EXAMPLE: try_lock_for();
Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
On successful lock acquisition returns true, otherwise returns false.

//======================================<Code Block(S)>======================================

// timed_mutex::try_lock_for example
#include <iostream>       // std::cout
#include <chrono>         // std::chrono::milliseconds
#include <thread>         // std::thread
#include <mutex>          // std::timed_mutex

std::timed_mutex mtx;

void fireworks () {
	// waiting to get a lock: each thread prints "-" every 200ms:
	while (!mtx.try_lock_for(std::chrono::milliseconds(200))) {
		std::cout << "-";
	}
	// got a lock! - wait for 1s, then this thread prints "*"
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "*\n";
	mtx.unlock();
}

int main ()
{
	std::thread threads[10];
	// spawn 10 threads:
	for (int i=0; i<10; ++i)
		threads[i] = std::thread(fireworks);

	for (auto& th : threads) th.join();

	return 0;
}

/*
Output:

srb-go3@slave-node:~/dev_space/CPP_concurrency$ g++ -std=c++11 -pthread -g 7_try_lock_for.cpp 
srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
------------------------------------*
----------------------------------------*
-----------------------------------*
------------------------------*
-------------------------*
--------------------*
---------------*
----------*
-----*
*
srb-go3@slave-node:~/dev_space/CPP_concurrency$

*/


//======================================<Code Block(E)>======================================


http://www.cplusplus.com/reference/mutex/timed_mutex/try_lock_for/
http://www.cplusplus.com/reference/mutex/timed_mutex/try_lock_until/

https://www.youtube.com/watch?v=x0sHzDyETUc&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=7

