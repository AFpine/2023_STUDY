#include <bits/stdc++.h>
using namespace std;

int n;
int start_month, start_day, end_month, end_day;
int tmpEnd = 0, idx = 0, num = 0;
bool flag, resFlg = true;
int end_ = 301;
pair<int, int> flower[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> start_month >> start_day >> end_month >> end_day;
		flower[i].first = start_month * 100 + start_day;
		flower[i].second = end_month * 100 + end_day;
	}

	sort(flower + 1, flower + n + 1);

	while (end_ < 1131 && idx <= n) {
		flag = false;
		idx++;
		for (int i = idx; i <= n; ++i) {
			if (flower[i].first > end_)
				break;
			if (tmpEnd < flower[i].second) {
				flag = true;
				tmpEnd = flower[i].second;
				idx = i;
			}
		}
		//���� �Ǿ��ִ� ���� ���� ������ ���� �Ǵ� �� ��, ���� ���� ���� ���� �� ����

		if (flag) {
			end_ = tmpEnd;
			num++;
		}
		else {
			resFlg = false;	//�߰��� ���� ���� �ϼ� ���� or 11/30���� �Ǿ����� �ʾƼ� false
			break;
		}
	}

	if (!resFlg)
		cout << "0";
	else
		cout << num;
}