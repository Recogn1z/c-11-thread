#include<iostream>
#include<thread>
#include<mutex>
using namespace std;


int a  =0;
mutex m1, m2;
void func1(){
    for(int i=0;i<100;i++) {
        m1.lock();
        m2.lock();
        m1.unlock();
        m2.unlock();
    }
}

void func2(){
    for(int i=0;i<100;i++) {
        m2.lock();
        m1.lock();
        m2.unlock();
        m1.unlock();
    }
}


int main (){
    thread t1(func1);
    thread t2(func2);
    t1.join();
    t2.join();
    cout << "over";
    return 0;
}