#include <iostream>
#include <thread>
#include<mutex>


int shared_data = 0;
std::mutex mtx;

void fun() {
    for (int i =0; i<10000;i++){
        std::lock_guard<std::mutex>lg(mtx);
        //std::unique_lock<std::mutex>lg(mtx);
        shared_data++;
    }
}


int main() {
    std::thread t1(fun);
    std::thread t2(fun);
    t1.join();
    t2.join();
    std::cout << shared_data <<std::endl;
    return 0;
}