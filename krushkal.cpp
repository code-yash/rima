#include<iostream>  
#include <algorithm>

using namespace std;
class Edge{
	
	
	 public:
	 	
	 	 int source;
	 	 int dest;
	 	 int weight;
};

bool compare(Edge e1,Edge e2){
	
	 return e1.weight < e2.weight;
}

int findparent(int v , int *parent){
	
	  if(parent[v] == v){
	  	
	  	return v;
	  	
	  }
	  
	return findparent(parent[v],parent);  
}

void Kruskals(Edge *input,int n,int E){
	
	//sort array ascending order
	sort(input,input+E,compare);
	Edge *output = new Edge[n-1];
	
	int *parent = new int[n];
	
	for(int i=0;i<n;i++){
		
		parent[i] = i;
		
		  
	}
	
	int count = 0;
	int i=0;
	while(count != n-1){
		
		Edge currentegdes = input[i];
		int sourceparent = findparent(currentegdes.source,parent);
		int destparent = findparent(currentegdes.dest,parent);
		
		
		if(sourceparent != destparent){
			
			  output[count] = currentegdes;
			  count++;
			  parent[sourceparent] = destparent;
		}
		
	i++;	
	}
	
	
	
	for(int i=0;i<n-1;i++){
		
		
		  if(output[i].source < output[i].dest){
		  	
		  	cout<<output[i].source << "  "<<output[i].dest<<"  "<<output[i].weight<<endl;
		  	   
		  }
		  
		  else{
		  	
		  		cout<<output[i].dest << "  "<<output[i].source<<"  "<<output[i].weight<<endl;
		  	  
		  }
	}
	
	  
}



int main()
{
	
	 int n,E;
	 
	 cout<<"enter the number of vertices"<<endl;
	 cin>>n;
	 cout<<"enter the number of Edges"<<endl;
	 cin>>E; 
	
	Edge *input  = new Edge[E];
	
	for(int i=0;i<E;i++){
		int s,d,w;
		cin>>s>>d>>w;
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	
     Kruskals(input,n,E);
	
	return 0;
}



