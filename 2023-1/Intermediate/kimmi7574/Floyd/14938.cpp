#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000 // 10��

int n, m, r; //n:��������, m:��������, r:���� ����
int max_num = 0, cnt = 0;
int d[102][102];
int item[102];

void func() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cnt = item[i];
		for (int j = 1; j <= n; j++) {
			if (i != j && d[i][j] <= m)
				cnt += item[j];
		}
		max_num = max(max_num, cnt);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r;
	int a, b, l; //t: �� ������ ������ ��, a,b:������ ��ȣ, l: ���� ����
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				d[i][j] = INF;
		}
	}
	
	for (int i = 1; i <= n; i++) 
		cin >> item[i];

	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		d[a][b] = l;
		d[b][a] = l;
	}

	func();

	cout << max_num;

	return 0;
}