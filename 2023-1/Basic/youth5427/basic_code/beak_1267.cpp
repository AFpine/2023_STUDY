/*
	Day: 2023.03.11
	���� :
*/
#include <iostream>
using namespace std;

int main() {
	int num = 0, time = 0;
	cin >> num;				// num: ��ȭ�� Ƚ��

	int Y = 0, M = 0;		// [Y: ����, M: �ν�] ��� ���
	for (int i = 0; i < num; i++) {
		cin >> time;		// ��ȭ �ð� �Է�
		Y += (time / 30 + 1) * 10;
		M += (time / 60 + 1) * 15;
	}
	if (Y < M) cout << "Y " << Y << endl;
	else if(Y == M) cout << "Y " << "M " << Y << endl;
	else cout << "M " << M << endl;
}