# Code

This project uses three main components:

- Candy.h implements the two-pass greedy solution for distributing candies.
- FindCelebrity.h implements the elimination method to find a celebrity.
- dijkstra.h implements Dijkstra’s algorithm for shortest paths as a benchmark.

Example usage:

```cpp
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