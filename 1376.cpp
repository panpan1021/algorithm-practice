#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> children(n);
        for (int i = 0; i < manager.size(); i++) {
            int a = manager[i];
            children[a] .push_back( i);
        }
        function<int(int)> dfs = [&](int node)->int {
            int maxtime = 0;
            for (int i = 0; i < children[node].size(); i++) {
                maxtime = max(dfs(children[node][i]) + informTime[node], maxtime);
            }
            return maxtime;
            };
        return dfs(headID);
    }
};
int main() {
    Solution S;
    vector < vector<int >> a= {{1, 2}, { 2,3 }};
    vector < vector<int >> b = { {1, 4}, { 2,0 } };
    S.


	return 0;
}