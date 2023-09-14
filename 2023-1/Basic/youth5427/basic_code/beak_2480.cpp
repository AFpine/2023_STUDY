/*
	Day: 2023.03.10
	참고 : 
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int result = int(a == b) + int(b == c) + int(c == a);

	if (result == 3) {
		cout << 10000 + (a * 1000) << endl;
	}
	else if (result == 1) {
		if (a == b || a==c)	cout << 1000 + a * 100 << endl;
		else if(b==c) cout << 1000 + b * 100 << endl;
	}
	else if (result == 0) {
		int temp = (int)max({ a, b, c });
		cout << 100 * temp << endl;
	}
}
