#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> edge[2];
        edge[0] = vector<vector<int>>(n);
        edge[1] = vector<vector<int>>(n);
        for (auto& e : redEdges)edge[0][e[0]].push_back(e[1]);
        for (auto& e : blueEdges)edge[1][e[0]].push_back(e[1]);
        vector<vector<int>> dist(n, vector<int>(2, -1));
        dist[0][0] = 0, dist[0][1] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; i++) {
                int num = q.front(); q.pop();
                if (dist[num][0] != -1) {
                    for (int j = 0; j < edge[1][num].size(); j++) {
                        int tmp = edge[1][num][j];
                        if (dist[tmp][1] != -1)continue;
                        dist[tmp][1] = dist[num][0] + 1;
                        q.push(tmp);
                    }
                }
                if (dist[num][1] != -1) {
                    for (int j = 0; j < edge[0][num].size(); j++) {
                        int tmp = edge[0][num][j];
                        if (dist[tmp][0] != -1)continue;
                        dist[tmp][0] = dist[num][1] + 1;
                        q.push(tmp);
                    }
                }
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = min(dist[i][0], dist[i][1]);
        }
        return ans;
    }
};
int main() {
    Solution S;
    vector < vector<int >> a= {{1, 2}, { 2,3 }};
    vector < vector<int >> b = { {1, 4}, { 2,0 } };
    S.shortestAlternatingPaths(5,a,b);


	return 0;
}