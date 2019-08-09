#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

static int nums = 100;
mutex m;

//std::thread::id main_thread_id = std::this_thread::get_id();
void workThread(int tId)
{
    m.lock();
    cout <<"thread_ID:"<<std::this_thread::get_id()<<"\t"<< --nums << endl;
    m.unlock();
}
const int tdLen = 10;

void little_sleep(std::chrono::microseconds us)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start + us;
    do {
        std::this_thread::yield();
    } while (std::chrono::high_resolution_clock::now() < end);
}
int main()
{
    /*auto start = std::chrono::high_resolution_clock::now();
    little_sleep(std::chrono::microseconds(100));
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    cout << "waited for"
        << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
        << " microseconds\n";*/

    thread td[tdLen];
    for (int i = 0; i < tdLen; i++)
        td[i] = thread(workThread,i);
    for (auto& t : td)
    {
        cout << t.get_id() << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        //t.join();
        //t.detach();
        //t.get_id();
        //t.hardware_concurrency();
        //t.joinable();       //
        //t.native_handle();
        //t.swap(td[0]);
        //t.~thread();
    }
    volatile int a;
    getchar();
    return 0;
}