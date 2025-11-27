//
// Created by vladikslon on 11/27/25.
//

#ifndef DSA_GREEDY_CANDY_H
#define DSA_GREEDY_CANDY_H
#include <vector>
using namespace std;
class Candy {
public:
    static int candy(const vector<int>& ratings) {
        const int n = ratings.size();
        int res = n;

        int i = 1;
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int inc = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                inc++;
                res += inc;
                i++;
            }

            int dec = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                dec++;
                res += dec;
                i++;
            }

            res -= min(inc, dec);
        }

        return res;
    }
};
#endif //DSA_GREEDY_CANDY_H