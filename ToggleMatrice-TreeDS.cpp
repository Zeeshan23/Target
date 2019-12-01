#include<iostream>

using namespace std;

struct node
{
	int index;
	struct node *left;
	struct node *right;
};

int Max(int a, int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

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
		
		struct node *root=new struct node;
		root->index=-1;
		root->left=NULL;
		root->right=NULL;
		
		int *hash=new int[20];
		for(int i=0; i<20; i++)
		{
			hash[i]=0;
		}
		int ind=0;
		
		for(int i=0; i<r; i-=-1)
		{
			int countZeros=0;
			struct node *p=root;
			for(int j=0; j<c; j-=-1)
			{
				if( j == (c-1) )    //Row ke Last Element ka case
				{
					if(matrice[i][j]==0)    //left
					{
						countZeros++;
						if(p->left!=NULL)   //matlab aisa pehle se hai
						{
							p=p->left;
							if( (k-countZeros)%2==0 && k>=countZeros )
							{
								hash[p->index]++;
							}
						}
						else    //matlab aisa pehle se nhi hai
						{
							struct node *newNode=new struct node;
							newNode->index=ind++;
							newNode->left=NULL;
							newNode->right=NULL;
							
							p->left=newNode;
							p=p->left;
							
							if( (k-countZeros)%2==0 && k>=countZeros )
							{
								hash[p->index]++;
							}
						}
					}
					else if(matrice[i][j]==1)    //right
					{
						if(p->right!=NULL)   //matlab aisa pehle se hai
						{
							p=p->right;
							if( (k-countZeros)%2==0 && k>=countZeros )
							{
								hash[p->index]++;      //pointing key ke value ko increment
							}
						}
						else    //matlab aisa pehle se nhi hai
						{
							struct node *newNode=new struct node;
							newNode->index=ind++;      //naya hash key dega is naye TYPE of row ko. 
							newNode->left=NULL;
							newNode->right=NULL;
							
							p->right=newNode;
							p=p->right;
							
							if( (k-countZeros)%2==0 && k>=countZeros )
							{
								hash[p->index]++;     //pointing key ke value ko increment
							}
						}
					}
				}
				else     //Jab Row ka last element nhi hoga tab
				{
					if(matrice[i][j]==0)  //left jaana hai
					{
						countZeros++;
						if(p->left!=NULL)  //left mein pehle se hai
						{
							p=p->left;
						}
						else     //Left mein pehle se nhi hai
						{
							struct node *newNode=new struct node;
							newNode->index=-1;
							newNode->left=NULL;
							newNode->right=NULL;
							
							p->left=newNode;
							p=p->left;
						}
					}
					else if(matrice[i][j]==1)  //Right jaana hai
					{
						if(p->right!=NULL)  //Rightt mein pehle se hai
						{
							p=p->right;
						}
						else     //Right mein pehle se nhi hai
						{
							struct node *newNode=new struct node;
							newNode->index=-1;
							newNode->left=NULL;
							newNode->right=NULL;
							
							p->right=newNode;
							p=p->right;
						}
					}
				}
			}
		}
		
		int max=0;
		for(int i=0; i<20; i++)
		{
			max=Max(hash[i],max);
		}
		
		cout<<max;
	}
	
	return 0;
}
