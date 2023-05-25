#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdlib.h>
#include<tuple>
#include<vector>
#include<string.h>
//����dp�ε�
#define MAX 105
using namespace std;
int v, e, k;
int ans;
int indegree[MAX];
bool isbase[MAX];//�⺻��ǰ���� �ƴ��� üũ
int cnt[MAX];
int dp[MAX][MAX];
vector<pair<int,int>> adj[MAX];//�⺻��ǰ, ����
queue<int>q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	fill(isbase, isbase + MAX + 1, 1);
	for (int i = 1; i <= e; i++) {
		int v1, v2, cnt;
		cin >> v1 >> v2 >> cnt;
		adj[v1].push_back({ v2,cnt });
		isbase[v1] = 0;
		indegree[v2]++;
	}
	q.push(v);
	cnt[v] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			cnt[nxt.first] += nxt.second * cnt[cur];//nxt�� cur�� ����� �⺻��ǰ, nxt.second(�⺻��ǰ����)*�߰���ǰ�� ����
			indegree[nxt.first]--;
			if (indegree[nxt.first] == 0) q.push(nxt.first);
		}
	}
	for (int i = 1; i <= v; i++) {
		if (isbase[i])cout << i << " " << cnt[i] << "\n";
	}
}

