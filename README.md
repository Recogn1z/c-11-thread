## 2024/3/27 how to create a thread in c++

### include<thread>

### create the thread `thread thread1(func);`

### `.join()` can wait thread to finish the process, that means it can make main thread blocked until finish the process

### `.detach()` the main thread can end with the additional threads run in the background

### `.joinable()` to judge if this thread can use detach or join

## 2024/3/28

### ref(a) and &ref = a: ref() is a template that need to pass a reference to a function or a context that requires copyable objects but you want to avoid copying the actual object. &ref use a pointer to use the reference.

## 2024/3/31

### If multiple threads access a memory at the same time and at least one thread overwrites the variable, a data race problem will occur.

### `mutex` to resolve the problem mentioned above, `mutex mtx` to create, and use `mtx.lock()` to lock it which means after locked, another threads cannot acess to this memeory until `mtx.unlock()`
