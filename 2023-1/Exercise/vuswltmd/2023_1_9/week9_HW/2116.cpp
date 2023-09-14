//����2116 �ֻ��� �ױ�
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num;
int dice[10'005][7];
vector<pair<int, int>> up_down_set[10'005];
int _max = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> num;
	
	// A�� F�� ¦, B�� D�� ¦, C�� E�� ¦

	for (int i = 0; i < num; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> dice[i][j];
		}
	}

	int _count = 0;

	for (int i = 0; i < num; i++) {
		up_down_set[i].push_back({ dice[i][1], dice[i][6]}); // A�� F�� ¦
		up_down_set[i].push_back({ dice[i][2], dice[i][4] }); // B�� D�� ¦
		up_down_set[i].push_back({ dice[i][3], dice[i][5] }); // C�� E�� ¦
		//i��° �ֻ����� ���Ʒ� ¦
	}

	for (int cnt = 1; cnt <= 6; cnt++) {
		
		int _down = cnt; // ù��° �ֻ����� �ٴ�
		int _up; // ù��° �ֻ����� ����
		int value = 0;

		for (int i = 0; i < num; i++) {

			for (int j = 0; j <= 2; j++) {
				if (up_down_set[i][j].first == _down) {
					_up = up_down_set[i][j].second;
					break;
				}
				else if (up_down_set[i][j].second == _down) {
					_up = up_down_set[i][j].first;
					break;
				}
			}

			for (int j = 6; j >= 1; j--) {
				if (j != _down && j != _up) {
					value = value + j;
					break;
				}
			}

			_down = _up;
		}

		if ( _max < value) {
			_max = value;
		}
	}
	
	cout << _max;
}
