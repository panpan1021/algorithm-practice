#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> graph(n);
        for (auto& conn : connections) {
            int a = conn[0], b = conn[1];
            graph[a].emplace_back(b, true);  // 原始方向 a -> b
            graph[b].emplace_back(a, false); // 反向，表示 b -> a 不是原始方向
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int ans = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& [v, isOriginal] : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    if (isOriginal) ans++; // 需要反转
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution S;
    vector < vector<int >> a= {{1, 2}, { 2,3 }};
    vector < vector<int >> b = { {1, 4}, { 2,0 } };
    S.


	return 0;
}