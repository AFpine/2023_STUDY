#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdlib.h>
#include<tuple>
#include<array>
#include<vector>
#include<string.h>
#define X first
#define Y second
#define MAX 1000002
using namespace std;
int v, e;
int testcase;
vector<pair<int, int>>adj[MAX];//cost, v_2
priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
bool check[MAX];//�ּҽ��� Ʈ���� ���ԵǾ��°�?
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++){
		int cost;
		int v_1, v_2;
		cin >> v_1 >> v_2 >> cost;
		adj[v_1].push_back({ cost,v_2 });
		adj[v_2].push_back({ cost,v_1 });
	}
	int cnt = 0;
	int ans = 0;
	int max_cost = 0;
	check[1] = 1;
	for (auto next : adj[1]) pq.push({ next.X,1,next.Y });
	while (cnt < v - 1) {
		int cost;
		int v_1, v_2;
		tie(cost, v_1, v_2) = pq.top(); pq.pop();
		if (check[v_2])continue;
		ans += cost;
		check[v_2] = 1;
		cnt++;
		max_cost = max(max_cost, cost);
		for (auto next : adj[v_2]) {
			if (!check[next.Y])pq.push({ next.X,v_2,next.Y });
		}

	}
	cout << ans - max_cost;
		
	
}
