//
// Created by vladikslon on 11/27/25.
//

#ifndef DSA_GREEDY_FIND_CELEBRITY_H
#define DSA_GREEDY_FIND_CELEBRITY_H

#include <vector>
using namespace std;
    class FindCelebrity {
    public:
        static std::vector<std::vector<bool>> knowsMatrix;

        static bool knows(int a, int b) {
            return knowsMatrix[a][b];
        }

        static int findCelebrity(int n) {
            int candidate = 0;
            for (int i = 1; i < n; i++) {
                if (knows(candidate, i)) candidate = i;
            }
            for (int i = 0; i < n; i++) {
                if (i == candidate) continue;
                if (knows(candidate, i) || !knows(i, candidate)) {
                    return -1;
                }
            }
            return candidate;
        }
    };






#endif //DSA_GREEDY_FIND_CELEBRITY_H