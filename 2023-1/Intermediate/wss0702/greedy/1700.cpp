#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
//���� �ȵ�
//��ġ�� ���ڸ� �ִ��� ���� �ʰ�
//��ġ�� �ʴ� ���ڵ��� ���� �������ؾ���.
//flag�� �ִ� ���� �� ��ġ�� �� �� ���� ���� pop��Ű�� ���ο� ���ڸ� �ɴ´�.

using namespace std;
int N, K;
int arr[105];
int use[102];//�ܼ�Ʈ
int ans;
vector<int> flag;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	if (N >= K) {
		cout << 0;
		return 0;
	}
	int arr_index = 0;
	int c_index = 0;
	while (c_index < N) {
		if (find(use, use + N, arr[arr_index]) == use + N/*�ߺ� üũ*/) {
			use[c_index] = arr[arr_index];
			c_index++;
		}
		arr_index++;
	}
	//�����ǿ� ������ ��� ��⸦ ����
	for (int i = N; i < K; i++) {
		int cur = arr[i];//����� ��ǰ
		if (find(use, use + N, cur) == use + N) {
			pair<int, int> e = {INT_MIN, INT_MIN};

			for (int j = 0; j < N; j++) {
				pair<int, int> c;
				int pos = find(arr + i, arr + K, use[j]) - arr;

				if (pos == K) c = { INT_MAX, j };
				else c = { pos, j };

				if (c.first > e.first) e = c;
			}
			use[e.second] = cur;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
