#include<iostream>
using namespace std;
int main()
{
	int temp,countswap=0,countcompare=0,n;
	cout<<"enter the size of array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<n-1;i++)
	{
		int j=i+1;
		
		while(arr[j-1]>arr[j] && j>0)
		{
			temp=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=temp;
			
			countswap++;
			countcompare=countcompare+1;
			j--;	
		}
		if(j!=0)
		{
		countcompare=countcompare+1;
		}
		
	}

	cout<<"sorted array is: ";
	for(int j=0;j<n;j++)
	{
		cout<<arr[j]<<"  ";
	}
	cout<<endl;
	cout<<"no. of swaps: "<<countswap<<endl;
	cout<<"no. of compare: "<<countcompare<<endl;
	return 0;
}

	

	
