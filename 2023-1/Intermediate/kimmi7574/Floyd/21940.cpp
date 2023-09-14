#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int city[202];
int d[202][202];
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int u, v, t;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i != j)
				d[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> t;
		d[u][v] = t;
	}
	cin >> k;	//�� �ο�
	for (int i = 1; i <= k; i++) {
		cin >> city[i]; //������ ģ������ ��� ������ ��ȣ
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	int min_num = INF;
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		int dst = -1;
		for (int j = 1; j <= k; j++) {
			if (d[i][city[j]] != INF && d[city[j]][i] != INF)
				dst = max(d[i][city[j]] + d[city[j]][i], dst);
			//�� ģ������ �պ��ð��� �ִ� ���ϱ�
		}
		if (min_num > dst) { //�ִ�պ��ð��� �� �ּҰ� �Ǵ� ���� x����
			result.clear();
			result.push_back(i);
			min_num = dst;
		}
		else if (min_num == dst)
			result.push_back(i);
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}