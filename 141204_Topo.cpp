#include <iostream>
#include <cstdlib>
using namespace std;

int arr[16][16]=
{//vMain >Who linked 
   //0  1 2 3 4 5  6 7 8 9 0  1 2 3 4 5
	{-1, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0}, //0
	{-1, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0}, //1
	{-1, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0}, //2
	{-1, 1,1,0,0,0, 0,0,0,0,0, 0,0,0,0,0}, //3
	{-1, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0}, //4
	
	{-1, 0,0,0,1,0, 0,0,0,0,0, 0,0,0,0,0}, //5
	{-1, 0,0,0,0,1, 0,0,0,0,0, 0,0,0,0,0}, //6
	{-1, 0,0,1,0,0, 1,0,0,0,0, 0,0,0,0,0}, //7
	{-1, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0}, //8
	{-1, 0,0,0,0,0, 0,1,1,0,0, 0,0,0,0,0}, //9
	
	{-1, 0,0,0,0,0, 0,1,0,0,0, 0,0,0,0,0}, //10
	{-1, 0,0,0,0,0, 0,0,0,0,1, 0,0,0,0,0}, //11
	{-1, 0,0,0,0,0, 0,1,0,0,0, 0,0,0,0,0}, //12
	{-1, 0,0,0,0,0, 0,1,0,0,0, 0,0,0,0,0}, //13
	{-1, 0,0,0,0,0, 0,0,0,0,0, 0,0,1,0,0}, //14
	
	{-1, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0} //15
};

int linknum[16]={0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,0};
int save[16]={0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,0};
void T_O()
{
	int s = 0;
	//count how many link to point
	for(int i = 1; i<16; i++)
	{
		for(int j = 1; j<16; j++)
		{
			if(arr[i][j]==1)
			{
				linknum[i]++;
			}
		}
	}
	
	/**cout<<"==============linknum=============="<<endl;
	for(int i = 0; i<16; i++)
		cout<<linknum[i]<<" ";**/
	cout<<endl<<"========================================"<<endl;
	for(int i = 0; i<16; i++)
	{
		for(int j = 0; j<16; j++)
		{
			printf("%3d",arr[i][j]);
		}
		cout<<endl;
	}
	cout<<"========================================"<<endl<<endl;
	
	for(int i = 1; i<16; i++)
	{
		if(linknum[i] == 0)
		{
			cout<<i<<" ";
			save[i] = 1;
			for(int j = 0; j<16; j++)
			{
				arr[i][j] = -1;
				arr[j][i] = -1;
			} 
			break;
		}
	}
	
	for(int i = 0; i<16; i++)
	{
		if(save[i] == 1)
			linknum[i] = -1;
		else
			linknum[i] = 0;
	}
}

int main()
{
	for(int i = 0; i<15; i++)
		T_O();
} 
