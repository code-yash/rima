#include<iostream>
#include<stdlib.h>
#include <stdio.h>    
using namespace std;
void Quicksort(int arr[],int f,int l);
int partition(int arr[],int f,int l);
int main()
{
	int n;
	cout<<"enter the the size of the array"<<endl;
	cin>>n;
	cout<<"enter the elements of the array"<<endl;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	Quicksort(arr,0,n-1);
	cout<<"the sorted array is:  ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	cout<<endl;	

	return 0;
}	


void Quicksort(int arr[],int f,int l)
{
	if(f<l)
	{
		int q=partition(arr,f,l);
		Quicksort(arr,f,q-1);
		Quicksort(arr,q+1,l);
	}
}



int partition(int arr[],int f,int l)
{
	int i=f-1;
	int j=f;
 	int r=rand()%l;
	cout<<"random number:"<<r<<"  "<<endl;
		int swap=arr[l];
		arr[l]=arr[r];
		arr[r]=swap;
	int x=arr[l];
	while(j<=l)
	{
		if(arr[j]<=x)
		{
			i=i+1;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		j=j+1;
	}
	return i;
}
		


