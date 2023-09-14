#include <bits/stdc++.h>
using namespace std;

int n, num, zero, one;
int max_sum = 0;
vector<int> pos;	//��� ����
vector<int> neg;	//���� ����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > 1)
			pos.push_back(num);
		else if (num < 0)
			neg.push_back(-num);
		else  if (num == 0)
			zero++;
		else
			one++;
	}

	if (pos.size() % 2 == 1)
		pos.push_back(1);
	if (neg.size() % 2 == 1) {
		if (zero == 0) neg.push_back(-1);
		else neg.push_back(0);
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	max_sum = one;

	//������� ���
	for (int i = 0; i < pos.size(); i += 2) {
		max_sum += pos[i] * pos[i + 1];
	}
	
	//�������� ���
	for (int i = 0; i < neg.size(); i += 2) {	//������ ������ ū ���� ���� ����
		max_sum += neg[i] * neg[i + 1];
	}

	cout << max_sum << "\n";
}