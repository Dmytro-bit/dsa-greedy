#include <iostream>
#include <chrono>
#include "dijkstra.h"

using namespace std;


template<typename Func, typename... Args>
void measureTime(Func &&func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms = end - start;

    cout << "Time: " << ms.count() << " ms\n";
}


void test1() {
    for (volatile int i = 0; i < 100000000; ++i);
}

int main() {
    measureTime(dijkstra);
    return 0;
}
