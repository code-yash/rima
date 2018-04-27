#include<iostream>
using namespace std;
void counting(int arr[],int max,int n);
int main()
{
	int n,max;
	cout<<"enter the size of the array"<<endl;
	cin>>n;	
	cout<<"enter the maximum number of the array"<<endl;
	cin>>max;
	int arr[n];
	cout<<"enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	counting(arr,max,n);	

	return 0;
}



void counting(int arr[],int max,int n)
{

	int count[max+1]={0},C[n]={0};

	for(int i=0;i<n;i++)
	{
		count[arr[i]]++;
	}

	for(int i=1;i<max+1;i++)
	{
		count[i]=count[i-1]+count[i];
	}
	
	for(int i=n-1;i>=0;i--)
	{
		C[count[arr[i]]-1]=arr[i];
		count[arr[i]]=count[arr[i]]-1;
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<C[i]<<"   ";
	}
	cout<<endl;		
		
}		

		




	
