#include <bits/stdc++.h>
using namespace std;

int n;
int arr[21][21];
//1:�Ҽ���, 2:��������ü, 0:�Ҽ����� ��������ü�� ����X

//���� �ڸ� �� ���� ���
/*1. �Ҽ����� ������ 1������ ���
  2. �Ҽ����� �ְų�, �Ҽ����� ������ �Ѵ� ���� ���
  3. �Ҽ��� ����, ������ 2���̻��� ���
  4. �Ҽ����� �ڸ����� �ϴ� ���⿡ ������ �ִ� ���
  5. ���η� �ڸ� ��, �Ҽ����� ���� �� �Ǵ� ���� �Ʒ��� �ִ� ���
  6. ���η� �ڸ� ��, �Ҽ����� ���� ���� �Ǵ� ���� �����ʿ� �ִ� ���

  ������ �������� �� ex)���η� ���� -> ���� ������ ����Ǽ� * ������ ������ ����Ǽ�
  */

//slice�� true - ���η� �߸�, false - ���η� �߸�
int solve(int x0, int y0, int xi, int yi, bool slice) {
	int impurities = 0, jewels = 0;
	for (int y = y0; y < yi; y++) {
		for (int x = x0; x < xi; x++) {
			if (arr[y][x] == 1)	//�Ҽ��� ����
				impurities++;
			else if (arr[y][x] == 2) //���� ����
				jewels++;
		}
	}

	if (jewels == 1 && impurities == 0)	//�Ҽ��� x, ����o ->���డ��
		return 1;
	else if (jewels == 1 && impurities == 1)//1����� -> ����Ұ�
		return 0;
	else if (jewels == 0)	//2�� ��� -> ����Ұ�
		return 0;
	else if (jewels > 2 && impurities == 0)	//3����� ->����Ұ�
		return 0;

	//�Ҽ����� ��������ü�� �������� ��� -> ������ ���� ��������
	int result = 0;
	for (int y = y0; y < yi; y++) {
		for (int x = x0; x < xi; x++) {
			if (arr[y][x] == 1) { //�Ҽ����� ��
				if (slice) { //������ ���η� �߶� ������ ���θ� ����
					//���η� �ڸ� �� �ִ°�?
					if (x != x0 && x != xi - 1) {//�糡�� �ƴ϶� 1���հ�
						bool check = true;
						for (int i = y0; i < yi; i++) {
							if (arr[i][x] == 2) { //���ο� ������ �־ �Ұ���
								check = false;
								break;
							}
						}

						if (check) //���ο� ������ ��� 2���հ�
							result = result + solve(x0, y0, x, yi, false) * solve(x + 1, y0, xi, yi, false);
					}
				}

				else {//������ ���η� �߶��� ������ �� ������ ���θ� ����
					//���η� �ڸ� �� �ִ°�?
					if (y != y0 && y != y - 1) { //�� ���� �ƴ϶� 1���հ�
						bool check = true;
						for (int i = x0; i < xi; i++) {
							if (arr[y][i] == 2) {	//���ο� ������ �־ �Ұ���
								check = false;
								break;
							}
						}

						if (check) //���ο� ������ ��� 2�� �հ�
							result = result + solve(x0, y0, xi, y, true)*solve(x0, y + 1, xi, yi, true);
					}
				}
			}
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int impurity = 0, jewel = 0;
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> arr[y][x];
			if (arr[y][x] == 1)
				impurity++;
			else if (arr[y][x] == 1)
				jewel++;
		}
	}

	if (impurity == 0 && jewel == 1)
		cout << 1;
	else {
		int resultA = solve(0, 0, n, n, true);
		int resultB = solve(0, 0, n, n, false);
		if (resultA + resultB == 0)
			cout << -1;
		else
			cout << resultA + resultB;
	}

	return 0;
}