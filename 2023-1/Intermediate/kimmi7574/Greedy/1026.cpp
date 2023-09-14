#include <bits/stdc++.h>
using namespace std;

int n;
int A[52];
int B[52];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	sort(A, A + n);
	//sol 1) sort(B, B + n);
	//sol 2)
	sort(B, B + n, greater<>());
	//A�� ������������, B�� ������������ ����

	int min_val = 0;
	for (int i = 0; i < n; i++) {
		//sol 1) min_val += A[i] * B[n - 1 - i]; -> B�迭�� ū �� �������
		//sol 2)
		min_val += A[i] * B[i];
	}

	cout << min_val;
}