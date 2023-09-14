#include <bits/stdc++.h>
using namespace std;

int n;	//���� ���� Ƚ��
pair<int, int> line[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> line[i].first >> line[i].second;
	}

	sort(line, line + n);

	int total = 0;
	int start = line[0].first;
	int end = line[0].second;

	for (int i = 1; i < n; i++) {
		int cur_s = line[i].first;
		int cur_e = line[i].second;

		if (end >= cur_s) { //�� ������ ���� ���������� ũ�ų� ����,
			if (end < cur_e)//�� ������ ���� �������� ������
				end = cur_e;//���� ������ �� �������� ��.
		}
		else {	//���� �� ���� ��, ���ο� ���� ����
			total += end - start;
			start = cur_s;	//���� �������� ���ο� ������(�� �������� �����)
			end = cur_e;	//���� ������ ���ο� ����(�� ������ �����)
		}
	}

	total += end - start;	//������ ���� ���� ���� ����
	cout << total << "\n";
}