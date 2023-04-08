
/*	Practical No 7 :- Program to implement Threaded Binary Tree
	Name:- Gidge Ashwini S
	Roll no :- 74
	Batch :- S4
*/
#include<iostream>
#include<cstdlib>
#define MAX_VALUE 65536
using namespace std;
class node
{
	public:
		int key;
		node *left, *right;
		bool lthread,rthread;
	
};
class TBST
{
	private:
		node *root;
	public:
		TBST()
		{
			root=new node();
			root->right = root->left=root;
			root->lthread=true;
			root->key= MAX_VALUE;
		}
		void insert(int key)
		{
			node *p=root;
			for(;;)
			{
				if(p->key < key)
				{
					if(p->rthread)
						break;
					p=p->right;
				}
				else if(p->key > key)
				{
					if(p ->lthread)
						break;
					p = p->left;
				}
				
				else
				{
					return;
				}
			}
			node *tmp = new node;
			tmp->key = key;
			tmp->rthread = tmp->lthread = true;
			
			if(p->key < key)
			{
				tmp->right = p->right;
				tmp->left=p;
				p->right=tmp;
				p->rthread = false;
			}
			else
			{
				tmp->right =p;
				tmp->left = p->left;
				p->left =tmp;
				p->lthread = false;
			}
		}
		void display()
		{
			node *tmp = root,*p;
			for(;;)
			{
				p = tmp;
				tmp = tmp->right;
				
				if(!p->rthread)
				{
					while(!tmp->lthread)
					{
						tmp = tmp->left;
					}
				}
				
				if(tmp == root)
				{
					break;
				}
				cout<<tmp->key<<"  ";
			}
			cout<<endl;
		}
		bool search(int key)
		{
			node *tmp=root->left;
			for(;;)
			{
				if(tmp->key < key)
				{
					if(tmp->rthread)
						return false;
					tmp= tmp->right;
				}
				else if(tmp->lthread)
				{
					if(tmp->lthread)
					{
						return false;
					}
					tmp = tmp->left;
				}
				else
				{
					return true;
				}
			}
		}
		void deletet(int key)
		{
			node *dest=root->left, *p=root;
			for(;;)
			{
				if(dest->key<key)
				{
					if(dest->rthread)
					return;
					p=dest;
					dest=dest->right;
				}
				else if(dest->key>key)
				{
					if(dest->lthread)
					return;
					p=dest;
					dest=dest->left;
				}
				else
				{
					break;
				}
			}
			node *target=dest;
			if(!dest->rthread && !dest->lthread)
			{
				p=dest;
				target=dest->left;
				while(!target->rthread)
				{
					p=target;
					target=target->right;
				}
				if(p->key>=target->key)
				{
					if(target->rthread && target->lthread)
					{
						p->left=target->left;
						p->lthread=true;
					}
					else if(target->rthread)
					{
						node *largest=target->left;
						while(!largest->rthread)
						{
							largest=largest->right;
						}
						largest->right=p;
						p->left=target->left;
					}
					else
					{
						node *smallest=target->right;
						while(!smallest->lthread)
						{
							smallest=smallest->left;
						}
						smallest->left=target->left;
						p->left=target->right;
					}
				}
				else
				{
					if(target->rthread && target->lthread)
					{
						p->right=target->right;
						p->rthread=true;
					}
					else if(target->rthread)
					{
						node *largest=target->left;
						while(!largest->rthread)
						{
							largest=largest->right;
						}
						largest->right=target->right;
						p->right=target->left;
					}
					else
					{
						node *smallest=target->right;
						while(!smallest->lthread)
						{
							smallest=smallest->left;
						}
						smallest->left=p;
						p->right=target->right;
					}
				}
			}
		}
							
};
int main()
{
	int val,k,z,g;
	TBST t;
	do
	{
		cout<<"\nWhich operation do you want to perform";
		cout<<"\n\t 1.Insert \n\t 2.Display \n\t 3.Search \n\t 4.Delete";
		cin>>k;
		switch(k)
		{
			case 1:
				cout<<"\nEnter a Value you want to insert:";
				cin>>val;
				t.insert(val);		
			break;
			case 2:
				t.display();
			break;
			case 3:
				cout<<"\n Enter Key you want to search:";
				cin>>val;
				if(t.search(val) == true)
				{
					cout<<"\nKey"<<val<<"is found";
				}
				else
				{
					cout<<"\nKey"<<val<<"is not found";	
				}
			break;
			case 4:
				cout<<"\nEnter Key you want to delete:";
				cin>>val;
				t.deletet(val);
				cout<<"After delete operation";
				t.display();
			break;
		}
		cout<<"\nDo you want to contineu\n\t 1.YES 2.NO";
		cin>>z;	
	}while(z!=2);
	return 0;

}
