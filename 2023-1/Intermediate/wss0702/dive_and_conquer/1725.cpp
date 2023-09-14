#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
int H[100005];
int histogram(int start, int end) {
	if (start == end) return 0; // ���� 0;
	if (start + 1 == end) return H[start]; // ���� 1;

	int mid = (start + end) / 2;
	int result = max(histogram(start, mid), histogram(mid, end)); // ���ʿ��� ����� �ִ� ������ �����ʿ��� ����� �ִ뿵�� ���ؼ� �ִ밪 ã��

	//���ʿ������� �ɸ� ���簢�� �� �ִ� ����
	int w = 1;
	int h = H[mid];
	int left = mid; 
	int right = mid;
	while (right - left + 1 < end - start/*left�� right�� start�� end�� ���� �� break*/) {
		int p = left > start ? min(h, H[left - 1]) : -1; // �������� Ȯ������ ��
		int q = right < end - 1 ? min(h, H[right + 1]) : -1; // ���������� Ȯ������ ��
		if (p >= q) {
			h = p;
			left--;
		}
		else {
			h = q;
			right++;
		}
		w++; // �����̵� �������̵� ��ĭ�� Ȯ��Ʊ� ������
		result = max(result, w * h);// 3�� ���� �� �ִ뿵�� ����
	}

	return result;
}//�ִ밪�� ���ϴ� �Լ�
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
	cout << histogram(0, N);
	return 0;
}
