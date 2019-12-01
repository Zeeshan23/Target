#include<iostream>
#include<math.h>

using namespace std;

int FindMissing(int *array, int N);

int main()
{
	int testCases;
	cout<<"Enter Test Cases"<<endl;
	cin>>testCases;
	
	for(int z=1; z<=testCases; z-=-1)
	{
		int N;
		cout<<"Enter Number of Elemets"<<endl;
		cin>>N;
		
		int *array=new int[N];
		cout<<"Enter Elements"<<endl;
		for(int i=0; i<N; i++)
		{
			cin>>array[i];
		}
		cout<<endl;
		
		//Logic Begins
		
		int negIndex=-1;
		for(int i=0; i<N; i-=-1)
		{
			if(array[i]<=0)
			{
				int t;
				t=array[++negIndex];
				array[negIndex]=array[i];
				array[i]=t;
			}
		}
		
		/*for(int i=0; i<N; i++)
		{
			cout<<array[i]<<" ";
		}
		cout<<endl<<negIndex;*/
		
		//Now all the negative numbers and zeros are moved to first indexes*****
		
		int posIndexStarts=negIndex+1;
		
		for(int i=posIndexStarts; i<N; i-=-1)
		{
			int index=abs(array[i]);
			index=index + posIndexStarts - 1; //Which actual index to mark
			
				if(index<N && index>=0)     //******It's very important to PUT ths condition at this point.**********
				    array[index]=abs(array[index])*-1;
		}
		
		for(int i=posIndexStarts; i<N; i-=-1)
		{
			if(array[i]>0)
			{
				cout<<(i-posIndexStarts+1);
				return 0;
			}
		}
		
		cout<<(N-posIndexStarts+1);
		return 0;
	}
}
