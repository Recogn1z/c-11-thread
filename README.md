## 2024/3/27 how to create a thread in c++

### include<thread>

### create the thread `thread thread1(func);`

### `.join()` can wait thread to finish the process, that means it can make main thread blocked until finish the process

### `.detach()` the main thread can end with the additional threads run in the background

### `.joinable()` to judge if this thread can use detach or join
