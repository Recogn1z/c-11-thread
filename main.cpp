#include<iostream>
#include<thread>
#include<string>
using namespace std;

void printHelloWorld(){
    for(int i=0;i<10000;i++) {
        cout << i << " ";
    }
}


int main (){
    thread thread1(printHelloWorld);
    bool jo = thread1.joinable();
    if (jo==1){
        thread1.join();
    } 
    cout << "over";
    return 0;
}