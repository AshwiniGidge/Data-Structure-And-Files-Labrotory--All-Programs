//Practical No:- Non-recursive
//Name:- Ashwini Gidge
//Roll No:- 74
//Class:- S.Y.IT
#include <iostream>
#include<stack>
#include<cstring>
using namespace std;
struct node
{
    int data;
    node *left, *right;
};
class BT
{
    node *nn, *root, *temp, *ptr, *parent,*stk[30];
    int top,d,max;
	public:
    BT()
    {
        root = NULL;
		top = -1;
    }
	
    int isempty();
    int isfull();
    void push(node*);
    node*pop();

    void create();
    void insert(node *, node *);

    void inorder(node *);
    void preorder(node*);
    void postorder(node*);

    void display_in();
    void display_pre();
    void display_post();
  
   
    void NR_inorder(node*);
    void NR_preorder(node*);
    void NR_postorder(node*);    
};
void BT::create()
{
    nn = new node;
    nn->left = NULL;
    nn->right = NULL;
    cout << "Enter the Node:";
    cin >> nn->data;

    if (root == NULL)
    {
        root = nn;
    }
    else
    {
        insert(root, nn);
    }
}
void BT::insert(node *root, node *nn)
{
    char ch;
    cout << "Where you want to insert the Node: l/L or r/R-";
    cin >> ch;
    if (ch == 'l' || ch == 'L')
    {
        if (root->left == NULL)
        {
            root->left = nn;
        }
        else
        {
            insert(root->left, nn);
        }
        cout << "Node is added to the Left....." << endl;
    }
    else if (ch == 'r' || ch == 'R')
    {
        if (root->right == NULL)
        {
            root->right = nn;
        }
        else
        {
            insert(root->right, nn);
        }
        cout << "Node is added to the Right....." << endl;
    }
}
int BT :: isempty()
{
	if(top == -1)
	{
	    return 1;
        return 0;              		
	}
}
int BT :: isfull()
{
	if(top == 29)
	{
	     return 1;
    	 return 0;
    }
}
void BT :: push(node *d)
{
	if(!isfull())
	{
	    stk[++top] = d;
	}
}
node *BT :: pop()
{
       node*temp = stk[top];
       top--;
       return temp;
}
void BT::display_in()
{
    if (root == NULL)
    {
        cout << "Root is not created:";
    }
    else
    {
        cout << "The Inorder tree is:";
        inorder(root);
        NR_inorder(root);
    }
}
void BT::display_pre()
{
    if (root == NULL)
    {
        cout << "Root is not created:";
    }
    else
    {
        cout << "The Preorder tree is:";
        preorder(root);
		NR_preorder(root);
    }
}
void BT::display_post()
{
    if (root == NULL)
    {
        cout << "Root is not created:";
    }
    else
    {
        cout << "The Postorder tree is:";
        postorder(root);
    }
}
void BT::inorder(node*ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout << "\t" << ptr->data;
        inorder(ptr->right);
    }
}
void BT::preorder(node*ptr)
{
	  if (ptr != NULL)
    {
	 cout << "\t" << ptr->data;
        preorder(ptr->left);
        preorder(ptr->right);
    }	
}
void BT::postorder(node*ptr)
{
	 if (ptr != NULL)
    {
        preorder(ptr->left);
        preorder(ptr->right);
		cout << "\t" << ptr->data;
    }	
}
void BT ::  NR_inorder(node*root)
{
     BT s;
     while(!s.isempty() || root!=NULL)
      {
          while(root!=NULL)
           {
              s.push(root);   
              root = root->left;
           }
          root = s.pop();
          cout<<"  "<<root->data<<"  ";
          root = root->right;
       }
}
void BT ::  NR_preorder(node*root)
{
     BT s;
     while(!s.isempty() || root!=NULL)
      {
          while(root!=NULL)
           {
	      		cout<<"  "<<root->data<<"  ";
                s.push(root);   
                root = root->left;
           }
          root = s.pop();
          root = root->right;
       }
}
void BT:: NR_postorder(node*root)
{
    BT s;
    int i=0;
    int str[50];
      while(!s.isempty() || root!=NULL)
      {
          while(root!=NULL)
           {
	      str[i++] = root -> data;
          s.push(root);   
          root = root->right;
           }
          root = s.pop();
          root = root->left;
       }
       for(i=max-1; i>=0; i--)
	   {
	    	cout<<"%s",str[i];
       }	
}
int main()
{
    BT o;
    int ch1, ch2, ans;
    cout << "BINARY TREE OPERATIONS" << endl;
    do
    {
        cout << "\nWhich operation do you want to perform on tree:\n\n1.CREATE\n2.INORDER\n3.PREORDER\n4.POSTORDER\n5.NR_INORDEER\n6.NR_PREORDER\n7.NR_POSTORDER ";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
            do
            {
                o.create();
                cout << "Do you want to add more elements: 1.Y\t2.N ";
                cin >> ans;
            } while (ans == 1);
            break;

        case 2:
            cout << "Inorder Traversal: " << endl;
            o.display_in();
            break;

        
        case 3:
          	cout << "Preorder Traversal: " << endl;
          	  o.display_pre();
            break;
	
	case 4:
		cout << "Postorder Traversal: " << endl;
          	  o.display_post();
            break;
        
          	  
	case 5:
              cout<<"non recursive traversal:  "<<endl;
              o.display_in();
	}
        cout << "\n--------------------------------------------------------------" << endl;
        cout << "\n\nDo u want to continue-1.Y \t 2.N";
        cin >> ch2;
    } while (ch2 != 2);
    return 0;
}



