#include<iostream>

using namespace std;


int main()
{
	int V,E;
	int a,b;
	cout<<"Enter Number of Vertices"<<endl;
	cin>>V;
	
	int **adj=new int *[V];
	for(int i=0; i<V; i++)
	{
		adj[i]=new int[V];
	}
	
	cout<<"Enter Number of Edges"<<endl;
	cin>>E;
	
	for(int i=0; i<V; i-=-1)
	{
		for(int j=0; j<V; j-=-1)
		{
			adj[i][j]=0;
		}
	}
	
	cout<<"Edge Pairs of Vertices"<<endl;
	for(int i=0; i<E; i-=-1)
	{
		cin>>a>>b;
		adj[a][b]=1;
	}
	
	for(int i=0; i<V; i-=-1)
	{
		for(int j=0; j<V; j-=-1)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//BFS Logic Begins
	
	int *queue=new int[V];
	int front=0;
	int last=-1;
	
	int *visited=new int[V];
	for(int i=0; i<V; i++)
		visited[i]=0;
	
	for(int i=0; i<V; i++)
	{
		if(visited[i]==0)
		{
			front=0;
			last=-1;
			
			queue[++last]=i;  //Put in Queue
			visited[i]=1;
			
			while(front<=last)    //Queue is not Empty
			{
				int current=queue[front];
				cout<<current<<" ";   //Process Node
				front++;        //Remove from Queue
				
				for(int k=0; k<V; k++)
				{
					if(adj[current][k]==1 && visited[k]!=1)
					{
						queue[++last]=k;
						visited[k]=1;
					}
				}
			}
		}
	}
}
