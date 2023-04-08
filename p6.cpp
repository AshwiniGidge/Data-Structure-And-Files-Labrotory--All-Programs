/*	Practical No 06 :- Hash Table implementation with chainng without replacement
	Name :- Gidge Ashwini S.
	Roll No :- 74
	Batch :- SY4
*/
	
#include<iostream>
using namespace std;
# define MAX 10
# define SIZE 10
# define FALSE 0
# define TRUE 1
struct hashtable
{
	int chain;
	long int key;
	char name;
}s[MAX];
class hasht
{
	public:
	int hash(int telno);
};
int hasht::hash(int telno)
{
	int h;
	h=telno%MAX;
	return h;
}
int main()
{
	int i,flag1=0,ch,ch1,no1,h,c,index,k,temp,ch3;
	int data[SIZE],flag[SIZE],chain[SIZE],j,x,op,loc;
	char sname;
	char name1[SIZE];
	hasht t;
	for(i=0;i<MAX;i++)
	{
		s[i].key=-1;
		s[i].chain=-1;
		s[i].name='_';
	}
	do
	{
		for(j=0;j<MAX;j++)
		{
			if(s[j].key==-1)
			break;
		}
		if(j==MAX)
		{
			cout<<"\n Hash table is full:";
			break;
		}
		cout<<"Enter the telephone number:";
		cin>>no1;
		cout<<"Enter the name:";
		cin>>sname;
		h=t.hash(no1);
		c=1;
		index=h;
		do
		{
			if(s[h].key==-1)
			{
				flag1=1;
				s[h].key=no1;
				s[h].name=sname;
				if(c!=-1)
					s[c].chain=h;
			}
			else if(t.hash(s[h].key)==index)
			c=h;
			h=t.hash(h+1);
		}while (flag1==0 && h<MAX);
		flag1=0;
		//cout<<"--------------------------------------------------------------";
		cout<<"\nIndex"<<"\t"<<"Telephone"<<"\t"<<"Name"<<"\t"<<"chain"<<"\n";
		for(i=0;i<MAX;i++)
		cout<<i<<"\t"<<s[i].key<<"\t"<<s[i].name<<"\t"<<s[i].chain<<"\n";
		cout<<"--------------------------------------------------------------";
		cout<<"\n Do you want to continue[0/1]:";
		cin>>ch;
	}while(ch==1);
	return 0;
}
