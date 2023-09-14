#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

char board[1001][1001];
int dist1[1001][1001];						// �� �Ÿ�
int dist2[1001][1001];						// ����� �Ÿ�
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	queue<pair<int, int>> F;				// ��
	queue<pair<int, int>> SG;				// �����
	int n;				// �׽�Ʈ���̽� ����
	cin >> n;
	while (n--)
	{
		int w, h;
		cin >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
				dist1[i][j] = -1;
				dist2[i][j] = -1;
				if (board[i][j] == '@')
				{
					SG.push({ i,j });
					dist2[i][j] = 0;
				}
				if (board[i][j] == '*')
				{
					F.push({ i,j });
					dist1[i][j] = 0;
				}
			}
		}
		while (!F.empty())
		{
			auto current = F.front();
			F.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = current.first + dx[dir];
				int ny = current.second + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if (board[nx][ny] == '#' || dist1[nx][ny] >= 0)
					continue;
				dist1[nx][ny] = dist1[current.first][current.second] + 1;
				F.push({ nx, ny });
			}
		}
		bool escape = false;
		while (!SG.empty() && !escape)
		{
			auto current = SG.front();
			SG.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = current.first + dx[dir];
				int ny = current.second + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)			// Ż�� �� ��
				{
					escape = true;
					cout << dist2[current.first][current.second] + 1 << '\n';
					break;
				}
				if (board[nx][ny] == '#' || dist2[nx][ny] >= 0)
					continue;
				if (dist1[nx][ny] != -1 && (dist2[current.first][current.second] + 1 >= dist1[nx][ny]))
					continue;
				dist2[nx][ny] = dist2[current.first][current.second] + 1;
				SG.push({ nx, ny });
			}
		}
		while (!SG.empty())			// ����� queue�� ������ ������� �ʴ� ��찡 ����Ƿ�
			SG.pop();
		/*if (escape)				// �޸� �ʰ� ����
		{
			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
				{
					n = max(n, dist2[i][j]);
				}
			}
			cout << n << '\n';
		}*/
		if (!escape)
			cout << "IMPOSSIBLE" << '\n';
	}
	return 0;
}