#include <bits/stdc++.h>
using namespace std;

int n;
int A[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	sort(A, A + n);	//���� �迭 ����

	int max_w = 0;
	for (int i = 0; i <= n; i++) {	//i: ���� ��� ����
		max_w = max(max_w, A[n - i] * i);
		//i�� �� ���� ����(n - i) �߷���(A[n - i]) ���� ��.
		//���� * i�� => �ִ� �߷�
	}

	cout << max_w;
}