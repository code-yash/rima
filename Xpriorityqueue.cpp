#include<iostream>
#include<cstdlib>
using namespace std;
void increasekey(int arr[],int i,int key,int heapsize);
void insert(int arr[],int key,int heapsize);
void buildmaxheap(int arr[],int heapsize);
void maxheapify(int arr[],int i,int heapsize);
void print(int arr[],int heapsize);
void dequeue(int arr[],int heapsize);
int main()
{
	int n;
	cout<<"enter the size of the array"<<endl;
	cin>>n;
	int heapsize=n;
	int arr[n];
	cout<<"enter the elements of the array"<<endl;
	for(int j=0;j<n;j++)
	{
		cin>>arr[j];
	}
        buildmaxheap(arr,n);
	do
	{
		cout<<"**********select your choice*********"<<endl;
		cout<<"1.Increase the priority of a particular node"<<endl;
		cout<<"2.Insert the elements in queue"<<endl;
		cout<<"3.print the queue elements"<<endl;
		cout<<"4.delete the highest priority element"<<endl;
		cout<<"5.exit"<<endl;
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1:
			  cout<<"enter the position of the node:"<<endl;
			  int pos;
			  cin>>pos;
			  cout<<"enter the new priority of that node:"<<endl;
			  int pt;
			  cin>>pt;
			  increasekey(arr,pos,pt,heapsize);
	                  //buildmaxheap(arr,n);
			  //print(arr,heapsize);
			  break;
			
			case 2:	
			  cout<<"enter the element:"<<endl;
			  int key;
			  cin>>key;
			  insert(arr,key,heapsize);
			  heapsize++;
			  break;	
		
			case 3:
	                  buildmaxheap(arr,heapsize);
			  //print(arr,heapsize);
			  break;
				
			case 4:	
			  dequeue(arr,heapsize);
			  heapsize--;
			  break;
		
			case 5:
			  exit(0);
		}

		
	}
	while(true);
	return 0;	
}

void insert(int arr[],int key,int heapsize)
{
	arr[heapsize]=-100;
	heapsize=heapsize+1;
	increasekey(arr,heapsize,key,heapsize);
	
}


void increasekey(int arr[],int i,int key,int heapsize)
{
 	if(arr[i-1]<key)
	{
		arr[i-1]=key;
		while(i/2>=1)
		{
			if(arr[i-1]>arr[(i/2)-1])
			{
				int temp=arr[i-1];
				arr[i-1]=arr[(i/2)-1];
				arr[(i/2)-1]=temp;
				

			}
			i=i/2;

		}

	}

	//buildmaxheap(arr,heapsize);
	print(arr,heapsize);
}





void maxheapify(int arr[],int i,int heapsize)
{
	int l,r,largest,temp;
	l=2*i+1;
	r=2*(i+1);
	if(l+1<=heapsize && arr[l]>arr[i])
	{
		largest=l;
	}
	else
	{
		largest=i;
	}



	if(r+1<=heapsize && arr[r]>arr[largest])
	{
		largest=r;
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
	print(arr,heapsize);
	
}
	
void print(int arr[],int heapsize)
{
	cout<<"now the queue is:  ";
	for(int i=0;i<heapsize;i++)
	{
		cout<<arr[i]<<"   ";
	}
	cout<<endl;
}


void dequeue(int arr[],int heapsize)
{
	
	int max=arr[0];
	arr[0]=arr[heapsize-1];
	arr[heapsize-1]=max;
	cout<<max<<endl;
	heapsize=heapsize-1;
	
	for(int i=(heapsize/2)-1;i>=0;i--)
	{
		maxheapify(arr,i,heapsize);

		
	}

	cout<<"now the maxheap is:  ";
	for(int i=0;i<heapsize;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	
	
}
	
	
