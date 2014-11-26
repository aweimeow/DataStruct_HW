#include <iostream>
#include <cstdlib>
using namespace std;

int res[7][7]={
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	};
int line[42][3]={
	{0,0,0},{0,0,0},{0,0,0},
	{0,0,0},{0,0,0},{0,0,0}
	};
int arr[7][7]={
		{0 , 28, 0 , 0 , 0 , 10, 0 },
		{28, 0 , 16, 0 , 0 , 0 , 14},
		{0 , 16, 0 , 12, 0 , 0 , 0 },
		{0 , 0 , 12, 0 , 22, 0 , 18},
		{0 , 0 , 0 , 22, 0 , 25, 24},
		{10, 0 , 0 , 0 , 25, 0 , 0 },
		{0 , 14, 0 , 18, 24, 0 , 0 }
	};
bool visited[7] = {false};
bool found = false;
int min_in_arr, max_in_arr, linecount=0;
template<typename T, size_t M, size_t N>
void getline(T (&arr)[M][N])
{
	int max=NULL, min=NULL;
	int temp[3];
	for(int i = 0; i<M; i++)	//find min value && max value
	{
		for(int j = 0; j<N; j++)
		{
			if(max==NULL&&arr[i][j]!=0)
				max = arr[i][j];
			if(min==NULL&&arr[i][j]!=0)
				min = arr[i][j];
			if(max!=NULL&&max<arr[i][j])
				max = arr[i][j];
			if(min!=NULL&&min<arr[i][j])
				min = arr[i][j];
		}
	}
	min_in_arr = min;	max_in_arr = max;
	for(int i = 0; i<M; i++)	//find all linked line
	{
		for(int j = 0; j<N; j++)
		{
			if(i==j||i>j)
				continue;
			if(arr[i][j]!=0)
			{
				line[linecount][0] = i;	//Link point 1
				line[linecount][1] = j;	//Link point 2
				line[linecount][2] = arr[i][j];	//weight value
				linecount++;
			}
		}
	}
	for(int i = 0; i<linecount; i++)	//Bubble sorting
	{
		for(int j = i; j<linecount; j++)
		{
			if(line[j][2]<line[i][2])
			{
				for(int k = 0; k<3; k++)
				{
					temp[k] = line[j][k];
					line[j][k] = line[i][k];
					line[i][k] = temp[k];
				}
			}
		}
	} 
}

void dfs(int s, int e)
{
	if(s==e)
	{
		found = true;
	}
	if(found)
	{
		return;
	}
	visited[s] = true;
	for(int w = 0; w<7; w++)
	{
		if(res[s][w]!=0)
		{
			if(!visited[w])
			{
				dfs(w,e);
				if(found)
					break;
			}
		}
	}
}

bool islinked(int s, int e)
{
	for(int i = 0; i<7; i++)
		visited[i]=false;
	found = false;
	dfs(s,e);
	if(found == true)
		return true;
	else
		return false;
}

void core()
{
	for(int i = 0; i<linecount; i++)
	{
		if(!islinked(line[i][0],line[i][1]))
		{
			res[line[i][0]][line[i][1]]=line[i][2];
			res[line[i][1]][line[i][0]]=line[i][2];
		}
	}
}

int main()
{
	getline(arr);
	for(int i = 0; i<linecount; i++)
	{
		for(int j = 0; j<3; j++)
		{
			cout<<"line["<<i<<"]["<<j<<"]="<<line[i][j]<<"  ";
		} 
		cout<<endl;
	}
	core();
	cout<<"ARR=============="<<endl;
	for(int i = 0; i<7; i++)
	{
		for(int j = 0; j<7; j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"RESULT=============="<<endl;
	for(int i = 0; i<7; i++)
	{
		for(int j = 0; j<7; j++)
		{
			cout<<res[i][j]<<"\t";
		}
		cout<<endl;
	}
}
