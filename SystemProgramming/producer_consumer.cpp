
#include <bits/stdc++.h>
using namespace std;


mutex mtx;
condition_variable cv;

int loop = 4;
queue<int> msgQ;

int turn = 1;

void producer() {
    while(loop) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{return (turn==1);});
        printf("\nIn producer:\n");
        for(int i=0; i<3; i++) {
            msgQ.push(rand());
        }
        turn = 2; // For Consumer
        loop--;
        cv.notify_one();
    }
    return;
}

void consumer() {
    while(loop) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{return (turn==2);});
        printf("\nIn consumer:\n");
        while(msgQ.size() > 0) {
            int msg = msgQ.front();
            printf("%d, ", msg);
            msgQ.pop();
        }
        turn = 1; // For Producer
        loop--;
        cv.notify_one();
    }
    return;
}


int main()
{
    printf("Hello producer:consumer:\n\n");
    thread tProducer(producer), tConsumer(consumer);
    
    tProducer.join();
    tConsumer.join();

    return 0;
}



