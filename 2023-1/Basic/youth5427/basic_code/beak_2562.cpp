/*
	Day: 2023.03.12
	���� : �ִ밪 �Լ� *max_element( , )
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[9] = { 0 };
	for (int i = 0; i < 9; i++)
		cin >> arr[i];

	int max = *max_element(begin(arr), end(arr));	// ��ü �ּҸ� �����ϱ� ������ * ���
	cout << max << endl;

	for (int i = 0; i < 9; i++)						// �ִ밪 ��ġ �˻�
		if (max == arr[i]) cout << i+1 << endl;
}