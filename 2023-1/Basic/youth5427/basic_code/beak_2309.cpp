/*
	Day: 2023.03.11
	���� :
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[9] = { 0 };			// ������ ������ 9��
	int result[7] = { 0 };		// ������ 7��
				
	for (int i = 0; i < 9; i++)		// ������ Ű �Է�
		cin >> arr[i];

	for (int a = 0; a < 9; a++) {		// 2��[a,b(a����ū)] ������ ���
		int sum = 0;					// 7���� �� : sum(100)
		for (int b = a+1; b < 9; b++){
			sum = 0;

			for (int c = 0, temp = 0 ; c < 9; c++) {
				if (c != a && c != b)	result[temp++] = arr[c];
			}
			for (int i = 0; i < 7; i++) {
				sum += result[i];
			}
			if (sum == 100) break;
		}
		if (sum == 100) break;;
	}

	sort(result, result + 7);			// �������� ����
	for (int i = 0; i < 7; i++) 		// Ű �Է�
		cout << result[i] << endl;
}