#include <bits/stdc++.h>
using namespace std;

int n, m, x, result;
int dst[1002];	//���������� �ִܰŸ� ���
vector<pair<int, int>> v[1002];

void func(int a, int d) {
	memset(dst, 98765432, sizeof(dst));	//�ʱⰪ ���Ѵ� ����
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	//�켱���� ť(�ּ� �Ÿ��� ��Ʈ��)
	pq.push({ 0, a }); //�Ÿ�, ����
	dst[a] = 0;
	
	while (!pq.empty()) {
		int cur_x = pq.top().second;	//���� ����
		int cur_dst = pq.top().first;	//���� �������� �Ÿ�
		pq.pop();
		
		if (cur_x == d) {	//���� ������ �����ߴٸ�
			result = dst[cur_x];	//�ִ� �Ÿ� ���
			break;
		}

		for (int i = 0; i < v[cur_x].size(); i++) {
			//���� ������ �̾��� ���� ������
			int next_x = v[cur_x][i].first;	//���� ����
			int next_dst = v[cur_x][i].second + cur_dst;  //���� �������� �Ÿ� ���
			if (dst[next_x] > next_dst) {
				//���� �������� �Ÿ��� ��ϵ� �������� �Ÿ��� ����
				dst[next_x] = next_dst;	//�ִܰŸ���� ���
				pq.push({ next_dst, next_x });	//ť�� ����
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ansA, ansB, totalAns = 0;
	int st, en, t;

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> st >> en >> t;
		v[st].push_back({ en, t });
	}
	for (int i = 1; i <= n; i++) {
		func(i, x);	//���� �� �ִ� �Ÿ�
		ansA = result;
		func(x, i);	//���� �� �ִ� �Ÿ�
		ansB = result;
		if (totalAns < ansA + ansB)
			totalAns = ansA + ansB;	//��
	}

	cout << totalAns << "\n";
	return 0;
}