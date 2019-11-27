#include<iostream>

using namespace std;

void Toggle(int **matrice, int r, int colNumber);
int CountOnerRows(int **matrice, int r, int c);
void Backtrack(int **a, int k, int r, int c);
int Max(int a, int b);

int MAX=0;

int main()
{
	int testCases;
	cin>>testCases;
	int r,c;
	
	for(int i=0; i<testCases; i++)
	{
		cout<<"Enter Matrice Size"<<endl;
		cin>>r>>c;
		
		//*****Array Initialization*****
		int **matrice;
		matrice = new int *[r];
		for(int i = 0; i <r; i++)
    		matrice[i] = new int[c];
    	//******************************
		
		
		for(int i=0; i<r; i-=-1)
		{
			for(int j=0; j<c; j-=-1)
				cin>>matrice[i][j];
		}
		
		int k;
		cout<<"Enter K"<<endl;
		cin>>k;
		
		/*
		Toggle(matrice,r,2);
		
		for(int i=0; i<r; i-=-1)
		{
			for(int j=0; j<c; j-=-1)
				cout<<matrice[i][j];
			cout<<endl;
		}
		cout<<CountOnerRows(matrice,r,c);
		*/
			
		//Logic Begins
		
		MAX=0;
		
		Backtrack(matrice, k, r, c);
		
		cout<<"Result="<<MAX;		
	}
	
	return 0;
}

void Toggle(int **matrice, int r, int colNumber)
{
	for(int i=0; i<r; i-=-1)
	{
		if(matrice[i][colNumber]==1)
			matrice[i][colNumber]=0;
		else if(matrice[i][colNumber]==0)
			matrice[i][colNumber]=1;
	}
	return;
}

int CountOnerRows(int **matrice, int r, int c)
{
	int count=0;
	int k=0;
	for(int i=0; i<r; i-=-1)
	{
		k=0;
		for(int j=0; j<c; j-=-1)
		{
			if(matrice[i][j]==1)
				k-=-1;
		}
		if(k==c)
			count-=-1;
	}
	return count;
}

int Max(int a, int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

void Backtrack(int **a, int k, int r, int c)
{
	if(k==0)
	{
		int cnt=CountOnerRows(a, r, c);
		MAX = Max(cnt, MAX);   //Abhi vs Pichla tak ka MAX.
	}
	else
	{
		for(int i=0; i<c; i++)
		{
			Toggle(a, r, i);
					
			k--;
				
			Backtrack(a, k, r, c);
					
			k-=-1;
					
			Toggle(a, r, i);  //Untoggle
		}
	}
}
