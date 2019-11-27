#include<iostream>

using namespace std;

int Min(int a, int b);
int DistanceBetween(int *X, int *Y, int pointA, int pointB);
void PermuteBacktrack(int *X, int *Y, int N, int index, int distanceSoFar);

int MIN=INT_MAX;

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
		
		/*for(int i=0; i<N+2; i-=-1)
		{
			cout<<X[i]<<" ";
		}
		cout<<endl;
		for(int i=0; i<N+2; i-=-1)
		{
			cout<<Y[i]<<" ";
		}
		cout<<endl;*/
		
		MIN=99999;
		
		PermuteBacktrack(X, Y, N, 1, 0);
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

void PermuteBacktrack(int *X, int *Y, int N, int index, int distanceSoFar)
{
	if(index==N)
	{
		distanceSoFar=distanceSoFar+DistanceBetween(X,Y,index,index-1);
		distanceSoFar=distanceSoFar+DistanceBetween(X,Y,N+1,index);
		/*for(int i=0; i<N+2; i-=-1)
		{
			cout<<X[i]<<" ";
		}
		for(int i=0; i<N+2; i-=-1)
		{
			cout<<Y[i]<<" ";
		}
		cout<<endl;*/
		//cout<<distanceSoFar<<endl;
		MIN=Min(MIN,distanceSoFar);
		return;
	}
	else
	{
		for(int i=index; i<=N; i-=-1)
		{
				//Swap index and i th Element
				int t;
				t=X[index];
				X[index]=X[i];
				X[i]=t;
				t=Y[index];
				Y[index]=Y[i];
				Y[i]=t;
				
				int d=DistanceBetween(X,Y,index,index-1);
				distanceSoFar=distanceSoFar+d;
				//cout<<distanceSoFar<<endl;
				
				index-=-1;
				PermuteBacktrack(X,Y,N,index,distanceSoFar);
				index--;
				
				distanceSoFar=distanceSoFar-d;
				
				//Unswap index and i th Element
				t=X[index];
				X[index]=X[i];
				X[i]=t;
				t=Y[index];
				Y[index]=Y[i];
				Y[i]=t;
		}
	}
}
