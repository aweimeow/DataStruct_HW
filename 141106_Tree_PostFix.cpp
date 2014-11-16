#include <iostream>
#include <cstdlib>
#include <stack>
#define GET_NODE (node*)(malloc(sizeof(node)))

using namespace std;

typedef struct whole
{
	char value;
	struct whole* L_child;
	struct whole* R_child;
}node;

node root;
char str[100];
stack<char> num;
int str_index = 0;
void init()
{
	root.value = '+';
	root.L_child = GET_NODE;	root.R_child = GET_NODE;
	root.L_child->value = '-';	root.R_child->value = '*';
	root.L_child->L_child = GET_NODE;
	root.L_child->R_child = GET_NODE;
	root.L_child->L_child->value = '/';
	root.L_child->R_child->value = '3';
	root.L_child->R_child->L_child = NULL;
	root.L_child->R_child->R_child = NULL;
	root.L_child->L_child->L_child = GET_NODE;
	root.L_child->L_child->R_child = GET_NODE;
	root.L_child->L_child->L_child->value = '6';
	root.L_child->L_child->L_child->L_child = NULL;
	root.L_child->L_child->L_child->R_child = NULL;
	root.L_child->L_child->R_child->value = '2';
	root.L_child->L_child->R_child->L_child = NULL;
	root.L_child->L_child->R_child->R_child = NULL;
	root.R_child->L_child = GET_NODE;
	root.R_child->R_child = GET_NODE;
	root.R_child->L_child->value = '4';
	root.R_child->L_child->L_child = NULL;
	root.R_child->L_child->R_child = NULL;
	root.R_child->R_child->value = '2';
	root.R_child->R_child->L_child = NULL;
	root.R_child->R_child->R_child = NULL;
}


void pushstack(node *ptr)
{
	if(ptr)
	{
		pushstack(ptr->L_child);
		pushstack(ptr->R_child);
		str[str_index] = ptr->value;
		cout<<ptr->value;
		str_index++;
	}
}

void create_str()
{
	cout<<"Post-Fix : ";
	pushstack(&root);
	cout<<endl;
}

void calc()
{
	int num1, num2;
	for(int i = 0; i<str_index; i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			num.push(str[i]);
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			num2 = num.top()-'0';	num.pop();
			num1 = num.top()-'0';	num.pop();
			switch(str[i])
			{
				case '+':
					num.push(num1+num2+'0');
					break;
				case '-':
					num.push(num1-num2+'0');
					break;
				case '*':
					num.push(num1*num2+'0');
					break;
				case '/':
					num.push(num1/num2+'0');
					break;
				default:
					cout<<"Error";
			}
		}
	}
	cout<<"The Answer is : "<<num.top();
}

int main()
{
	init();
	create_str();
	calc();
	
}
