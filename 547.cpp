#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include <utility>
#include<list>
#include<map>
#include<unordered_map>
#include<string>
using namespace std;
struct compare {
	bool operator()(int a, int b) {
		return a < b;
	}
};
class Solution {
public:
    vector<int> myrank, parent;
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unit(int x, int y) {
        if (myrank[x] > myrank[y])
            parent[y] = x;
        else if (myrank[y] > myrank[x])
            parent[x] = y;
        else {
            parent[x] = y;
            myrank[y]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n + 1);
        parent.assign(n + 1, 0);
        myrank.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int flag = isConnected[i][j];
                if (flag) {
                    int pa_x = find(i + 1), pa_y = find(j + 1);
                    if (pa_x != pa_y)
                        unit(pa_x, pa_y);
                }
            }
        }
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[parent[i]])
                vis[parent[i]] = 1;
        }
        for (auto e : vis)
            if (e)
                ret++;
        return ret;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
	Solution S;
	vector<int> a({ 1,2 }), b({ 3,4 });
    vector<vector<int>> aa = { {1,0,0,1 }, { 0,1,1,0 }, { 0,1,1,1 }, { 1,0,1,1 } };
    S.findCircleNum(aa);
	return 0;
}