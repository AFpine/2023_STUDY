#include <iostream>
using namespace std;

bool paper[130][130];		//0�� 1�� ǥ�� �����ϹǷ� bool�� 2���� �迭 ����(0�� ��� 1�� �Ķ��� �ǹ�)
int arr[2];							// 0��°�� ��� 1��°�� �Ķ��� ����
int N;		// ���簢�� �Ѻ��� ����

bool is_same_color(int x, int y, int n)		//�簢�� ��ü�� ���� ������ Ȯ���ϴ� �Լ�
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (paper[x][y] != paper[i][j])
				return false;
	return true;
}

void recursion(int x, int y, int n)		//x, y�� ������, n�� �� ���� ����
{
	if (is_same_color(x, y, n))
	{
		arr[paper[x][y]]++;
		return;
	}
	else
	{
		int half = n / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				recursion(i * half + x, j * half + y, half);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	recursion(0, 0, N);

	for (int i = 0; i < 2; i++)
		cout << arr[i] << "\n";
	return 0;
}