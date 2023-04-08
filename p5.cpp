/*	Program : Write a program to implement priority queue using heap data structure.
	Name : Gidge Ashwini S
	Roll No : 74
	Class : SY
*/

#include<iostream>
using namespace std;
int H[10];
int size=-1;
int parent(int i)
{
	return(i-1)/2;
}
int leftchild(int i)
{
	return((2*i)+1);
}
int rightchild(int i)
{
	return((2*i)+2);
}
void shiftUp(int i)
{
	while(i>0&&H[parent(i)]<H[i])
	{
		swap(H[parent(i)],H[i]);
		i=parent(i);
	}
}
void shiftDown(int i)
{
	int maxIndex=i;
	int l=leftchild(i);
	if(l<=size&&H[l]>H[maxIndex])
	{
		maxIndex=l;
	}
	int r=rightchild(i);
	if(r<=size&&H[l]>H[maxIndex])
	{
		maxIndex=r;
	}
	if(i!=maxIndex)
	{
		swap(H[i],H[maxIndex]);
		shiftDown(maxIndex);
	}
}
void insert(int p)
{
	size=size+1;
	H[size]=p;
	shiftUp(size);
}
int extractMax()
{
	int result=H[0];
	H[0]=H[size];
	size=size-1;
	shiftDown(0);
	return result;
}
void changePriority(int i,int p)
{
	int oldp=H[i];
	H[i]=p;
	if(p>oldp)
	{
		shiftUp(i);
	}
	else
	{
		shiftDown(i);
	}
}
int getMax()
{
	return H[0];
}
void remove(int i)
{
	H[i]=getMax()+1;
	shiftUp(i);
	extractMax();
}
	
int main()
{
	int n;
	cout<<"\n How many elements do you want to insert: ";
	cin>>n;
	cout<<"\n Enter elements: ";
	for(int i=1;i<=n;i++)
	{
		cin>>H[i];
		insert(i);
		
	}
	int i=0;
	cout<<"Priority Queue:"; 
	while(i<=size)
	{
		cout<<H[i]<<" ";
		i++;
	}
	cout<<"\nNode with maximum priority: "<<extractMax()<<"\n";
	cout<<"Priority Queue after extracting maximum: ";
	int j=0;
	while(j<=size)
	{
		cout<<H[j]<<" ";
		j++;
	}
	cout<<"\n";
	changePriority(2,49);
	cout<<"Priority Queue after priority change: ";
	int k=0;
	while(k<=size)
	{
		cout<<H[k]<<"\n";
		k++;
	}
	cout<<endl;
	remove(3);
	cout<<"Priority Queue after removing element: ";
	int l=0;
	while(l<=size)
	{
		cout<<H[l]<<" ";
		l++;
	}
	return 0;
}
