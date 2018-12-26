#include<bits/stdc++.h>
using namespace std;

void juggling_algo(int *array, int n, int k);
int GCD(int n,int k);

int main()
{
	int n,k;
	cin>>n>>k;

	int array[n];
	for(int i=0;i<n;i++)
		cin>>array[i];

	juggling_algo(array,n,k);
	cout<<endl<<"----------------------"<<endl;
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
	return 0;
}

void juggling_algo(int array[],int n,int k)
{
	int gcd = GCD(n,k);
	for(int i=0;i<gcd;i++)
	{
		int start = array[i];
		int j = i;
		int p = j;

		do
		{   
			p = j;
			array[j] = array[(j+k)%n];
			j = (j+k)%n;
		}
		while(i != j);
		array[p] = start;
	}
}

int GCD(int a,int b)
{
	if(a == 0)
		return b;
	return (GCD(b%a,a));
}

