#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> vertex[20001];
int color[20001] = { 0, };
int n, m;			// ������ ������ ������ ����

bool is_bipartite_graph()			// �̺� �׷��� ���� �Ǻ��ϴ� �Լ� true�� �̺� �׷���
{
	for (int cur = 1; cur <= n; cur++)		// ��� node�� �� Ȯ��
	{
		for (auto next : vertex[cur])
		{
			if (color[next] % 2 == color[cur] % 2)		// ����Ǿ� �ִ� node���� ���� ������
				return false;										// false ����
			else 
				continue;
		}
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;		// �׽�Ʈ ���̽��� ����
	cin >> k;
	queue<int> q;
	while (k--)
	{
		cin >> n >> m;
		int u, v;
		while (m--)			// ���� ���� �Է�
		{
			cin >> u >> v;
			vertex[u].push_back(v);
			vertex[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)			// ��� ����� ���� ���� bfs Ž��
		{
			if (color[i] > 0)
				continue;
			q.push(i);				
			color[i] = 1;			// Ȧ�� ¦���� �� ����
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto next : vertex[cur])
				{
					if (color[next] > 0)
						continue;
					color[next] = color[cur] + 1;
					q.push(next);
				}
			}
		}
		if (is_bipartite_graph())
			cout << "YES";
		else
			cout << "NO";
		cout << endl;

		for (int i = 0; i <= n; i++)		// ���������� vertex vector�� color �ʱ�ȭ
		{
			vertex[i].clear();
			color[i] = 0;
		}
	}
	return 0;
}