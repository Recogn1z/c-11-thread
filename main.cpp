#include<iostream>
#include<thread>
using namespace std;

void printHelloWorld(){
    cout << "Hello world" <<endl;
}


int main (){
    thread thread1(printHelloWorld);
    return 0;
}