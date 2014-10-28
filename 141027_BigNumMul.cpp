#include <iostream>
#include <cstdlib>
#include <sstream>
#define GET_NODE (node *)(malloc(sizeof(node)))
using namespace std;

typedef struct whole
{
	int num; //number
	int sqr; //square
	struct whole* ptr; // the pointer to next node
}node;

/**stringstream ss(temp);
		ss >> a[usedlength-i]**/
node *leader_a, *leader_b;
int alen, blen;
void init()
{		
	int length = 0;
	string astr, bstr, temp;
	node *NowNode, *PreNode;
	cout<<"Input first number : ";	cin>>astr;
	cout<<"Input second number : ";	cin>>bstr;
	alen = astr.length();	blen = bstr.length();
	for(int out = 0; out<2; out++)
	{
		if(out == 0)
			length = alen;
		else
			length = blen;
		for(int i = length-1; i>=0; i--) //sqr = length-1-i
		{
			if(out == 0)
				temp = astr.substr(i, 1);
			else
				temp = bstr.substr(i, 1);
			NowNode = GET_NODE;
			if(i == length-1)
			{
				if(out == 0)
					leader_a = NowNode;
				else
					leader_b = NowNode;
			}
			else if(i == 0)
				PreNode->ptr = NowNode;//NowNode->ptr = NULL;
			else
			{
				PreNode->ptr = NowNode;
			}
			PreNode = NowNode;
			stringstream ss(temp);
			ss >> (NowNode->num);
			NowNode->sqr = length-1-i;		
		}
	}	
}

void proc()
{
	int result_arr[alen+blen], tempnum, tempsqr;
	node *A_node, *B_node;
	A_node = leader_a;
	//clear
	for(int i = 0; i<(alen+blen); i++)
	{
		result_arr[i] = 0;
	}
	
	for(int a=0; a<alen; a++)
	{
		B_node = leader_b;
		for(int b=0; b<blen; b++)
		{
			tempnum = (A_node->num) * (B_node->num);
			tempsqr = (A_node->sqr) + (B_node->sqr);
			result_arr[tempsqr] += tempnum;
			B_node = B_node->ptr;
		}
		A_node = A_node->ptr;
	}
	int remainder, Q;//餘 && 商 
	for(int i = 0; i<alen+blen; i++)
	{
		if(result_arr[i]>=10)
		{
			Q = result_arr[i]/10;
			remainder = result_arr[i]-Q*10;
			result_arr[i] = remainder;
			result_arr[i+1] += Q;
		}
	}
	
	//Print --	
	cout<<"結果為 : "; 
	for(int i = alen+blen-1; i>=0; i--)
	{
		cout<<result_arr[i];
	}
	
	cout<<endl<<"==========================="<<endl;
}

int main()
{
	init();
	proc();
}
