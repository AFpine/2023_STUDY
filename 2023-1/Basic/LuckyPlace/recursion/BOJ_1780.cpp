#include <iostream>
using namespace std;

int paper[2200][2200];
int arr[3];						// -1, 0, 1�� ������ ����(���������̹Ƿ� 0���� �ڵ� �ʱ�ȭ)
int N;

bool is_same_num(int x, int y, int n)		// x, y�� �簢���� ���� �� ������ n�� �˻��� ����
{
	for (int i = x; i < x + n; i++)				// ������ ���ǿ� �������� ������� �Ѵ�.
	{
		for (int j = y; j < y + n; j++)
		{
			if (paper[x][y] != paper[i][j])
				return false;
		}
	}
	return true;
}

void recursion(int x, int y, int n)
{
	if (is_same_num(x, y, n))
	{
		arr[paper[x][y] + 1]++;	
		return;
	}
	else
	{
		int a = n / 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				recursion(x + a * i, y + a * j, a);			// ��ͽ���, x, y(������)�� ������� �Ѵ�.(��Ʈ ��)
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	recursion(0, 0, N);

	for (int i = 0; i < 3; i++)			// ���
		cout << arr[i] << "\n";
	return 0;
}