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
    typedef pair<int, int> pii;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n);
        vector<vector<int>> edge(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int tmp = graph[i][j];
                edge[tmp].push_back(i);
                outdegree[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) { q.push(i); ans.push_back(i); }
        }
        while (!q.empty()) {
            int a = q.front(); q.pop();
            for (int i = 0; i < edge[a].size(); i++) {
                outdegree[edge[a][i]]--;
                if (outdegree[edge[a][i]] == 0) { q.push_back(edge[a][i]); ans.push_back(edge[a][i]); }
            }
        }
        sort(ans.begin(), ans.end());
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