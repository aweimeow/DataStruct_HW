#include <iostream>
#include <cstdlib>
#define GET_NODE (node*)(malloc(sizeof(node)))
using namespace std;

int arr[16];
int count = 0; 
void deal()
{
	int index = count;
	bool isright = false;
	cout<<"Now Index = "<<index<<endl;
	cout<<"arr[index/2] = "<<arr[index/2]<<endl;
	cout<<"arr[index] = "<<arr[index]<<endl;
	isright = arr[index/2]>arr[index];
	cout<<isright;
	while(isright)
	{
		if(index/2==0)
		{
			break;
		}
		else
		{
			int temp;
			temp = arr[index/2];
			arr[index/2] = arr[index];
			arr[index] = temp;
			index = index/2;
			isright = arr[index/2]>arr[index];
			cout<<"isright = "<<isright;
		}
	}
}	

void insert()
{
	int input;
	cout<<"Please input insert number : ";
	cin>>input;
	count++;
	arr[count] = input;
	deal();
}

void del()
{
	if(count==0)
	{
		cout<<"No node to del !";
	}
	else
	{
		arr[count] = 0;
		count--;
	}
}

void print()
{
	cout<<"Array is : ";
	for(int i = 1; i<=count; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void init()
{
	char chose;
	cout<<"select your chose(I=insert/D=Delete/P=Print/Else=exit) : ";
	cin>>chose;
	if(chose=='I'||chose=='i')
	{
		insert();
		init();
	}
	else if(chose=='D'||chose=='d')
	{
		del();
		init();
	}
	else if(chose=='P'||chose=='p')
	{
		print();
		init();
	}
	else
	{
		cout<<"Program END ! ";
	}
}

int main()
{
	init();
}
