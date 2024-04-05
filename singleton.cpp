#include<iostream>
#include<string>
using namespace std;


class Log{
    public:
    Log(const Log& log) = delete;
    Log& operator=(const Log& log) = delete;
    static Log& getInstance() {
        static Log log;  //eger singleton
        return log;
        //static Log * log = nullptr // lazy singeton
        // if(!log) { log = new Log()}
    }
    void printLog(string msg) {
        cout << msg <<endl;
    }

    private:
    Log() {};
};

int main() {
    Log::getInstance().printLog("not good");
}