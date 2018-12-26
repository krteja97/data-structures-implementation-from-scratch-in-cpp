#include<bits/stdc++.h>
#define MAX_SIZE 23
using namespace std;

struct stacc
{
	int top;
	int * array;	
};

void Push(stacc * s,int x);
void pop(stacc * s);
void show_top(stacc *s);

int main()
{
	struct stacc * s;
	s->top = -1;
	s->array = new int[MAX_SIZE];
	int x;
	while(true)
	{
		cout<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.show_top"<<endl;
		cin>>x;

		switch(x)
		{
			case 1:
				int z;
				cout<<"enter number to push"<<endl;
				cin>>z;
				Push(s,z);
				break;
			case 2:
				pop(s);
				break;
			case 3:
				show_top(s);
				break;
			default:
				break;
		}
	}
	return 0;
}

void Push(stacc * s,int x)
{
	if(s->top == MAX_SIZE-1)
	{
		cout<<"unable to insert"<<endl;
		return ;
	}
	s->top++;
	s->array[s->top] = x;
	return ;
}

void pop(stacc * s)
{
	if(s->top == -1)
	{
		cout<<"cannot pop, stacc empty"<<endl;
		return ;
	}

	s->top--;
	return ;
}
;
void show_top(stacc *s)
{
	if(s->top == -1)
	{
		cout<<"not plausible mate"<<endl;
		return ;
	}
	cout<<s->array[s->top]<<endl;
	return ;
}