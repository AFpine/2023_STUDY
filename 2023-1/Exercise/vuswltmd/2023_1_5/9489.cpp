//9489 ���� 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int n, k;
int graph[1000001];
vector<int> idx;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    while (1) {
        if (n == 0 && k == 0) {
            break;
        }

        int parent_idx = -1, before = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int node; cin >> node;
            idx.push_back(node);

            if (i == 0) {
                // ��Ʈ�� ��
                before = node;
                graph[node] = node;
            }
            else {
                if (before + 1 == node) {
                    // node�� ���� �� ���� �������̶�� ���� �θ� �����ϴ� ��� 
                    graph[node] = idx[parent_idx];
                    before = node;
                }
                else {
                    // node�� ���� �� ���� ���������� �ʴٸ� ���� �θ� �������� ����
                    graph[node] = idx[++parent_idx];
                    before = node;
                }
            }
        }

        for (int n : idx) {
            if (graph[graph[n]] == graph[graph[k]]) {
                // �θ��� �θ� ���ٸ�                
                if (graph[n] != graph[graph[k]]) {
                    // n�� �θ� k�� ���θ��̸� �ȵ�
                    if (graph[n] != graph[k]) {
                        // �θ� �ٸ��ٸ� (������ �θ�� �ٸ��� �θ��� �θ� ���ƾ���)
                        if (graph[k] != graph[idx[0]]) {
                            // k�� �θ� ��Ʈ��尡 �ƴ϶�� (����)
                            ans++;
                        }
                    }
                }
            }          
        }
        cout << ans << '\n';
        idx.clear();

        cin >> n >> k;
    }

}

