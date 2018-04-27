#include<iostream>
using namespace std;
void recurinser(int arr[],int n);
int main()
{
	int n,countswap=0,countcomp=0;
	cout<<"enter the size of the array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	recurinser(arr,n);
	cout<<"the sorted array is : ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	cout<<"the no. of compare is : "<<countcomp<<endl;	
	cout<<"the no. of swap is : "<<countswap<<endl;	
	return 0;
	
}

void recurinser(int arr[],int n)
{
	int countswap,countcomp;
	if(n<=1)
		return;
	
	recurinser(arr,n-1);
	int last =arr[n-1];
	int j=n-2;
	while(j>=0 && arr[j]>last)
	{
		countswap++;
		countcomp++;
		arr[j+1]=arr[j];
		j--;
	}
	if(j!=0)
	{
		countcomp++;
	}
	arr[j+1]=last;
}


