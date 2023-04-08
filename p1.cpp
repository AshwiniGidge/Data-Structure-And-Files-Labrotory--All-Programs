/*
		Practical No 1:-
		Title: program to implement binary tree operations
		Name: Gidge Ashwini Shantaram
		Roll No: 74
*/

#include<iostream>
using namespace std;
struct node
{
	node *left;
	node *right;
	int data;
};
class btree
{
	node *root,*nn,*temp,*parent;
	public:
		btree()
		{
			root=NULL;
		}
		void create();
		void insert(node *,node *);
		void display();
		void inorder(node *);
		void leaf();
		void display_leaf(node *temp);
		void longestpath();
		int depth(node*);
};
void btree::create()
{
	nn=new node;
	nn->left=NULL;
	nn->right=NULL;
	cout<<"\n Enter the element:";
	cin>>nn->data;
	if(root==NULL)
	{
		root=nn;
	}
	else
	{
		insert(root,nn);
	}
	
}
void btree::insert(node *root,node *nn)
{
	char ch;
	cout<<"Where to insert left to right of "<<root->data<<":";
	cin>>ch;
	if(ch=='r' || ch=='R')
	{
		if(root->right==NULL)
		{
			root->right=nn;
		}
		else
		{
			insert(root->right,nn);
		}
	}
	else
	{
		if(root->left==NULL)
		{
			root->left=nn;
		}
		else
		{
			insert(root->left,nn);
		}
	}
}
void btree::display()
{
	if(root==NULL)
	{
		cout<<"\nTree is not created";
		
	}
	else
	{
		cout<<"\nTree is:";
		inorder(root);
	}
}
void btree::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<" "<<root->data<<" ";
		inorder(root->right);
	}
}
void btree::leaf()
{
	display_leaf(root);
}
void btree::display_leaf(node *temp)
{
	if(root==NULL)
	{
		cout<<"Tree is not created";
	}
	if(temp!=NULL)
	{
		if((temp->left==NULL) && (temp->right==NULL))
		cout<<" "<<temp->data;
		else
		{
			display_leaf(temp->left);
			display_leaf(temp->right);
		}
	}
}
void btree::longestpath()
{
	if(root==NULL)
	{
		cout<<"\nTree is empty";
	}
	else
	{
		int ldepth=depth(root);
		int rdepth=depth(root);
		if(ldepth>rdepth)
		{
			cout<<"\nDepth of tree is : "<<ldepth;
		}
		else
		{
			cout<<"\nDepth of tree is : "<<rdepth;
		}
	}
}
int btree::depth(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		int ldepth=depth(root->left);
		int rdepth=depth(root->right);
		if(ldepth>rdepth)
		{
			return(ldepth+1);
		}
		else
		{
			return(rdepth+1);
		}
	}
}
int main()
{
	btree b1;
	int ch,ans,ch1;
	do
	{
		cout<<"\n1.Create\n2.Display\n3.Display Leaf Nodes\n4.Depth of tree.";
		cout<<"\nEnter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1:
			do
			{
				b1.create();
				cout<<"Do you want to add new element then press 1 :"<<endl;
				cin>>ans;
			}while(ans==1);
			break;
			case 2:
				cout<<"Inorder"<<endl;
				b1.display();
				break;
			case 3:
				b1.leaf();
			 	break;
			case 4:
				b1.longestpath();
				break;	
		}
		cout<<"\nDo you want to press 1 : ";
		cin>>ch1;
	}while(ch1==1);
	return 0;
}
