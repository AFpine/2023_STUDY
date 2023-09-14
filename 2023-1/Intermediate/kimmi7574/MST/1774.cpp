#include <bits/stdc++.h>
using namespace std;

pair<int, int> loc;
vector<tuple<long long, int, int>> dist;
int parent[1001];

int find(int x) {
	if (parent[x] == x) return x;
	else
		return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	else {
		parent[x] = y;
		return true;
	}
}

long long dist_cal(int x1, int y1, int x2, int y2) {
	long long x_dist = pow(x1 - x2, 2);
	long long y_dist = pow(y1 - y2, 2);
	return (long long)sqrt(x_dist + y_dist);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, x, y, u, v;
	double result = 0.0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {	//���ֽŵ��� ��ǥ
		cin >> x >> y;
		loc.push_back({ x, y });
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {	//�̹� ����� ���
		cin >> u >> v;
		if (merge(u, v))
			cnt++;
	}

	//i�� ���ֽŰ� j�� ���ֽ� ������ �Ÿ� ���
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			long long r = dist_cal(loc[i].first, loc[i].second, loc[j].first, loc[j].second);
			dist.push_back({ r, i, j });	//���(�Ÿ�), �����, ������
		}
	}

	sort(dist.begin(), dist.end());

	for (int i = 0; i < dist.size(); i++) {
		if (!merge(get<1>(dist[i]), get<2>(dist[i])))
			continue;

		result += sqrt(get<0>(dist[i]));
		cnt++;
		if (cnt == n - 1)
			break;
	}

	cout << fixed;
	cout.precision(2);
	cout << result << "\n";
	return 0;
}