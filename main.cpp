#include <iostream>
#include <chrono>
#include "dijkstra.h"

#include "Candy.h"
#include "FindCelebrity.h"


using namespace std;


std::vector<std::vector<bool> > FindCelebrity::knowsMatrix;
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

void testCelebrity() {
    FindCelebrity::knowsMatrix = {
        {false, true, true},
        {false, false, true},
        {false, false, false}
    };
    cout << "3 people : " << FindCelebrity::findCelebrity(3) << endl;
    measureTime([]() { FindCelebrity::findCelebrity(3); });

    FindCelebrity::knowsMatrix  = {
            {false, true,  true,  false},
            {false, false, false, false},
            {false, true,  false, false},
            {true,  true,  false, false}
    };
    cout <<  "4 person : " <<FindCelebrity::findCelebrity(4) << endl;
    measureTime([]() { FindCelebrity::findCelebrity(4); });


}

int main() {
    measureTime(dijkstra);
    cout << "Celebrity benchmark:" << endl;
    testCelebrity();
    cout << "Candy benchmark:" << endl;
    ratings = {1, 2, 3, 2, 1};
    int candies = Candy::candy(ratings);
    measureTime([](){(void)Candy::candy(ratings);} );
    cout << candies << endl;
    return 0;
}
