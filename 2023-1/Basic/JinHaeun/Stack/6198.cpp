#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;        // ���� ����  
    cin >> n;

    stack<int> stk;       

    int a;
    long long cnt = 0;        //�������� Ȯ�� ���� �� �� ���� 1,000,000,000 �̷��� �շ�  
    int num = 0;        //���ÿ� �����ִ� �ǹ� ����  

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        
        if(i != 0)
        {
        	while(!stk.empty())
        	{
        		if(stk.top() > a )
        		{
        			cnt += num;
        			break;
				}	
        		else
        		{
        			stk.pop(); 
        			num--;
				}		
			}
		}
        
		stk.push(a);
		num++;
    }
	
	cout << cnt;
    

    return 0;
}
