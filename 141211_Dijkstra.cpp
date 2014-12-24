#include <iostream>
#include <cstdlib>
#define MAX_NUM 6
using namespace std;

int arr[MAX_NUM][MAX_NUM]=
{
	{ 0,50,45,10, 0, 0},
	{ 0, 0,10,15, 0, 0},
	{ 0, 0, 0, 0,30, 0},
	{20, 0, 0, 0,15, 0},
	{ 0,20,35, 0, 0, 0},
	{ 0, 0, 0, 0, 3, 0}
};

void Less(int n, int w)//now node & now weight
{
	int store[MAX_NUM]={-1,-1,-1,-1,-1,-1}; //store[x] = y x = node, y = weight
	int min = 999;//min index;
	for(int i = 0; i<MAX_NUM; i++)
		if(arr[n][i]!=0)
			store[i] = w+arr[n][i];

	for(int i = 0; i<MAX_NUM; i++)
		if(store[i]!=-1)
		{
			min = i;
			break;
		}

	for(int i = 0; i<MAX_NUM; i++)
		if(store[i]!=-1 && store[min]>store[i])
			min = i;

	for(int i = 0; i<MAX_NUM; i++)
		arr[n][i] = 0;
	
	if(min==999)
		return;
	else
		cout<<n<<" ";
	Less(min, store[min]);
}

int main()
{
	Less(0,5);
}
