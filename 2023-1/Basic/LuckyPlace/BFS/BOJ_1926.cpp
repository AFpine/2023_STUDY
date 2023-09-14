#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[502][502];

bool vis[502][502];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;
	int n, m;
	cin >> n >> m;		// n�� ����(��) m�� ����(��)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	int picture_num = 0;			// �׸��� ����(�Ķ����� ����)
	int area_max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)		// �Ķ����� ã�� ���� 2�� for��
		{
			if (board[i][j] == 0 || vis[i][j] == 1)		// �������� ���� �Ķ����̿��� üũ�� ��� continue
				continue;
			Q.push({ i, j });
			vis[i][j] = 1;				// ã�� ���� �ϴ� üũ �ȵ� �Ķ����̹Ƿ� üũ
			picture_num++;
			int picture_area = 1;
			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)		// ���� ���� ��� continue
						continue;
					if (vis[nx][ny] || board[nx][ny] != 1)				// �̹� ���Ұų� �Ķ����� �ƴ� ��� continue
						continue;
					vis[nx][ny] = 1;
					picture_area++;
					Q.push({ nx, ny });
				}
			}
			if (area_max < picture_area)
				area_max = picture_area;
		}
	}
	cout << picture_num << "\n" << area_max;

	return 0;
}