# Code and guidelines

---

This project uses three main components:

- Candy.h implements the two-pass greedy solution for distributing candies.
- FindCelebrity.h implements the elimination method to find a celebrity.
- dijkstra.h implements Dijkstra’s algorithm for shortest paths as a benchmark.

Example usage:

```c++
#include "Candy.h"
#include "FindCelebrity.h"

// Candy example
vector<int> ratings = {1, 2, 3, 2, 1};
int totalCandies = Candy::candy(ratings);
cout << totalCandies << endl; // prints 9

// Celebrity example
FindCelebrity::knowsMatrix = {
    {false, true, true},
    {false, false, true},
    {false, false, false}
};
int celeb = FindCelebrity::findCelebrity(3);
cout << celeb << endl; // prints 2
```

### General

- Time measurement function

```c++
template<typename Func, typename... Args>
double measureTime(Func &&func, Args &&... args) {
    auto start = chrono::high_resolution_clock::now();
    func(forward<Args>(args)...);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms = end - start;

    return ms.count();
}
```

- Benchmark

```c++
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
```

### 1. Dijkstra's algorithm and travelling salesman problem

- main loop

```c++
// ========================== Dijkstra's algorithm ==========================
    while (!pq.empty()) {
        DistanceTo smallest = pq.top(); // get city from a queue
        pq.pop();
        string target = smallest.getTarget(); // get target city

        if (shortestDistance.find(target) == shortestDistance.end()) { 
            int d = smallest.getDistance();
            shortestDistance[target] = d;
            auto neighbours = directRoutes.find(target);

            if (neighbours != directRoutes.end()) {
                for (const DistanceTo &dt: neighbours->second) {
                    string c = dt.getTarget();
                    if (shortestDistance.find(c) == shortestDistance.end()) {
                        pq.push(DistanceTo(c, d + dt.getDistance()));
                    }
                }
            }
        }
    }
```

