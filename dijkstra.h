//
// Created by dmytro on 11/27/25.
//

#ifndef DSA_GREEDY_DIJKSTRA_H
#define DSA_GREEDY_DIJKSTRA_H

// Source: https://github.com/Dmytro-bit/oop-CA2-Collections/blob/main/src/Question11.java

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

class DistanceTo {
public:
    string target;
    int distance;

    DistanceTo(string target, int distance) : target(target), distance(distance) {
    }

    bool operator<(const DistanceTo &other) const {
        return distance < other.distance;
    }

    string getTarget() const { return target; }
    int getDistance() const { return distance; }
};

map<string, int> dijkstra() {
    string city1, city2, from = "";
    int distance;
    int counter = 0;
    ifstream file("citiesQ11.txt");
    map<string, set<DistanceTo> > directRoutes;

    // ========================== Reading input file ==========================
    while (file >> city1 >> city2 >> distance) {
        DistanceTo distanceTo1(city1, distance);
        DistanceTo distanceTo2(city2, distance);

        if (counter < 1) {
            from = city1;
            counter++;
        }

        directRoutes[city1].insert(distanceTo2);
        directRoutes[city2].insert(distanceTo1);
    }

    DistanceTo distance0(from, 0);
    priority_queue<DistanceTo> pq;
    map<string, int> shortestDistance;

    pq.push(distance0);

    // ========================== Dijkstra's algorithm ==========================
    while (!pq.empty()) {
        DistanceTo smallest = pq.top();
        pq.pop();
        string target = smallest.getTarget();

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

    return shortestDistance;
}


#endif //DSA_GREEDY_DIJKSTRA_H
