#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//ó�� -�� ��Ÿ���� �� ��ȣ ����
//��ȣ ������  -�� ��Ÿ���� ��ȣ �ݱ�
//��ȣ ���� �� +�� ��Ÿ���� ��� ����
//��ȣ ���� �� �ٷ� -�� ��Ÿ���� ��ȭ ���� ����
using namespace std;
int N;

int ans;
int tmp;
int sign = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	cin >> input;
	for (char c : input) {
		if (c == '+' || c == '-') {
			ans += tmp * sign; // ó�� -�� ��Ÿ���� �� ��ȣ ���� ��ȣ ���� �� + ��Ÿ���� ��� ����(sign���� +�� -�� �ٲٱ�)
			if (c == '-') {
				sign = -1;
			}
			tmp = 0;
		}
		else {
			tmp *= 10; // �ڸ��� �ø��鼭 
			tmp += c - '0'; //���ϱ�
		}
	}
	ans += tmp * sign;
	cout << ans;
	
}
