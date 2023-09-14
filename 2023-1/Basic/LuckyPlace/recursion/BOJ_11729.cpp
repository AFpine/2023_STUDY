#include <iostream>
//#include <cmath>
using namespace std;

void hanoi(int a, int b, int n)		// ���� n���� a�� ��տ��� b�� ������� �ű�� ����� ����ϴ� �Լ�
{
	if (n == 1)
	{
		cout << a << ' ' << b << "\n";		// endl���� �ð��ʰ�
		return;
	}
	hanoi(a, 6-a-b, n - 1);
	cout << a << ' ' << b << "\n";
	hanoi(6 - a - b, b, n - 1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;				// �ϳ��� ���� ����
	cin >> num;
	//cout << pow(2, num) - 1 << "\n";				// �¿�Ʋ?
	cout << (1<<num) - 1 << "\n";		// 2^n - 1 �� �����δ�.
	hanoi(1, 3, num);
	return 0;
}