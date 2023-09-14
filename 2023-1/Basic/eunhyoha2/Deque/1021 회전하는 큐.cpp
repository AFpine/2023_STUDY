#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	deque<int> dq;
	int N, M; //ť�� ũ��N, �̾Ƴ����� ����M
	int left, right;
	int cnt = 0;
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	while (M--) {
		int num;
		cin >> num; //���� ���� ��ġ �Է� �ޱ�

		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == num) { //�� ������ ��ġ�� �Է¹��� ��ġ�� ���ٸ�
				left = i;
				right = dq.size() - i; //�̵� Ƚ���� ���� ���� ã��
				break;
			}
		}
		if (left <= right) {
			while (1) {
				if (dq.front() == num) //�־��� ���� ����Ʈ�� �� ������
					break;

				dq.push_back(dq.front());
				dq.pop_front(); // �������� �� ĭ
				cnt++; // ī��Ʈ �ϸ� �ݺ�
			}
			dq.pop_front();
		}
		else {
			cnt++;
			while (1) {
				if (dq.back() == num)
					break;

				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
			dq.pop_back();
		}
	}
	cout << cnt;

	return 0;
}