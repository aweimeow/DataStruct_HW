#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
char HT[150][20]={0};
static int b = 150; //array count
static char a = 'a'; //first char
int sTime = 0;
char *names[100] = {"Jacob","Mason","William","Jayden","Noah","Michael","Ethan","Alexander","Aiden","Daniel","Anthony","Matthew","Elijah","Joshua","Liam","Andrew","James","David","Benjamin","Logan","Christopher","Joseph","Jackson","Gabriel","Ryan","Samuel","John","Nathan","Lucas","Christian","Jonathan","Caleb","Dylan","Landon","Isaac","Gavin","Brayden","Tyler","Luke","Evan","Carter","Nicholas","Isaiah","Owen","Jack","Jordan","Brandon","Wyatt","Julian","Aaron","Sophia","Isabella","Emma","Olivia","Ava","Emily","Abigail","Madison","Mia","Chloe","Elizabeth","Ella","Addison","Natalie","Lily","Grace","Samantha","Avery","Sofia","Aubrey","Brooklyn","Lillian","Victoria","Evelyn","Hannah","Alexis","Charlotte","Zoey","Leah","Amelia","Zoe","Hailey","Layla","Gabriella","Nevaeh","Kaylee","Alyssa","Anna","Sarah","Allison","Savannah","Ashley","Audrey","Taylor","Brianna","Aaliyah","Riley","Camila","Khloe","Claire"};

int calc(char c)
{
	return 97+(c-'a');
}

void deal(char* input)
{
	int index = 0, oindex = 0, count = 1;
	int len = strlen(input);
	for(int i = 0; i<len; i++)
		index += calc(input[i]);
	index%=b;
	oindex = index;
	//////////////////////////////////////
	while(HT[index][0]!=0)
	{
		sTime++;
		index = oindex+(count*count);
		count++;
		if(index>=b)
			index%=b;
	}
	sTime++;
	for(int i = 0; i<strlen(input); i++)
		HT[index][i] = input[i];
	/**
	cout<<"=============================="<<endl;
	cout<<"oindex = "<<oindex<<endl;
	cout<<"index = "<<index<<endl;
	cout<<"=============================="<<endl;
	for(int i = 0; i<100; i++)
	{
		cout<<"HT["<<i<<"] = "<<HT[i]<<endl;
	}
	system("pause");
	**/
}

void print()
{
	for(int i = 0; i<150; i++)
	{
		cout<<"HT["<<i<<"] = "<<HT[i]<<endl;
	}
	cout<<"Average Time : "<<(sTime/100.0);
}

int main()
{
	for(int i = 0; i<100; i++)
	{
		deal(names[i]);
	}
	print();	
}
