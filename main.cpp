#include <iostream>
#include <chrono>
#include "dijkstra.h"

#include "Candy.h"
#include "FindCelebrity.h"


using namespace std;


std::vector<std::vector<bool> > FindCelebrity::knowsMatrix;
std::vector<int> ratings;

template<typename Func, typename... Args>
double measureTime(Func &&func, Args &&... args) {
    auto start = chrono::high_resolution_clock::now();
    func(forward<Args>(args)...);
    // https://medium.com/cpluspluschronicles/a-developers-guide-to-std-forward-and-fold-expressions-in-c-2cf1fa8a53e0
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms = end - start;

    return ms.count();
}


void test1() {
    for (volatile int i = 0; i < 100000000; ++i);
}

template<typename Func, typename... Args>
void benchmark(const int loops, Func &&func, Args &&... args) {
    double total = 0;
    for (int i = 0; i < loops; i++) {
        total += measureTime(func, forward<Args>(args)...);
    }

    cout << endl;
    cout << "Loops: " << loops << endl;
    cout << "Total time: " << total << endl;
    cout << "Average loop time: " << total / loops << endl;
    cout << endl;
}

int main() {
    ratings = {1, 2, 3, 2, 1};
    benchmark(100, dijkstra);
    // benchmark(100, candy(ratings));

    cout << "Travelling salesman problem" << endl;
    map<string, int> shortestDistance = dijkstra();
    for (const auto &pair: shortestDistance) {
        cout << pair.first << " - " << pair.second << endl;
    }

    FindCelebrity::knowsMatrix = {
        {false, true, true},
        {false, false, true},
        {false, false, false}
    };
    cout << "Find Celebrity problem (2)" << endl;
    cout << FindCelebrity::findCelebrity(3) << endl;

    FindCelebrity::knowsMatrix = {
        {false, true, false},
        {false, false, false},
        {true, true, false}
    };
    cout << "Find Celebrity problem (1)" << endl;
    cout << FindCelebrity::findCelebrity(3) << endl;

    FindCelebrity::knowsMatrix = {
        {false}
    };
    cout << "Find Celebrity problem (0)" << endl;
    cout << FindCelebrity::findCelebrity(1) << endl;


    cout << "Candies problem" << endl;
    int candies = Candy::candy(ratings);
    cout << candies << endl;
    return 0;
}
