#include <iostream>
#include <cstdlib>
using namespace std;

int A[3][3]=
{
	{1, 2, 3},
	{3, 2, 1},
	{0, 1,-1}
};
int B[3][3]=
{
	{ 2, 3, 4},
	{-1,-2, 0},
	{ 0, 1, 1}
};
int C[3][3]=
{
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

void init()
{
	for(int c=0; c<2; c++)
	{
		if(c==0)
			cout<<"= = = A = = ="<<endl;
		else
			cout<<"= = = B = = ="<<endl;
		for(int i = 0; i<3; i++)
		{
			for(int j = 0; j<3; j++)
			{
				if(c==0)
					printf("%3d",A[i][j]);
				else
					printf("%3d",B[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			for(int k = 0; k<3; k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
}

void print()
{
	cout<<"= = = C = = ="<<endl;
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			printf("%3d", C[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	init();
	print();
}
