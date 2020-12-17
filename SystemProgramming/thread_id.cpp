


//======================================<Code Block(S)>======================================
#include<bits/stdc++.h>
using namespace std;

void thread_function(string s)
{
    std::cout << "thread function\n";
}


int main()
{
    std::string s = "Shreyas B ";
    //std::thread t(&thread_function, std::move(s));  // Working, Note the use of move()
    //std::thread t(&thread_function, s);  // Working. Note the use of &
    std::thread t(thread_function, s);
    std::cout << "main thread message = " << s << std::endl;

    std::cout << "main thread id = " << std::this_thread::get_id() << std::endl;
    std::cout << "child thread id = " << t.get_id() << std::endl;

    t.join();
    return 0;
}
//======================================<Code Block(E)>======================================




