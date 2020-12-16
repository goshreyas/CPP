



//======================================<Code Block(S)>======================================


#include<bits/stdc++.h>
using namespace std;


// 1. Function Pointer
// This is the very basic form of thread creation.

#if 0
// Working
void fun(int x) {
	while(x-- > 0)
		cout << x << endl;
}

int main() {
	std::thread t1 = thread(fun, 5);
	if(t1.joinable())
		t1.join();
	return 0;
}
#endif


#if 1
// Working
void fun(int &x) {   // NOTE The use of &
	while(x-- > 0)
		cout << x << endl;
}

int main() {
	int n = 5;
	std::thread t1 = thread(fun, ref(n));  // NOTE: The use of ref()
	if(t1.joinable())
		t1.join();
	return 0;
}
#endif


/*
Testing:
srb-go3@slave-node:~/dev_space/CPP_concurrency$ g++ -std=c++11 -pthread -g 2_different_type_create_thread.cpp 
srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
4
3
2
1
0
srb-go3@slave-node:~/dev_space/CPP_concurrency$ 

*/


//======================================<Code Block(E)>======================================





