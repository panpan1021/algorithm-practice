#include"tot.h"
using namespace std;
int inf = 0x3f3f3f3f;
int n = 10;
void djstra(vector<vector<pair<int, int>>>& eg,int begin,int end) {
	vector<int> dist(n, inf);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, begin });
	dist[begin] = 0;
	while (!pq.empty()) {
		auto [distance, num] = pq.top();
		pq.pop();
		if (dist[num] < distance)continue;
		auto tmp = eg[num];
		for (int i = 0; i < tmp.size(); i++) {
			auto [nextnum, weight] = tmp[i];
			if (distance + weight < dist[nextnum]) {
				dist[nextnum] = distance + weight;
				pq.push({ dist[nextnum],nextnum });
			}
		}
	}
}
