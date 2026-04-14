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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int cnt = 0;          // 记录已访问的房间数

        while (!q.empty()) {
            int a = q.front(); q.pop();
            cnt++;            // 每弹出一个房间，计数加1
            for (int key : rooms[a]) {   // 直接使用 rooms
                if (!vis[key]) {
                    vis[key] = true;
                    q.push(key);
                }
            }
        }
        return cnt == n;      // 所有房间都被访问过吗？
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
    vector<vector<int>> aa = { {1,3 }, { 3,0,1 }, { 2 }, {0} };
    cout<<S.canVisitAllRooms(aa);
	return 0;
}