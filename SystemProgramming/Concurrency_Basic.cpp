
//====================================================================================================
Go For Sleep:

std::this_thread::sleep_for(std::chrono::seconds(1));
std::this_thread::sleep_for(std::chrono::milliseconds(10));

//====================================================================================================
Get Thread ID:

std::thread::id this_id = std::this_thread::get_id();
std::cout << "thread " << this_id << "\n";

Code: https://github.com/goshreyas/CPP/blob/master/SystemProgramming/thread_id.cpp

Ref: https://en.cppreference.com/w/cpp/thread/get_id

Ref: https://www.bogotobogo.com/cplusplus/C11/1_C11_creating_thread.php

//====================================================================================================
How many threads:

cout << std::thread::hardware_concurrency();

Ref: https://www.bogotobogo.com/cplusplus/C11/1_C11_creating_thread.php

//====================================================================================================
Create Thread:







//====================================================================================================
Conditonal Variable:




//====================================================================================================




