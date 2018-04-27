#include<iostream>
#include<cstdlib>
using namespace std;
template<class T>
class node
{
	public:
	T key;
	node<T> *left,*right,*parent;
	node(T k, node<T> *l = NULL,node<T> *r = NULL,node<T> *p=NULL)
   	{   
      		key = k;
      		left = NULL;
      		right = NULL;
		parent=NULL;

   	}
};



template<class T>
class tree
{
      private: 
     
     	node<T> *root;
     	node<T> *q;
      public:
     	tree()
	{
         	root=NULL;
         	q=NULL;
	}
      	void insertion();
     	void insertfix(node<T> *);
     	void leftrotate(node<T> *);
     	void rightrotate(node<T> *);
     	node<T>* successor(node<T> *);
	void disp();
     
};

