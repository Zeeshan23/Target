#include<iostream>

using namespace std;

int Min(int a, int b);
int DistanceBetween(int *X, int *Y, int pointA, int pointB);
bool IsAllVisited(int *visitedMatrice, int N);
void Backtrack(int *X, int *Y, int N, int distanceSoFar, int lastPointIndex, int *visitedMatrice);

int MIN=999990;

int main()
{
	int testCases;
	int N;
	cout<<"Enter Test Cases"<<endl;
	cin>>testCases;
	
	for(int t=0; t<testCases; t-=-1)
	{
		cout<<"Enter Number of Customers"<<endl;
		cin>>N;
		
		int *visited=new int[N+2];
		for(int i=0; i<N+2; i++)
		{
			visited[i]=0;
		}
		
		int *X=new int[N+2];
		int *Y=new int[N+2];
		
		cout<<"Enter Points"<<endl;
		for(int i=0; i<N+2; i-=-1)
		{
			cin>>X[i];
			cin>>Y[i];
		}
		
		//Just sending home point to last index
		int temp;
		temp=X[1];
		X[1]=X[N+1];
		X[N+1]=temp;
		temp=Y[1];
		Y[1]=Y[N+1];
		Y[N+1]=temp;
		
		MIN=99999;
		
		Backtrack(X, Y, N, 0, 0, visited);
		cout<<"Result="<<MIN;		
	}
	return 0;
}

int Min(int a, int b)
{
	if(a>=b)
		return b;
	else
		return a;
}

int DistanceBetween(int *X, int *Y, int pointA, int pointB)
{
	int Xa=X[pointA];
	int Ya=Y[pointA];
	int Xb=X[pointB];
	int Yb=Y[pointB];
	
	int diff1=Xa-Xb;
	int diff2=Ya-Yb;
	
	if(diff1<0)
		diff1=diff1*-1;
	if(diff2<0)
		diff2=diff2*-1;
		
	return (diff1+diff2);
}

bool IsAllVisited(int *visitedMatrice, int N)
{
	for(int i=0; i<N+1; i++)
	{
		if(visitedMatrice[i]==0)
			return false;
	}
	return true;
}

void Backtrack(int *X, int *Y, int N, int distanceSoFar, int lastPointIndex, int *visitedMatrice)
{
	if(IsAllVisited(visitedMatrice,N)==true)
	{
		distanceSoFar=distanceSoFar+DistanceBetween(X,Y,lastPointIndex,N+1);
		//cout<<distanceSoFar<<endl;
		//cout<<"Hi";
		visitedMatrice[N+1]=1;
		MIN=Min(MIN,distanceSoFar);
		return;
	}
	else
	{
		for(int i=1; i<N+1; i-=-1)
		{
			if(visitedMatrice[i]==0)
			{
				visitedMatrice[i]=1;
				distanceSoFar=distanceSoFar+DistanceBetween(X,Y,lastPointIndex,i);
				//cout<<distanceSoFar<<endl;
				Backtrack(X,Y,N,distanceSoFar,i,visitedMatrice);
				visitedMatrice[i]=0;
			}
		}
	}
}
