#include <bits/stdc++.h>
using namespace std;

int T;	//�׽�Ʈ���̽� ��
int n;	//���� ��
int arr[1000005];	//�� �� �ְ���Ÿ���� �迭

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		
		int arr[1000005] = { 0, };	//�� �� �ְ���Ÿ���� �迭
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int max_val = -1;
		long long result = 0;
		for (int i = n - 1; i >= 0; i--) {	//�������� �˻��Ͽ� �ִ� ���� & ���̸�ŭ ���־� result�� ����
			max_val = max(max_val, arr[i]);
			result += max_val - arr[i];
		}

		cout << result << "\n";
	}
}