#include <iostream>
#include <cstdlib>
#define MAX 15
#define LC 20 //LifeCount
using namespace std;

int direct[8][2] = {{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};
int area[MAX][MAX] = {0};
int oarea[MAX][MAX] = {0};
int life[LC][2] = {
					{5,5},{5,6},
					{5,7},{6,5},
					{6,8},{8,4},
					{8,6},{9,5},
					{4,5},{4,6},
					{6,6},{10,2},
					{10,3},{11,4},
					{12,3},{2,13},
					{2,12},{13,13},
					{13,14},{13,12}
					};
 
void deal()
{
	for(int i = 0; i<MAX; i++)
		for(int j = 0; j<MAX; j++)
			oarea[i][j] = area[i][j];
	for(int i = 0; i<MAX; i++)
	{
		for(int j = 0; j<MAX; j++)
		{
			int count = 0;
			if(oarea[i][j]==1)
			{
				for(int k = 0; k<8; k++)
				{
					if((i+direct[k][0])>=0&&(i+direct[k][0])<MAX&&(j+direct[k][1])>0&&(j+direct[k][1])<MAX)
						if(oarea[i+direct[k][0]][j+direct[k][1]] == 1)
							count++;
				}
				if(count==2||count==3)
					area[i][j]=1;
				else
					area[i][j]=0;
			}
			else if(oarea[i][j]==0)
			{
				for(int k = 0; k<8; k++)
				{
					if((i+direct[k][0])>=0&&(i+direct[k][0])<MAX&&(j+direct[k][1])>0&&(j+direct[k][1])<MAX)
						if(oarea[i+direct[k][0]][j+direct[k][1]] == 1)
							count++;
				}	
				if(count==3)
					area[i][j]=1;
				else
					area[i][j]=0;
			}
			
		}
	}
}

void init()
{
	for(int i = 0; i<LC; i++)
	{
		oarea[life[i][0]][life[i][1]] = 1;
		area[life[i][0]][life[i][1]] = 1;
	}
}

void print()
{
	for(int i = 0; i<MAX; i++)
	{
		for(int j = 0; j<MAX; j++)
		{
			if(area[i][j]==0)
			{
				//―ー
				cout<<"ー";
			}
			else
			{
				cout<<"―";
			}
		}
		cout<<endl;
	}
}

int main()
{
	init();
	print();
	system("pause");
	system("cls");
	for(int i = 0; i<30; i++)
	{
		deal();
		print();
		system("pause");
		system("cls");
	}
} 
