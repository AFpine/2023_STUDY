#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//������ �����̶� ����ѵ�?
// �����ϴ� ���� <= ���� ������ ���� 
// ���� ������ ���� <= ������ ���� ������ ������ ���ŵ�
//�װ� �ƴ϶�� ���� ������ ������ ���� ���� ����
//���� "��"���̸� ��� ����
using namespace std;
int N;
pair<int, int>cm[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cm[i].first >> cm[i].second;
	}
	sort(cm, cm + N);
	int ans = 0;
	int left, right;
	left = cm[0].first;
	right = cm[0].second;
	for (int i = 1; i < N; i++) {
		int for_left, for_right;
		for_left = cm[i].first;
		for_right = cm[i].second;
		if (cm[i].first <= right && right <= cm[i].second) {
			right = cm[i].second;
		}
		else if (cm[i].first > right) {
			ans += right - left;
			left = cm[i].first;
			right = cm[i].second;
		}
	}
	cout << ans + right - left;
	return 0;
}
