#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
int HT[200] = {0};
int sTime = 0;
static int b=200;
char *names[100] = {"Jacob","Mason","William","Jayden","Noah","Michael","Ethan","Alexander","Aiden","Daniel","Anthony","Matthew","Elijah","Joshua","Liam","Andrew","James","David","Benjamin","Logan","Christopher","Joseph","Jackson","Gabriel","Ryan","Samuel","John","Nathan","Lucas","Christian","Jonathan","Caleb","Dylan","Landon","Isaac","Gavin","Brayden","Tyler","Luke","Evan","Carter","Nicholas","Isaiah","Owen","Jack","Jordan","Brandon","Wyatt","Julian","Aaron","Sophia","Isabella","Emma","Olivia","Ava","Emily","Abigail","Madison","Mia","Chloe","Elizabeth","Ella","Addison","Natalie","Lily","Grace","Samantha","Avery","Sofia","Aubrey","Brooklyn","Lillian","Victoria","Evelyn","Hannah","Alexis","Charlotte","Zoey","Leah","Amelia","Zoe","Hailey","Layla","Gabriella","Nevaeh","Kaylee","Alyssa","Anna","Sarah","Allison","Savannah","Ashley","Audrey","Taylor","Brianna","Aaliyah","Riley","Camila","Khloe","Claire"};

int calc(char c)
{
	return 97+(c-'a');
}

int stage(int a) // ¶¥¼h 3 = 1+2+3 = 6 
{
	int sum = 1;
	if(a>1)
	{
		for(int i = 1; i<=a; i++)
			sum*=i;
		return sum;
	}
	else if(a==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void deal(char* input)
{
	int index = 0;
	int len = strlen(input);
	for(int i = 0; i<len; i++)
		index += calc(input[i]);
	index%=b;
	HT[index]++;
}

void print()
{
	for(int i = 0; i<200; i++)
	{
		sTime+=stage(HT[i]);
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
