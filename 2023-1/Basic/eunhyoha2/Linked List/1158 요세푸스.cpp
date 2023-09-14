#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	queue<int>q;
	for (int i = 1; i <= n; i++) {
		q.push(i); //1~n�� ���� ť �����
	}
	cout << "<";

	while (q.size() > 1) {
		for (int i = 1; i < k; i++) {
			int tmp = q.front();
			q.pop(); //k-1��°���� pop
			q.push(tmp); //�ڷ� push
		}
		cout << q.front() << ", "; //�� ������ �� k ���
		q.pop();
	}
	cout << q.front() << ">\n"; //������ ���
}