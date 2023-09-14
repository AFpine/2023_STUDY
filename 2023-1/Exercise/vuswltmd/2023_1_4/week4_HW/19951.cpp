//19951�� �»����� �Ʒü� ��Ȱ

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int soil[100'005];
int order_sum[100'005]; // ������ ����� ��ĥ ����
int N, M; // N: ������ ũ��, M: ������ ��

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> soil[i];
    }

    while (M--) {
        //a�� ĭ���� b�� ĭ���� ���̰� 
        //���� | k | ��ŭ �þ���� ���� ����� �Ѵ�.
        // k�� ������ ���� �ĳ��� ��, ����� ���� �״� ��
        int a, b, k;
        cin >> a >> b >> k;

        order_sum[a] += k;
        order_sum[b + 1] += (-1) * k;
    }

    for (int i = 1; i <= N; i++) {
        order_sum[i] += order_sum[i - 1];
    }

    for (int i = 1; i <= N; i++) {
        soil[i] = soil[i] + order_sum[i];
        cout << soil[i] << ' ';
    }
}

// ���� https://yabmoons.tistory.com/729

