#include <iostream>
using namespace std;

int lc[100001];
int rc[100001];
int p[100001];				// iterative�ϰ� ���� ��ȸ�� �����ϱ� ���� parent����
bool vis[100001];			// iterative�ϰ� ���� ��ȸ�� �����ϱ� ���� vis����

int cnt;

//void inorder(int cur)		// �Ƹ� �Ұ���
//{
//	if (lc[cur] != 0)
//		inorder(lc[cur]);
//	cout << cur << ' ';
//	if (rc[cur] != 0)
//		inorder(rc[cur]);
//}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		int C, L, R;
		cin >> C >> L >> R;
		if (L != -1)
			lc[C] = L;
		if (R != -1)
			rc[C] = R;
		if (L != -1)
			p[L] = C;
		if (R != -1)
			p[R] = C;
	}
	int cur = 1;		// cur == root(1)
	int rightmost = 1;		// ���� ������ �Ʒ��� ���, ���� ��Ʈ ��常 �����ϸ� ��Ʈ ��尡 rightmost�̹Ƿ� 1�� �ʱ�ȭ
	while (rc[cur] != 0)
	{
		rightmost = rc[cur];
		cur = rightmost;
	}
	//rightmost���� ���߷��� recursive�ϰ� ������ �Ұ����ϹǷ� iterative�ϰ� ����
	cur = 1;
	while (true)
	{
		vis[cur] = true;
		cnt++;
		if (lc[cur] != 0 && !vis[lc[cur]])
			cur = lc[cur];
		else if (rc[cur] != 0 && !vis[rc[cur]])
			cur = rc[cur];
		else                                     // ���� ������ �Ѵ� �湮�߰ų� �� ���� ���
		{
			if (cur == rightmost)		  // �����µ� ���� rightmost�� break
				break;
			else                                // �װ͵� �ƴϸ� �θ� ���� �ö󰡱�
				cur = p[cur];
		}
	}
	cout << cnt - 1;				//	�� ó�� root���� ������ �� ���ʿ��ϰ� 1�� �߰��ǹǷ� 1�� ���ش�
	return 0;
}