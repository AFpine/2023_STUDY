#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[20005];
int v, e,e_n_d;
int di(int st, int en)/*�������� ������ ���س��� ���ͽ�Ʈ�� ������*/ {
	int d[1005];
	fill(d, d + v + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	d[st] = 0;
	pq.push({ d[st],st });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second]) { // cur ������ ���� �������� �� �ѷ��� 
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second });
		}
	}
	return d[en];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> e_n_d;/*���� ����*/

	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	int mx = 0;
	for (int i = 1; i <= v; i++) {
		mx = max(mx, di(i,e_n_d)/*��������� ����*/+di(e_n_d,i)/*�������� �����*/);
	}
	cout << mx;
}
