#include<bits/stdc++.h>
using namespace std;

int main()
{
	stack <int> s;
	int x;

	while(true)
	{
		cout<<endl<<"enter the choice"<<endl;
		cout<<"1.push"<<endl<<"2.pop"<<endl<<"3.show_yop"<<endl;
		cin>>x;
		int p;
		switch(x)
		{
			case 1:
				cout<<"enter number to be inserted"<<endl;
				int g;
				cin>>g;
				s.push(g);break;
			case 2:
				 s.pop();break;
			case 3:
				p = s.top();break;
			default:
				break;
		}
		cout<<p<<endl;
	}
	return 0;
}