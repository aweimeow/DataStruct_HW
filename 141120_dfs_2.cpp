#include <iostream>
#include <cstdlib>
#include <string.h>
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
string temp;
int count = 0;
bool visited[7] = {false};

void dfs(int v)
{
	if(!visited[v])
	{
		temp+=v+'0';
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

string clearcom(string temp)
{
	string correct="";
	bool comma = false;
	string now;
	for(int i = 0; i<temp.length(); i++)
	{
		now = temp.substr(i,1);
		if(now=="0"||now=="1"||now=="2"||now=="3"||now=="4"||now=="5"||
			now=="6"||now=="7"||now=="8"||now=="9")
		{
			comma = false;
			correct += now;
		}
		else
		{
			if(!comma)
			{
				correct += now;
				count++;
			}
			comma = true;
		}
	}
	return correct;
}

void init()
{
	temp="";
	for(int i = 0; i<7; i++)
	{
		dfs(i);
		temp+=",";
	}
}

int main()
{
	init();
	cout<<"temp = "<<clearcom(temp);
	cout<<"count = "<<count;
}
