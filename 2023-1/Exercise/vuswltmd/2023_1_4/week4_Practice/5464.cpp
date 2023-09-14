//5464 ������
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

// ������ ��ȣ�� �켱����ť�� ������ ũ�� ���� ������ ���ĵȴ�
// ���� �ö����� �켱���� ť���� ���� �˸��� ������ ��ȣ�� �Ҵ����ش�
// ���� �������� ���������� �� ������ ��ȣ�� �켱���� ť�� �ݳ��Ѵ�.

int N; //���������� ũ��
int M; // M���� ����
int fee[101]; // �������� �� ���� ���Դ� ���
int vis[101]; // �ش� ������ ���� ����Ȯ��
int car[2001]; //index: ����ȣ, value: ���� ����
queue<int> Q; //����ϴ� ���� �־�� �뵵
priority_queue<int, vector<int>, greater<>> pq; // ������ ��ġ��, ��ȣ�� ���� ����'����'�� ���� ��ġ��Ų��
int ans = 0;

void parking_system(int order) {
    if (order > 0) {
        if (!pq.empty()) {
            int parking_num = pq.top(); pq.pop();
            vis[parking_num] = order;
        }
        else {
            Q.push(order);
        }
    }
    else {
        for (int i = 1; i <= N; i++) {
            if (vis[i] == abs(order)) {
                pq.push(i);
                vis[i] = 0;
                //cout << "��� " << fee[i] << '\n';
                //cout << "�� ���� " << car[abs(order)] << '\n';
                ans += (fee[i] * car[abs(order)]);

                if (!Q.empty()) {
                    parking_system(Q.front());
                    Q.pop();
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> fee[i];
        pq.push(i);
    }

    for (int i = 1; i <= M; i++) {
        cin >> car[i];
    }

    for (int i = 0; i < 2 * M; i++) {
        int order;
        cin >> order;
        
        parking_system(order);
    }

    cout << ans;
}


