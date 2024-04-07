#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<queue>
#include<condition_variable>
#include<functional>
using namespace std;

class ThreadPool{

    ThreadPool(int numThreads) :stop(false) {
        for (int i =0; i<numThreads;i++){
            threads.emplace_back([this]{
                while(1){
                    unique_lock<mutex> lock(mtx);
                    condition.wait(lock, [this] {
                        return !tasks.empty() ||stop;
                         });

                    if(stop && tasks.empty()) {
                        return;
                    }

                    function<void()> task(move(tasks.front()));
                    tasks.pop();
                    lock.unlock();
                }
            });
        }
    }

    ~ThreadPool() {
        unique_lock<mutex> lock(mtx);
        stop =true;
        condition.notify_all();
        for(auto &t: threads) {
            t.join();
        }
    }

    template<class F, class... Args>
    void enqueue(F &&f,Args&&... args) {
        function<void()>task = bind(forward<F>(f),forward<Args>((args)...));
        {
        unique_lock<mutex> lock(mtx);
        tasks.emplace(move(task));
        }
        condition.notify_one();
    }
    private:
    vector<thread> threads;
    queue<function<void()>> tasks;
    mutex mtx;
    condition_variable condition;
    bool stop;
};