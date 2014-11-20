#include <iostream>
#include <cstdlib>
using namespace std;

int arr[7][7]={
		{0,1,1,0,0,0,0},
		{1,0,0,0,0,0,0},
		{1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1},
		{0,0,0,0,0,1,0},
		{0,0,0,0,1,0,0},
		{0,0,0,1,0,0,0}
		};

bool visited[7] = {false};

void dfs(int v)
{
	if(!visited[v])
	{
		cout<<v;
	}
	visited[v] = true;
	for(int w = 0; w<7; w++)
	{
		if(arr[v][w]==1)
		{
			if(!visited[w])
			{
				dfs(w);
			}
		}
	}
}

void init()
{
	for(int i = 0; i<7; i++)
	{
		dfs(i);
		cout<<endl;
	}
}

int main()
{
	init();
}
