#include <bits/stdc++.h>
using namespace std;

string str, num;
bool isMinus = false;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int min_val = 0;
	cin >> str;

	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '-' || str[i] == '+' || i == str.size()) {
			if (isMinus) {	//true�� ���� ���� ���� ����
				min_val -= stoi(num);
				num = "";	//num reset
			}
			else {			//isMinus�� false��� ���ϱ� ���� ����
				min_val += stoi(num);
				num = "";	//num reset
			}
		}
		else
			num += str[i];	//str[i]�� ���� -> num�� ���ڸ� ����

		if (str[i] == '-') {
			isMinus = true;	//'-'�����ڰ� ������ isMinus true�� ����
		}
	}

	cout << min_val;
}