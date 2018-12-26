#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,sum;
	cin>>n>>sum;
	int array[n];
	for(int i=0;i<n;i++)
		array[i] = rand()%n;
	sort(array,array+n);
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	int left = 0;
	int right = n-1;

	while(left < right)
	{
		int s1 = array[left] + array[right];
		if(s1 == sum)
		{
			cout<<array[left]<<" "<<array[right]<<endl;
			left++;
		}
		else if(s1 < sum)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	cout<<endl;
}