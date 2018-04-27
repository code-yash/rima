#include<iostream>
using namespace std;
void maxheapify(int arr[],int i,int heapsize);
void buildmaxheap(int arr[],int heapsize);
void heapsort(int arr[],int n);

int main()
{
	int count=0;
	int i,n;
	cout<<"enter the size of the array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter the elements of the array"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	heapsort(arr,n);
	cout<<"the sorted value is:  "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	//cout<<count;
	return 0;
}

void maxheapify(int arr[],int i,int heapsize)
{
	int count;
	int l,r,largest,temp;
	l=2*i+1;
	r=2*(i+1);
	if(l+1<=heapsize && arr[l]>arr[i])
	{
		largest=l;
		count++;
	}
	else
	{
		largest=i;
		count++;
	}



	if(r+1<=heapsize && arr[r]>arr[largest])
	{
		largest=r;
		count++;
	}
	
	if(i!=largest)
	{
		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		maxheapify(arr,largest,heapsize);
	}
		

}
	



void buildmaxheap(int arr[],int heapsize)
{
	
	for(int i=(heapsize/2)-1;i>=0;i--)
	{
		maxheapify(arr,i,heapsize);
		
	}
	
	
}
void heapsort(int arr[],int n)
{
	int key;
	int heapsize=n;
	for(int i=n-1;i>=1;i--)
	{
		buildmaxheap(arr,heapsize);
		key=arr[i];
		arr[i]=arr[0];
		arr[0]=key;
		heapsize=heapsize-1;
	}
}
	
