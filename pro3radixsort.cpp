#include<iostream>
using namespace std;
int findmax(int arr[],int n);
void radixsort(int arr[],int n);
void counting(int arr[],int exp,int n);
int main()
{
	int n;
	cout<<"enter the size of the array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter the elements of the array(in three digit)"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	radixsort(arr,n);	

	return 0;
}

	int findmax(int arr[],int n)
	{
		int max=arr[0];
		for(int i=1;i<n;i++)
		{
			if(arr[i]>max)
			{
				max=arr[i];
			}
		}
		return max;
	}			
	

	
	void radixsort(int arr[],int n)
	{
		int exp;
		int max=findmax(arr,n);
		for(exp=1;max/exp>0;exp=exp*10)
		{
			counting(arr,exp,n);
		}
	}
	




	void counting(int arr[],int exp,int n)
	{
		int result[n+1]={0},count[10]={0};
		for(int i=0;i<n;i++)
		{
			count[(arr[i]/exp)%10]++;
		}
		for(int i=1;i<10;i++)
		{
			count[i]=count[i-1]+count[i];
		}
		
		for(int i=n-1;i>=0;i--)
		{
			result[count[(arr[i]/exp)%10]-1]=arr[i];
			count[(arr[i]/exp)%10]--;
		}
		
		for(int i=0;i<n;i++)
		{
			arr[i]=result[i];
			cout<<arr[i]<<"   ";
		}
		cout<<endl;
	}	

	
