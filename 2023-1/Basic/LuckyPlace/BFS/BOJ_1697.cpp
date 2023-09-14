#include <iostream>
#include <queue>
using namespace std;

int dist[100002];
int dx[3] = { 1,-1,2 };			// 2�� *2

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	queue<int> Q;
	int N, K;				// N : �����̰� �ִ� ��ġ, K : ������ �ִ� ��ġ
	cin >> N >> K;
	Q.push(N);
	for (int i = 0; i < 100002; i++)
		dist[i] = -1;
	dist[N] = 0;
	//while (!Q.empty())						// �ݺ� ������ queue�� �� �������ϸ� �ȵ�
	while (dist[K] == -1)
	{
		auto current = Q.front();
		Q.pop();
		for (int dir = 0; dir < 3; dir++)
		{
			int position;							// ������ ��ġ
			if (dx[dir] == 2)						// 2�� �̵�
				position = current * 2;
			else                                      // +1 -1 �̵�
				position = current + dx[dir];
			if (position < 0 || position > 100000)			// ���� ������ ������ ���
				continue;
			if (dist[position] >= 0)								// �̹� ���� ��ġ�� ���
				continue;
			dist[position] = dist[current] + 1;
			Q.push(position);
			/*if (position == K)
			{
				cout << dist[position];
				return 0;
			}*/
		}
	}
	cout << dist[K];
	return 0;
}