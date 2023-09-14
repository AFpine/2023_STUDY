//1863 ��ī�̶��� 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int N;
int X, Y;
stack<int> st;
int cnt = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        
        while(!st.empty() && st.top() > Y) {
            // ��ī�� ������ ���� ���������� ����
            cnt++;
            st.pop();
        }
        if (!st.empty() && st.top() == Y) continue;
        // ���� ��ī�̶��� ���̿� ���� ������ ���̰� ���ٸ� �������� �ʰ� �׳� �Ѿ
      
        st.push(Y);
    }
    while (!st.empty()) {
        if (st.top() != 0) {
            //��ī�̶����� ���̰� 0�� ���� ī��Ʈ ���� ����
            cnt++;
        }
        st.pop();
    }
    cout << cnt;
}

