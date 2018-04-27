#include<iostream>
#include<cstdlib>
using namespace std;
template<class T>
class node{
  public:
     T info;
     node<T> *next,*prev;
    node(T e){
         info = e;
         next = NULL;
         prev = NULL; 
    }
  };
template<class T>
class List{
    private:
      node<T> *head;
      node<T> *tail;
	int count;
    public:
      List(){
           head = NULL;
           tail = NULL;
     }

   
   
   void addTotail(T num);
   void sorting();
   void print();
    
   } ;


template<class T>
 void List<T> ::  addTotail(T num){

	count++;
      if(head == NULL){
       node<T> *temp = new node<T>(num);
          tail= head = temp;
              }
  else{
      node<T>  *temp = new node<T>(num);
        tail->next = temp;
        temp->prev = tail;
          tail = temp;
       
    }
      
 }


template<class T>
   void List<T> :: print(){
     node<T> *ptr = head;
          while(ptr != NULL){
            cout<<ptr->info<<" ";
             ptr = ptr->next;      
             }
    } 


template<class T>
 void List<T> ::  sorting()
{
	int count;
	node<T> *first=head;
	node<T> *second=head;
	second=second->next;
	while(second!=NULL)
	{
		first=head;
		while(first!=second)
		{
			if(first->info>second->info)
			{
				int temp=first->info;
				first->info=second->info;
				second->info=temp;
			}
			else
			{
				first=first->next;
			}
		}
		second=second->next;
	}

			
}






int main(){
   List<int> L;
  int choice,data,pos;
  do{
     cout<<"\n\na*******************Menu********************"<<endl;

     cout<<" 1.insert data"<<endl;
     cout<<" 2.sort elements"<<endl;
     cout<<" 3.Print the list"<<endl;
     cout<<" 4.exit"<<endl;
     
     cout<<"\n\n Enter your choice:";
     cin>>choice;
     switch(choice){
        
       case 1:
            cout<<"\n Enter data:";
            cin>>data; 
            L.addTotail(data);
            L.print(); 
            
            break;
      
      case 2:
          cout<<"\n the sorted elements is :"<<endl;
          L.sorting ();
          L.print();
          break;
    case 3: 
        L.print();
         break;
    case 4: exit(0);
   
      
   }
 }while(true);

   return 0;
}

