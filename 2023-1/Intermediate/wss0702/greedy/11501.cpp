#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//1. �ֽ� �ϳ��� ���.
//2. ���ϴ� ��ŭ ������ �ִ� �ֽ��� �Ǵ�
//3. �ƹ��͵� ���Ѵ�
//�ִ� ����(�Ĵ� ���� �ְ� - �� ���� �ְ�)
//������ �� ���� Ž���ؼ� �ְ� �ְ��� ���� �ְ� �ְ����� ���� �ְ���  ������ ��� �ְ� �ְ����� ���� �ְ��� ���´� �ְ� �ְ� ���� �ٽ� Ž�� 

using namespace std;
int N, T;
int price[1000005];
vector<int> pre_price;
long long ans;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> price[i];
		}
		int m = price[N - 1];
		for (int i = N - 1; i >= 0; i--) {
			if (m > price[i]) {
				ans += m - price[i];
			}
			else {
				m = max(price[i], m);
			}
		}
		cout << ans << "\n";
		ans = 0;
	}
}
