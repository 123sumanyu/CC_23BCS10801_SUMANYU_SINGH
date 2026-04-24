#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        
      
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

     
        vector<int> dist1(n + 1, INT_MAX);
        vector<int> dist2(n + 1, INT_MAX);

        queue<pair<int,int>> q;
        q.push({1, 0});
        dist1[1] = 0;

        while (!q.empty()) {
            auto [node, currTime] = q.front();
            q.pop();

            for (auto &nei : graph[node]) {
                int t = currTime;

               
                if ((t / change) % 2 == 1) {
                    t += (change - (t % change));
                }

              
                t += time;

              
                if (t < dist1[nei]) {
                    dist2[nei] = dist1[nei];
                    dist1[nei] = t;
                    q.push({nei, t});
                }
                else if (t > dist1[nei] && t < dist2[nei]) {
                    dist2[nei] = t;
                    q.push({nei, t});
                }
            }
        }

        return dist2[n];
    }
};