/*
	Day: 2023.03.16
	참고 : 시간 초과 => 이중 반복문을 줄여보자!
*/
#include <iostream>
using namespace std;

int a[1000001] = {};

int main(void) {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);
	
	int size = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		int temp = 0;
		cin >> temp;
		a[temp]++;
	}

	int x = 0;
	cin >> x;

	int ans = 0;
	for (int i = 0; i < 1000001; i++) {
		if ((x - i) > i) {
			if ((x - i) < 1000001 && (x - i) > 0) {
				if (a[i] > 0 && a[x - i] > 0) {
					ans++; a[x - i] = 0;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
