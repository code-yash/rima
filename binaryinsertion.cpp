#include<iostream>
using namespace std;

int binary(int arr[],int item,int low,int high){
	int mid;
	if(low<=high){
		
	   mid = (low+high)/2;
	
	
	
	if(item == arr[mid]){
		
		return mid;
		
		
   }
  else if(item> arr[mid]){
  	
  	
  	return binary(arr,item,mid+1,high);
  }
  
  else{
  	
  	
  	 return binary(arr,item,0,mid-1);
  }


}
	
}



void insertion(int arr[],int n){
	
	for(int i=1;i<n;i++){
	
	   int key  = arr[i];
	   int  j= i-1;
	      int loc  = binary(arr,key,0,j);
	while(j>= loc ){
		    
		   
		   arr[j+1] = arr[j];
           j--;
		
	}
	
	arr[j+1] = key;
}
	
}





int main(){
	
	int n;
	cout<<"enter the number of eleemts"<<endl;
	cin>>n;
	int arr[n];
	
	cout<<"enter the elements of array"<<endl;
	
	for(int i=0;i<n;i++){
		
		cin>>arr[i];
	}
	
	insertion(arr,n);
	
	cout<<"Sorted Array :"<<endl;
	
	for(int i=0;i<n;i++){
		
		cout<<arr[i]<< "  ";
	}
	
	
	return 0;
	
	
}
