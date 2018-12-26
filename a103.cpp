#include<bits/stdc++.h>
using namespace std;

void juggling_algo(int array[],int n,int k);
int binary_search(int *array,int low,int high,int x);
int GCD(int a,int b);

int main()
{
	int n,k;
	cin>>n>>k;
	int array[n];

	for(int i=0;i<n;i++)
		array[i] = rand()%n;

	sort(array,array+n);

	juggling_algo(array,n,k);
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	cout<<"enter the element to be searched"<<endl;
	int x;
	cin>>x;
	int index = binary_search(array,0,n-1,x);
	if(index == -1)
		cout<<"not found"<<endl;
	else
		cout<<index<<" "<<array[index]<<endl;

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

int binary_search(int *array,int low,int high,int x)
{
	if(low > high)
		return -1;
	int mid = (low + high)/2;

	if(x == array[mid])
		return mid;
	if(x < array[mid])
	{
		if(array[low] <= x)
			return binary_search(array,low,mid-1,x);
		else
			return binary_search(array,mid+1,high,x);
	}
	else
	{
		if(array[high] < x)
			return binary_search(array,low,mid-1,x);
		else
			return binary_search(array,mid+1,high,x);
	}
}

int GCD(int a,int b)
{
	if(a == 0)
		return b;
	return (GCD(b%a,a));
}