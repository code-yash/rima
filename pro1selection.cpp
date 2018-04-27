#include<iostream>
using namespace std;
int main()
{
	int key,i,j,temp,countswap=0,countcompare=0,n;
	cout<<"enter the size of the array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter the elements of the array"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<n-1;i++)
	{
		key=arr[i];
		for(j=i+1;j<n;j++)
		{
			if(key>arr[j])
			{
				temp=key;
				key=arr[j];
				arr[j]=temp;
				countswap++;
			}
			arr[i]=key;
			countcompare=countcompare+1;
		}
	}
	cout<<"sorted array is:  ";
	for(j=0;j<n;j++)
	{
		cout<<arr[j];
	}
	cout<<endl;
	cout<<"no. of swaps:  "<<countswap<<endl;
	cout<<"no. of compare:  "<<countcompare<<endl;
	return 0;
}	

