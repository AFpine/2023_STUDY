#include <bits/stdc++.h>
using namespace std;

int n;	//ȸ���� ��
pair<int, int> A[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0, time = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i].second >> A[i].first;
		/*������ �ð��� ���� ����� ȸ�� ������ ����
		  ������ �ð���� �����ϱ� ���ؼ� ���� first�� �־���*/
	}

	sort(A, A + n);

	for (int i = 0; i < n; i++) {
		if (time <= A[i].second) { //(1, 4) (3, 5) => 4�� 3���ε�
			cnt++;				   //������ ���۰� �� �Ųٷ� �־ sec�� time��
			time = A[i].first;    //(4, 1) (5, 3)���� �迭�� ���� but, ���ٰ� �Ȱ��� ���ϸ� ��.
			//a.fir = ������ �ð�!!!
		}
	}

	cout << cnt;
}