#include<iostream>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        int n = maze.size(), m = maze[0].size();
        q.push({ entrance[0],entrance[1] });
        int ret = -1;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[entrance[0]][entrance[1]] = 1;
            while (!q.empty()) {
                int t = q.size(); ret++;
                for (int i = 0; i < t; i++) {
                    auto [x, y] = q.front(); q.pop();
                    if (ret != 0 && (x == n - 1 || x == 0 || y == m - 1 || y == 0))return ret;
                    if (x + 1 < n && maze[x + 1][y] == '.' && !vis[x + 1][y]) { q.push({ x + 1,y }); vis[x + 1][y] = 1; }
                    if (x - 1 >= 0 && maze[x - 1][y] == '.' && !vis[x - 1][y]) { q.push({ x - 1,y }); vis[x - 1][y] = 1; }
                    if (y + 1 < m && maze[x][y + 1] == '.' && !vis[x][y + 1]) { q.push({ x,y + 1 }); vis[x][y + 1] = 1; }
                    if (y - 1 >= 0 && maze[x][y - 1] == '.' && !vis[x][y - 1]) { q.push({ x,y - 1 }); vis[x][y - 1] = 1; }
                }
            }
        return -1;
    }
};
int main() {
    Solution S;
    vector<vector<char>> a = { {'+','+','+'},{'.','.','.'},{'+','+','+'} }; vector<int> b = vector<int>({ 1,0 });
    S.nearestExit(a,b);
	return 0;
}