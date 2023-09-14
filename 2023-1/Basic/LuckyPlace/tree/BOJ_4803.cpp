#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> vertex[501];
bool is_visited[501];
int parent[501];
bool is_tree;
int cnt = 0;
int num = 1;		// case �� ���

void bfs(int root)
{
	queue<int> q;
	q.push(root);
	is_visited[root] = true;		// ���� �湮 ǥ��
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : vertex[cur])
		{
			if (parent[cur] == next)		// �θ� ���� ���� �ȵ�
				continue;
			if (is_visited[next])			// ���� �ڽ� ��尡 �湮�Ǿ��ٸ� tree�� �ƴ�
			{
				is_tree = false;
				continue;
			}
			parent[next] = cur;
			q.push(next);
			is_visited[next] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		while (m--)
		{
			int u, v;
			cin >> u >> v;
			vertex[u].push_back(v);
			vertex[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			if (is_visited[i])			// �̹� �ѹ� �湮�ߴ� ���̸� ���� �� �ʿ� ����
				continue;
			is_tree = true;
			bfs(i);
			if (is_tree)
				cnt += 1;
		}
		cout << "Case " << num << ": ";
		if (cnt > 1)
			cout << "A forest of " << cnt << " trees." << '\n';
		else if (cnt == 1)
			cout << "There is one tree." << '\n';
		else
			cout << "No trees." << '\n';
		num++;
		cnt = 0;
		for (int i = 0; i <= n; i++)
		{
			vertex[i].clear();
			is_visited[i] = false;
		}
	}
	return 0;
}