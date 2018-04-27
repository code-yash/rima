#include<iostream>

using namespace std;

class node
{
     public:
       	int value;
       	node *parent;
       	char color;
       	node *left;
       	node *right;
};
class redblack
{
      	node *root;
      	node *q;
   public :
      	redblack()
      	{
              	q=NULL;
        	root=NULL;
      	}
      	void insert();`
      	void insertfix(node *);
      	void leftrotate(node *);
      	void rightrotate(node *);
     	void del();
      	node* successor(node *);
     	void deletefix(node *);
      	void disp();
      	void display( node *);
      	//void search();
};





void redblack::insert()
{
	int z,i=0;
	cout<<"Enter value of the node to be inserted: "<<endl;
	cin>>z;
	node *p,*q;
	node *t=new node;
	t->value=z;
	t->left=NULL;
	t->right=NULL;
	t->color='r';
	p=root;
	q=NULL;
	if(root==NULL)
	{
		root=t;
		t->parent=NULL;
	}
	else
	{
	 	while(p!=NULL)
		{
			q=p;
		      	if(p->value<t->value)
		        p=p->right;
		      	else
		        p=p->left;
		}
		t->parent=q;
		if(q->value<t->value)
		q->right=t;
		else
			q->left=t;
	}
	insertfix(t);
}






void redblack::insertfix(node *t)
{
     	node *u;
     	if(root==t)
     	{
         	t->color='b';
         	return;
     	}
     	while(t->parent!=NULL&&t->parent->color=='r')
     	{
           	node *g=t->parent->parent;
           	if(g->left==t->parent)
           	{
                        if(g->right!=NULL)
                        {
                              	u=g->right;
                              	if(u->color=='r')
                              	{
                                   	t->parent->color='b';
                                   	u->color='b';
                                   	g->color='r';
                                   	t=g;
                              	}
                        }
                        else
                        {
                            	if(t->parent->right==t)
                            	{
                                 	t=t->parent;
                                 	leftrotate(t);
                            	}
                            	t->parent->color='b';
                            	g->color='r';
                            	rightrotate(g);
                        }
           	}
           	else
           	{
                	if(g->left!=NULL)
                        {
                             	u=g->left;
                             	if(u->color=='r')
                             	{
                                  	t->parent->color='b';
                                  	u->color='b';
                                  	g->color='r';
                                  	t=g;
                             	}
                       	}
                        else
                        {
                            	if(t->parent->left==t)
                            	{
                                   	t=t->parent;
                                   	rightrotate(t);
                            	}
                            	t->parent->color='b';
                            	g->color='r';
                            	leftrotate(g);
                        }
           	}
           	root->color='b';
     	}
}






void redblack::del()
{
     	if(root==NULL)
     	{
           	cout<<"\nEmpty Tree." ;
           	return ;
     	}
     	int d;
     	cout<<"Enter the value of the node to be deleted: "<<endl;
     	cin>>d;
     	node *p;
     	p=root;
     	node *y=NULL;
     	node *q=NULL;
     	int found=0;
     	while(p!=NULL&&found==0)
     	{
           	if(p->value==d)
               		found=1;
           	if(found==0)
           	{
                 	if(p->value<d)
                    		p=p->right;
                 	else
                    		p=p->left;
           	}
     	}
     	if(found==0)
     	{
            	cout<<"Element Not Found."<<endl;
            	return ;
     	}
     	else
     	{
         	cout<<"Deleted Node: "<<p->value;
         	cout<<"  Colour: "<<p->color;
         	
         	if(p->parent!=NULL)
               		cout<<"  Parent: "<<p->parent->value;
         	else
               		cout<<"  No parent: ";

         	if(p->right!=NULL)
               		cout<<"  Right Child: "<<p->right->value;
         	else
               		cout<<"  No right child ";

         	if(p->left!=NULL)
               		cout<<"  Left Child: "<<p->left->value;
         	else
               		cout<<"  No left child ";
		cout<<endl;

         	cout<<"Node Deleted."<<endl;

         	if(p->left==NULL||p->right==NULL)
              		y=p;
         	else
              		y=successor(p);


         	if(y->left!=NULL)
              		q=y->left;
         	else
         	{
              		if(y->right!=NULL)
                   		q=y->right;
              		else
                   		q=NULL;
         	}
         	if(q!=NULL)
              		q->parent=y->parent;
         	if(y->parent==NULL)
              		root=q;
         	else
         	{
             		if(y==y->parent->left)
                		y->parent->left=q;
             		else
                		y->parent->right=q;
         	}
         	if(y!=p)
         	{
             		p->color=y->color;
             		p->value=y->value;
         	}
         	if(y->color=='b')
             	deletefix(q);
     	}
}





void redblack::deletefix(node *p)
{
    	node *s;
    	while(p!=root&&p->color=='b')
    	{
          	if(p->parent->left==p)
          	{
                  	s=p->parent->right;
                  	if(s->color=='r')
                  	{
                         	s->color='b';
                         	p->parent->color='r';
                         	leftrotate(p->parent);
                         	s=p->parent->right;
                  	}
                  	if(s->right->color=='b'&&s->left->color=='b')
                  	{
                         	s->color='r';
                         	p=p->parent;
                  	}
                  	else
                  	{
                      		if(s->right->color=='b')
                      		{
                             		s->left->color=='b';
                             		s->color='r';
                             		rightrotate(s);
                             		s=p->parent->right;
                      		}
                      		s->color=p->parent->color;
                      		p->parent->color='b';
                      		s->right->color='b';
                      		leftrotate(p->parent);
                      		p=root;
                  	}
          	}
          	else
          	{
                  	s=p->parent->left;
                  	if(s->color=='r')
                  	{
                        	s->color='b';
                        	p->parent->color='r';
                        	rightrotate(p->parent);
                        	s=p->parent->left;
                  	}
                  	if(s->left->color=='b'&&s->right->color=='b')
                  	{
                        	s->color='r';
                        	p=p->parent;
                  	}
                  	else
                  	{
                        	if(s->left->color=='b')
                        	{
                              		s->right->color='b';
                              		s->color='r';
                              		leftrotate(s);
                              		s=p->parent->left;
                        	}
                        	s->color=p->parent->color;
                        	p->parent->color='b';
                        	s->left->color='b';
                        	rightrotate(p->parent);
                        	p=root;
                  	}
          	}
       		p->color='b';
       		root->color='b';
    	}
}







void redblack::leftrotate(node *p)
{
     	if(p->right==NULL)
           	return ;

     	else
     	{
           	node *y=p->right;
           	if(y->left!=NULL)
           	{
                  	p->right=y->left;
                  	y->left->parent=p;
           	}
           	else
		{
                  	p->right=NULL;
		}


           	if(p->parent!=NULL)
                	y->parent=p->parent;


           	if(p->parent==NULL)
                	root=y;
           	else
           	{
               		if(p==p->parent->left)
                       		p->parent->left=y;
               		else
                       		p->parent->right=y;
           	}
           	y->left=p;
           	p->parent=y;
     	}
}






void redblack::rightrotate(node *p)
{
     	if(p->left==NULL)
          	return ;

     	else
     	{
         	node *y=p->left;
         	if(y->right!=NULL)
         	{
                  	p->left=y->right;
                  	y->right->parent=p;
         	}
         	else
                 	p->left=NULL;


         	if(p->parent!=NULL)
                 	y->parent=p->parent;


         	if(p->parent==NULL)
               		root=y;
         	else
         	{
             		if(p==p->parent->left)
                   		p->parent->left=y;
             		else
                   		p->parent->right=y;
         	}
         	y->right=p;
         	p->parent=y;
     	}
}




node* redblack::successor(node *p)
{
      	node *y=NULL;
     	if(p->left!=NULL)
     	{
         	y=p->left;
         	while(y->right!=NULL)
              		y=y->right;
     	}
     	else
     	{	
         	y=p->right;
         	while(y->left!=NULL)
              		y=y->left;
     	}
     	return y;
}





void redblack::disp()
{
     	display(root);
}
void redblack::display(node *p)
{
	if(root==NULL)
	{
		cout<<"\nEmpty Tree.";
		return ;
	}
	if(p!=NULL)
	{
        	cout<<"Node:"<<p->value<<"  color:"<<p->color;
   
                if(p->parent!=NULL)
                       cout<<"  Parent: "<<p->parent->value;
                else
                       cout<<"  no parent";
                if(p->right!=NULL)
                       cout<<"  Right Child:"<<p->right->value;
                else
                       cout<<"  No right child";
                if(p->left!=NULL)
                       cout<<"  Left Child:"<<p->left->value;
                else
                       cout<<"  No left child";
                cout<<endl<<endl;
		if(p->left)
		{
		     	display(p->left);
		}
		    
		if(p->right)
		{
			display(p->right);
		}
     	}
}








int main()
{
    int ch,y=0;
    redblack A;
    do
    {
                cout<<"***********RED BLACK TREE***********"<<endl;
                cout<<"1. Insert in the tree"<<endl;
                cout<<"2. Delete a node from the tree"<<endl;
                cout<<"3. Search for an element in the tree"<<endl;
                cout<<"4. Display the tree"<<endl;
                cout<<"5. Exit"<<endl;
                cout<<"Enter Your Choice: ";
                cin>>ch;
                switch(ch)
                {
                         case 1 : A.insert();
                         	cout<<"\nNode Inserted.\n";
                                break;

                         case 2 : A.del();
                           	break;

                         //case 3 : A.search();
                              	//break;
                         case 4 : A.disp();
                                break;

                         case 5 : y=1;
                                break;

                         default : 
				cout<<"Enter a Valid Choice."<<endl;
                }
                cout<<endl;

    }while(y!=1);
    return 1;
}
