#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
long A[100005];
long long array_score(int start, int end) {
	if (start > end) return -1;
	else if (start == end) return A[start]*A[start]; // �κй迭�� ���� 1 ;;
	else {
		int mid = (start + end) / 2;

		long result = max(array_score(start, mid - 1), array_score(mid + 1, end)); // ���ʿ��� ����� �ִ� ������ �����ʿ��� ����� �ִ뿵�� ���ؼ� �ִ밪 ã��

		//���ʿ������� �ɸ� �κй迭 �� �ִ� ����

		long now_min_score = A[mid];
		int left = mid;
		int right = mid;
		long now_max_sum = A[mid];

		while (right - left < end - start/*left�� right�� start�� end�� ���� �� break*/) {
			long p = left > start ? A[left - 1] : -1; // �������� Ȯ������ �� �ּҰ�
			long q = right < end ? A[right + 1] : -1; // ���������� Ȯ������ �� �ּҰ�

			if (p > q) {
				now_max_sum += p;
				now_min_score = min(now_min_score, p);
				left--;
			}
			else {
				now_max_sum += q;
				now_min_score = min(now_min_score, q);
				right++;
			}
			result = max(result, now_max_sum * now_min_score);// 3�� ���� �� �ִ����� ����
		}

		return result;
	}
}//�ִ밪�� ���ϴ� �Լ�
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cout << array_score(0, N - 1);
	return 0;
}
