//13164 �ູ��ġ��
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int N, K;
int student[300'005];
int cost[300'005];
int ans = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> student[i];
    }

    for (int i = 1; i < N; i++) {
        cost[i - 1] = student[i] - student[i - 1];
        //cout << "i - 1: " << i - 1<< '\n';
    }

    sort(cost, cost + N - 1);

    for (int i = 0; i < N - K; i++) {
        ans += cost[i];
    }

    cout << ans;
}

// cost: �� �� ��ġ�������� Ű ����
// N - K ���� Ű���̰� ���� ū ��츦 �����ϰ� cost�� ��� �� �ϸ� ��.
