#include<iostream>
using namespace std;

void Merge(int arr[],int l,int m ,int r){
   int n1,n2;
   n1 = m-l+1;
   n2 = r-m;

   int L[n1],R[n2];
   int i,j,k;

   for(int i=0;i<n1;i++){

    L[i] = arr[l+i];

   }

   for(j=0;j<n2;j++){
    R[j] = arr[m+1+j];
   }

  i=0,j=0,k=l;
  while(i<n1 && j<n2){

    if(L[i]<= R[j]){
        arr[k] = L[i];
        i++;
    }
    else{
        arr[k] = R[j];
        j++;
    }
    k++;
 }
  while(i<n1){
    arr[k] = L[i] ;
    i++;
    k++;
  }
  while(j<n2){
    arr[k] = R[j];
    j++;
    k++;
  }

  }



void msort(int arr[],int n){
   int i;
   int l;
   for(i=1 ;i<n;i= 2*i){
      for(l=0;l<n-1;l+=2*i){
		cout<<l<<"laude lag gaye"<<endl;
         int mid =  l+i-1;
         int r = min(l +2*i -1,n-1);
         Merge(arr,l,mid,r);
       }
    }     
}

int main(){

int n;
 cout<<"enter the size of array"<<endl;
 cin>>n;
 int arr[n];
 
 cout<<"enter the elements of array "<<endl;
  for(int i=0;i<n;i++){
   
    cin>>arr[i];
  }
 msort(arr,n);
  cout<<"Sorted elements : ";
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
