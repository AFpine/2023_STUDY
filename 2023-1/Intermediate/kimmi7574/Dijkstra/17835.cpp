#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<long long, int>> vec[100002];
long long dst[100002];

priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
	greater<pair<long long, int>>> pq;

void func() {
	while (!pq.empty()) {
		int u, v;
		long long w, dw;
		tie(w, u) = pq.top();
		pq.pop();

		if (dst[u] != w)
			continue;
		for (auto next : vec[u]) {
			tie(dw, v) = next;
			dw += w;
			if (dw >= dst[v])
				continue;
			dst[v] = dw;
			pq.push({ dw, v });
		}
	}
}
/*������ ��� ������ ����
  ������Ҹ� �������� �Ÿ��� 0���� ����, ť�� ���ͽ�Ʈ���̿�
  �ĺ�ã��*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int u, v;
	long long c;

	cin >> n >> m >> k;
	fill(dst + 1, dst + n + 1, 1e18);

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		vec[v].push_back({ c, u });	//u,v �Ųٷ� ����(�Ÿ�, ����)
	}

	for (int i = 0; i < k; i++) {	//�������� ��ġ�� ������ ��ȣ
		cin >> u;
		dst[u] = 0;
		pq.push({ dst[u], u });
	}

	func();

	int max_idx = max_element(dst + 1, dst + n + 1) - dst;
	cout << max_idx << "\n" << dst[max_idx];
	return 0;
}