#include<bits/stdc++.h>
using namespace std;

int binary_search(int * array,int k,int low,int high);

int main()
{
	int n,k;
	cin>>n;
	int array[n];
	k = rand()%n;
	for(int i=0;i<n;i++)
	{
		array[i] = rand()%n;
	}

	sort(array,array+n);

	int index = binary_search(array,k,0,n-1);

	if(index == -1)
		cout<<"element not found"<<endl;
	else
		cout<<index<<" "<<array[index]<<endl;

	cout<<endl<<"------------"<<endl;
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	cout<<k<<endl;
	return 0;
}

int binary_search(int * array,int k,int low,int high)
{
	if(low > high)
		return -1;
	int mid = (low + high)/2;
	if(k == array[mid])
		return mid;
	if(k > array[mid])
		return binary_search(array,k,mid+1,high);
	return binary_search(array,k,low,mid-1);
}