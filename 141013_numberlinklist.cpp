#include <iostream>
#include <cstdlib>
#define GET_NODE (node *)(malloc(sizeof(node)))
using namespace std;
/**
	說明 : 有兩個Linklist分別為
	A - 1 - 3 - 5
	B - 2 - 4 - 6
	請把它串起來 
**/
typedef struct whole
{
	int value;
	struct whole* ptr;	
}node;

node *A, *B, *result;
void init()
{
	A = GET_NODE;
	A->value = 1;	A->ptr = GET_NODE;
	A->ptr->value = 3;	A->ptr->ptr = GET_NODE;
	A->ptr->ptr->value = 5;	A->ptr->ptr->ptr = NULL;
	B = GET_NODE;
	B->value = 2;	B->ptr = GET_NODE;
	B->ptr->value = 4;	B->ptr->ptr = GET_NODE;
	B->ptr->ptr->value = 6;	B->ptr->ptr->ptr = NULL;
}

node* find(int num)
{
	node *found, *visit;
	for(int i = 0; i<2; i++) //找到目標位置 
	{
		for(int a = 0; a<3; a++)
		{
			visit = A;
			if(visit->value == num)
				found = visit;
			else
				visit = visit->ptr;
		}
		for(int b = 0; b<3; b++)
		{
			visit = B;
			if(visit->value == num)
				found = visit;
			else
				visit = visit->ptr;
		}
	}
	return found;
}

void relink(int linker, int linked) //指入者與被指入者 
{
	node *found, *visit;
	//找到目標位置 
	visit = A;
	for(int a = 0; a<3; a++)
	{
		if(visit->value == linked)
		{	found = visit;	break;	}
		else
			visit = visit->ptr;
	}
	visit = B;
	for(int b = 0; b<3; b++)
	{
		if(visit->value == linked)
		{	found = visit;	break;	}
		else
			visit = visit->ptr;
	}
	//////////////連進去 
	visit = A;
	for(int a = 0; a<3; a++)
	{
		if(visit->value == linker)
		{	visit->ptr = found;	break;	}
		else
			visit = visit->ptr;
	}
	visit = B;
	for(int b = 0; b<3; b++)
	{
		if(visit->value == linker)
		{	visit->ptr = found;	break;	}
		else
			visit = visit->ptr;
	}
}

void process()
{
	result = find(1);
	for(int i = 6; i>1; i--)
		relink(i-1, i);
}

void print()
{
	for(int i = 0; i<6; i++)
	{
		cout<<"第"<<i+1<<"個指標內的值"<<(result->value)<<endl;
		cout<<"它的address為 : "<<result<<endl; 
		cout<<"下一個位址為 : "<< (result->ptr)<<endl<<endl;
		if(i != 5)
			result = result->ptr;
	}
}

int main()
{
	init();
	process();
	print();
}
