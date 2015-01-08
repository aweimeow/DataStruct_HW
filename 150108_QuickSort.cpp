#include <iostream>
#include <cstdlib>
#define MAX 7
using namespace std;

void swap(int data[], int i, int j)
{
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void QuickSort(int data[], int left, int right)
{
	if(left<right)
	{
		int i = left, j = right+1;
		while(true)
		{
			while((i+1)<MAX && data[++i]<data[left]);
			while((j-1)>-1 && data[--j]>data[left]);
			if(i>=j)
				break;
			swap(data, i, j);
		}
		swap(data, left, j);
		QuickSort(data, left, j-1);
		QuickSort(data, j+1, right); 
	} 
	
}

int main()
{
	int input[MAX];
	cout<<"¿é¤J"<<MAX<<"µ§¸ê®Æ : ";
	for(int i = 0; i<MAX; i++)
		cin>>input[i];
	QuickSort(input, 0, MAX-1);
	
	for(int i = 0; i<MAX; i++)
	{
		printf("%3d", input[i]);
	}
} 
