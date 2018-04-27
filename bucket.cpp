#include<iostream>
using namespace std;

void bucket_sort(int arr[],int n){

    
int i,j,k;

int count[10];
for( i=0;i<10;i++){

    count[i] = 0;
 
 }

for(i=0;i<n;i++){
 
    (count[arr[i]])++;

}

for(i=0,j=0;j<10;j++){

    for(k = count[j] ;k>0;k--){

       arr[i++] = j;

     }
 }

}


  
int main(){

      int n;
     cout<<"enter the size of array "<<endl;
        
     cin>>n;


     int arr[n];


     cout<<"enter the elements of array "<<endl;
      for(int i=0;i<n;i++){

         cin>>arr[i];


      }
 

 

      
bucket_sort(arr,n);


  cout<<"Sorted array :";
  
 
 for(int i=0;i<n;i++){

      cout<<arr[i]<<"  ";

   }

  return 0;

} 
