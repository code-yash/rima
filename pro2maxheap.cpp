#include<iostream>
using namespace std;
void maxheapify(int arr[],int i,int n);
void buildmaxheap(int arr[],int n);

int main()
{
	int i,n;
	cout<<"enter the size of the array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter the elements of the array"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	buildmaxheap(arr,n);
	cout<<"the maxheap is:  "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	return 0;
}

void maxheapify(int arr[],int i,int n)
{
	int l,r,largest,temp;
	l=2*i+1;
	r=2*(i+1);
	if(l+1<=n && arr[l]>arr[i])
	{
		largest=l;
	}
	else
	{
		largest=i;
	}



	if(r+1<=n && arr[r]>arr[largest])
	{
		largest=r;
	}
	
	if(i!=largest)
	{
		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		maxheapify(arr,largest,n);
	}
		

}
	



void buildmaxheap(int arr[],int n)
{
	
	for(int i=(n/2)-1;i>=0;i--)
	{
		maxheapify(arr,i,n);
		
	}
}
	
	
