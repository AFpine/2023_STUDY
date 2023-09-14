#include <iostream>
using namespace std;

const int MAX_NUM = 3075;				//  1024 * 3 �˳���� + 3
char star_board[MAX_NUM][MAX_NUM * 2];		// ���� ��Ȯ���� MAX_NUM * 2 - 1�� �ʿ������� �˳��ϰ� �����

void print_star(int r, int c)		// ���� ���� �ﰢ�� ���� ��� �Լ�
{
	star_board[r][c] = '*';
	star_board[r + 1][c - 1] = '*';
	star_board[r + 1][c + 1] = '*';
	for (int i = c - 2; i <= c + 2; i++)
		star_board[r + 2][i] = '*';
}

void recursion(int r, int c, int n)		// r, c�� print_star�� �������� ó�� ��ġ, n�� �ʱ� �Է°�
{
	if (n == 3)				// base conditon
	{
		print_star(r, c);
		return;
	}
	else
	{
		int half = n / 2;			// 2^n�̹Ƿ� 2�� ���� �ش�
		// 3���� �ﰢ���� ����Ż ������ �����Ƿ� ����Լ� 3���� ȣ�����ش�.
		recursion(r, c, half);	
		recursion(r + half, c - half, half);
		recursion(r + half, c + half, half);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	recursion(0, n - 1, n);					// �ʱ� ��ġ : row = n -1, column = 0
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 2 - 1; j++)
		{
			if (star_board[i][j] == '*')
				cout << '*';
			else
				cout << ' ';
		}
		cout << "\n";
	}

	return 0;
}