#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int N, M, K;
int D[201][201];
int nxt[201][201];
int friendlivingcity[205];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		fill(D[i], D[i] + 1 + N, INF);
		D[i][i] = 0;
	}
	while (M--) {
		int a, b, T;
		cin >> a >> b >> T;
		D[a][b] = T;
		nxt[a][b] = b;
	}
	cin >> K;
	for (int i = 1; i <= K; i++) {
		cin >> friendlivingcity[i];
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				}
			}
		}
	}
	
	vector<pair<int, int>> ans;
	for (int i = 1; i <= N; i++) {
		int mx = 0;
		for (int j = 1; j <= K; j++) {
			mx = max(mx, D[i][friendlivingcity[j]] + D[friendlivingcity[j]][i]);
		}//i�� �� ���, �� �� �պ��ð��� �ִ��� ���� �̾Ƴ�
		ans.push_back({ mx, i });
	}
	sort(ans.begin(), ans.end()); // �ִ� �� �ּҸ� ��
	int mn = ans[0].first;
		for (auto cur : ans) {
			if (mn < cur.first) break;
			cout << cur.second << " ";
	}
}
