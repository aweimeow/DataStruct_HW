#include <iostream>
#include <cstdlib>
using namespace std;

int G[4][4]=
{
	{0,1,0,0},
	{0,0,0,1},
	{0,0,0,0},
	{0,1,1,0}
};

int G_2[4][4]=
{
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
};

int G_3[4][4]=
{
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
};

void init()
{
	for(int C = 0; C<2; C++)
		for(int i = 0; i<4; i++)
			for(int j = 0; j<4; j++)
				for(int k = 0; k<4; k++)
				{
					if(C==0)
						G_2[i][j]+=G[i][k]*G[k][j];
					else
						G_3[i][j]+=G_2[i][k]*G[k][j];
				}
	for(int C = 0; C<3; C++)
	{
		if(C==0)
			cout<<"= = =  G  = = ="<<endl;
		else if(C==1)
			cout<<"= = = G_2 = = ="<<endl;
		else
			cout<<"= = = G_3 = = ="<<endl;
		for(int i = 0; i<4; i++)
		{
			for(int j = 0; j<4; j++)
			{
				if(C==0)
					printf("%2d", G[i][j]);
				else if(C==1)
					printf("%2d", G_2[i][j]);
				else
					printf("%2d", G_3[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void calc()
{
	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			G[i][j]=G[i][j]||(G_2[i][j]||G_3[i][j]);
		}
	}
}

void printGplus()
{
	cout<<"= = =  G+  = = ="<<endl;
	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			printf("%2d", G[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	init();
	calc();
	printGplus();
}
