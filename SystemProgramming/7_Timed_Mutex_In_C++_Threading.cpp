
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



//======================================<Code Block(E)>======================================



https://www.youtube.com/watch?v=x0sHzDyETUc&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=7

