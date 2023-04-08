/*                           
                              PRACTICAL NO.3
                               Title:: Write a program in c++ to implement Kruskals Algorithm to find minimum cost spanning Tree.
                                NAME :: Dhamone Siddhesh Dipak
                                 ROLL NO.: 19
                                  BATCH:: S1
                                   SUBJECT::DSFL
*/







#include<iostream>
using namespace std;
int visited[10]; 
class graph
{
int i,j,min,u,v,mincost,cost[10][10],edgs,a,b,n;
public:
graph()
{
edgs=1;
mincost=0;
}
void kruskal(int cost[10][10],int n);
void read();
};
void graph::read()
{
	cout<<"\n Enter the number of vertices::"; 
	cin>>n; 
	cout<<"\n Enter the weight of edges in the form of adjecency matrix::"; 
	
	for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
{
	cin>>cost[i][j];
	if(cost[i][j]==0)
	cost[i][j]=9999;
}
}
kruskal(cost,n);
}
void graph::kruskal(int cost[10][10],int n)
{
	while(edgs<n)
{
	min=9999;
	for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
{ 
	if(cost[i][j]<min)
{ 
	min=cost[i][j];
	a=u=i; b=v=j;
}
}
}
	while(visited[u])
	u=visited[u];
	while(visited[v])
	v=visited[v]; if(u!=v)
{
	edgs++; 
	cout<<"\n EDGES:"<<a<<"->"<<b<<"\tWeight:"<<min<<"\n";
	mincost=mincost+min; visited[v]=u;
}
cost[a][b]=cost[b][a]=9999;
}
	cout<<"\n MINIMUM COST="<<mincost<<"\n";
}
int main(void)
{
	graph g;
	g.read();
	return 0;
}









/*

Enter the number of vertices::7

 Enter the weight of edges in the form of adjecency matrix::0
28
0
0
0
10
0
28
0
16
0
0
0
14
0
16
0
12
0
0
0
0
0
12
0
22
0
18
0
0
0
22
0
25
24
10
0
0
0
25
0
0
0
14
0
18
24
0
0

 EDGES:1->6	Weight:10

 EDGES:3->4	Weight:12

 EDGES:2->7	Weight:14

 EDGES:2->3	Weight:16

 EDGES:4->5	Weight:22

 EDGES:5->6	Weight:25

 MINIMUM COST=99
*/

