


//======================================<Code Block(S1)>======================================

#include <bits/stdc++.h>
using namespace std;

void run(int count) {
	cout<< "\nMy ID: " << this_thread::get_id() << endl;
	cout<< "\nGoing to Sleep for :" << count << " seconds";
	this_thread::sleep_for(chrono::seconds(count));
	cout<< "\nAfter Sleeping for :" << count << " seconds";
}


int main() {
	thread t1(run, 20);
	cout << "main()" << endl;
	t1.detach();
	//t1.detach();       // NOTE: Don't call detach() multiple times, use joinable() as precautionary measures
	if(t1.joinable())    // NOTE: joinable() before detach()
		t1.detach();
	if(t1.joinable())
		t1.join();
	cout << "main() after" << endl;
	return 0;
}

/*
Output:
srb-go3@slave-node:~/dev_space/CPP_concurrency$ g++ -std=c++11 -pthread -g 3_thread_detach.cpp 
srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
main()
My ID: 140405963212544

Going to Sleep for :10 seconds
main() after
srb-go3@slave-node:~/dev_space/CPP_concurrency$
*/


//======================================<Code Block(E1)>======================================




//======================================<Code Block(S2)>======================================

#include <bits/stdc++.h>
using namespace std;

void run(int count) {
	cout<< "\nMy ID: " << this_thread::get_id() << endl;
	cout<< "\nGoing to Sleep for :" << count << " seconds";
	this_thread::sleep_for(chrono::seconds(count));
	cout<< "\nAfter Sleeping for :" << count << " seconds";
}


int main() {
	thread t1(run, 20);
	cout << "main()" << endl;
	t1.detach();
	//t1.detach(); // Don't call detach() multiple times
	if(t1.joinable())
		t1.detach();
	if(t1.joinable())
		t1.join();
	cout << "main() after" << endl;
	return 0;
}


/*
srb-go3@slave-node:~/dev_space/CPP_concurrency$ g++ -std=c++11 -pthread -g 3_thread_detach.cpp 
./srb-go3@slave-node:~/dev_space/CPP_concurrency$ ./a.out 
main() Before
My ID: 140518696122112
Going to Sleep for 2 seconds
After Sleeping for 2 seconds
main() after
srb-go3@slave-node:~/dev_space/CPP_concurrency$ 
*/

//======================================<Code Block(E2)>======================================




