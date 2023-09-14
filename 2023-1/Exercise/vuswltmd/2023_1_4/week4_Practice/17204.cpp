//17204 ������ ����
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int N, K;
int ans = 0;
int order[200];
bool vis[200];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> order[i];
    }

    int nxt = order[0];

    while (!vis[nxt]) {
        //cout << "nxt: " << nxt << '\n';
        ans++;
        vis[nxt] = true;
        if (nxt == K) {
            cout << ans;
            return 0;
        }
        nxt = order[nxt];
    }
    // cout << "nxt: " << nxt << '\n';
    cout << -1;
}

//6 2
//1
//3
//5
//4
//0
//2

//������ ���̰� ��� 2�� �����ߴ��� ������ ���̱��� �������� ���ϸ� 2�� ������� ���Ѵ�.
