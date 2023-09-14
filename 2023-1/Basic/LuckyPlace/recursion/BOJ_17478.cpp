#include <iostream>
using namespace std;

int N;

void print_bar(int n)
{
	for (int i = 0; i < n; i++)
		cout << "____";
}

void recursion(int count)
{
	print_bar(count);
	cout << "\"����Լ��� ������?\"" << "\n";
	if (count == N)
	{
		print_bar(count);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
	}
	else
	{
		print_bar(count);
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";
		print_bar(count);
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
		print_bar(count);
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";
		recursion(count + 1);
	}
	print_bar(count);
	cout << "��� �亯�Ͽ���." << "\n";
}

int main(void)
{
	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";
	recursion(0);
	return 0;
}