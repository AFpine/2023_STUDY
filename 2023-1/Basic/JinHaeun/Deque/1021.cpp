#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
  
	deque<int> dq;
	
	int n;
	cin >> n;
	
	int m;
	cin >> m;
	
	for(int i=1; i<=n; i++)
	{
		dq.push_back(i);    //ťä���  
	}
	
	int cnt = 0;
	int index;
	for(int i=1; i<=m; i++)
	{
		int num;
		cin >> num;
		
		for(int j=0; j<dq.size(); j++)
		{
			if(dq[j] == num)         //���� STL���� �ε��� ���� ������  
			{
				index = j;         // ��ġ �ľ��� ���� �ε��� ���ϱ�  
				break;
			}
		}
		
		if(dq.size() - index > index)    //��ü ������� �ڽ� ��ġ �� �ͺ��� ������ �տ��� �ڷ� ����  
		{
			while(1)
			{
				if(dq.front() == num) break;
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
			dq.pop_front();			
		}
		else
		{
			while(1)
			{
				if(dq.front() == num) break;
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
			dq.pop_front();
		}
	}
	
	cout << cnt;

}
