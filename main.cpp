#include <iostream>
#include <chrono>
#include "dijkstra.h"

#include "Candy.h"
#include "FindCelebrity.h"


using namespace std;


std::vector<std::vector<bool>> FindCelebrity::knowsMatrix;
std::vector<int> ratings;

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
    ratings = {1,2,3,2,1};
    int candies = Candy::candy(ratings);
    cout <<candies << endl;
    return 0;
}
