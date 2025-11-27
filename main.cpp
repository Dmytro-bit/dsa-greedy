#include <iostream>
#include <chrono>

#include "FindCelebrity.h"


using namespace std;


std::vector<std::vector<bool>> FindCelebrity::knowsMatrix;

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
    measureTime(test1);

    FindCelebrity::knowsMatrix = {
        {false, true, true},
        {false, false, true},
        {false, false, false}
    };
    cout << FindCelebrity::findCelebrity(3) << endl;

    FindCelebrity::knowsMatrix = {
        {false, true, false},
        {false, false, false},
        {true, true, false}
    };
    cout << FindCelebrity::findCelebrity(3) << endl;

    FindCelebrity::knowsMatrix = {
        {false}
    };
    cout << FindCelebrity::findCelebrity(1) << endl;
    return 0;
}
