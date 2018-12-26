#include<bits/stdc++.h>
using namespace std;

void quicksort(int * array, int low, int high);
int partition(int * array, int low, int high);
void swap(int &a, int &b);

int main()
{
	int n;
	cin>>n;
	int array[n];	
	for(int i=0;i<n;i++)
		array[i] = rand()%(2*n);

	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
	cout<<endl;	

	quicksort(array,0,n-1);

	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
	cout<<endl;

	return 0;
}

void quicksort(int * array, int low, int high)
{
	if(low > high)
		return ;
	int mid = partition(array,low,high);
	quicksort(array,low,mid-1);
	quicksort(array,mid+1,high);

}

int partition(int * array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;

	for(int j=low;j<high;j++)
	{
		if(array[j] <= pivot)
		{
			i++;
			swap(array[j],array[i]);
		}
	}

	swap(array[i+1],array[high]);
	return (i+1);
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	return ;
}