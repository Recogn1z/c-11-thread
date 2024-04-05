#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
using namespace std;

queue<int>q;
mutex mtx;
condition_variable g_cv;
void producer() {
    for(int i =0;i<10;i++){{
        unique_lock<mutex> lock(mtx);
        q.push(i);
        g_cv.notify_one();
        cout << "task: "<< i <<endl;
    }
    this_thread::sleep_for(chrono::microseconds(100));
    }
}

void consumer() {
    while(1){
        unique_lock<mutex> lock(mtx);
        g_cv.wait(lock,[](){return !q.empty();});
        int value = q.front();
        q.pop();
        cout << "finish: " << value <<endl;
    }
}

int main() {
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}