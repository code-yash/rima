#include<iostream>
using namespace std;

class prisms{
	
	private:
		
		   int no_of_edges,no_of_nodes;
		   int graph[10][10],mindist[10],visited[10];
    public:
    	
    	 void input();
    	 void spanningtree();
    	 void output();
    	 
    	 prisms(){
    	 	
    	 	
    	 	    no_of_edges = no_of_nodes = 0;
    	 	    for(int i=0;i<10;i++){
    	 	    	     visited[i] = mindist[i] = 0; 
    	 	    	   for(int j=0;j<10;j++){
    	 	    	   	
    	 	    	   	    graph[i][j] = 0;
    	 	    	   	    
    	 	    	   	        
						}
				 }
		 }
	
	
	 
};

void prisms :: input(){
	
	
	    int vertex1,vertex2,cost;
	    
	    cout<<"enter the number of nodes\n";
	    cin>>  no_of_nodes;
	    cout<<"enter the number of edges\n";
	    cin>>  no_of_edges;
	    
	    for(int i=0;i<no_of_edges;i++){
	    	
	    	cout<<"Enter the first vertex";
	    	cin>>vertex1;
	    	cout<<"Enter the Second vertex";
	    	cin>>vertex2;
	    	
	    	cout<<"Enter the cost of "<<vertex1<<"and"<<vertex2<<" ";
	    	cin>>cost;
	    	cout<<endl;
	    	
	    	graph[vertex1][vertex2] = graph[vertex2][vertex1] = cost;
	    }
	    	
}
	    


void prisms :: spanningtree(){
	
	int min = 9999 ,row,col,index = 0;
	
	for(int i=0;i<no_of_nodes;i++){
		for(int j=i;j<no_of_nodes;j++){
			
			if(graph[i][j]<min && graph[i][j] != 0){
				
				min = graph[i][j];
				row = i;
				col = j;
			}
		}
	}
	
	
	
	visited[row] = visited[col] = 1;
	 mindist[index++] = min ;
	 
	 
	 	for(int i=0;i<no_of_nodes-2;i++){
	 		min = 9999;
		for(int j=0;j<no_of_nodes;j++){
			
			if(visited[j] == 1){
			  
			  for(int k=0 ;k<no_of_nodes;k++){
			  
			
			   if(graph[j][k]<min && graph[j][k] != 0 &&  visited[k] == 0){
				
				min = graph[j][k];
				row = j;
				col = k;
			}
		}
	  }
	  
    }
    
    mindist[index++] =  min;
    visited[row] = 1;
    visited[col] = 1;
}


 int total =0;
   cout<<"Minimal spanning list:";
   
   for(int i=0 ; i< no_of_nodes -1;i++){
   	
   	
   	   cout<<"  " <<mindist[i]<<" "; 
   	   
   	   total += mindist[i];
   	    
   	   
   }	 
	
	  cout<<"Total  path cost :"<<total<<endl;   
}

void prisms :: output(){
	
	
	for(int i=0;i<no_of_nodes;i++){
		
		cout<<endl;
		for(int j=0;j<no_of_nodes;j++){
			
			     cout.width(4);
			     cout<<graph[i][j];
			     
		}
		
	}
}


int main()
{
	
   prisms obj;
   obj.input();
   obj.output();
   obj.spanningtree();
   
   return 0;
}


