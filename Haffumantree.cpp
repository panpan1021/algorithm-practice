#include"tot.h"
using namespace std;
struct Haffumannode {
	char _data;
	int _weight;
	Haffumannode* _left;
	Haffumannode* _right;
	Haffumannode(char data=0,int weight=0,Haffumannode* left=nullptr,Haffumannode* right=nullptr):
		_data(data)
		,_weight(weight)
		,_left(left)
		,_right(right)
	{ }
};
class compare {
public:
	bool operator()(Haffumannode* a, Haffumannode* b) {
		return a->_weight > b->_weight;
	}
};
Haffumannode* buildhaffumantree(const vector<char>& data, const vector<int>& weight) {
	priority_queue<Haffumannode*, vector<Haffumannode*>, compare> pq;
	for (int i = 0; i < data.size(); i++) {
		pq.push(new Haffumannode(data[i], weight[i]));
	}
	while (pq.size() > 1) {
		auto left = pq.top();
		pq.pop();
		auto right = pq.top();
		pq.pop();
		auto tmp = new Haffumannode('#', left->_weight + right->_weight,left,right);
		pq.push(tmp);
	}
	return pq.top();
}
void generatehaffumancodes(Haffumannode* root,vector<pair<char,string>>& ans,string codes) {
	if (!root)return;
	if (root->_data != '#')ans.push_back({ root->_data,codes });
	generatehaffumancodes(root->_left, ans, codes + '0');
	generatehaffumancodes(root->_right, ans, codes + '1');
}