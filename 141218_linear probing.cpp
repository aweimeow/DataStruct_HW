#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
static int b = 100; //array count
static char a = 'a'; //first char
char HT[100][20]={0};
int sTime = 0;
char *names[100] = {"Jacob","Mason","William","Jayden","Noah","Michael","Ethan","Alexander","Aiden","Daniel","Anthony","Matthew","Elijah","Joshua","Liam","Andrew","James","David","Benjamin","Logan","Christopher","Joseph","Jackson","Gabriel","Ryan","Samuel","John","Nathan","Lucas","Christian","Jonathan","Caleb","Dylan","Landon","Isaac","Gavin","Brayden","Tyler","Luke","Evan","Carter","Nicholas","Isaiah","Owen","Jack","Jordan","Brandon","Wyatt","Julian","Aaron","Sophia","Isabella","Emma","Olivia","Ava","Emily","Abigail","Madison","Mia","Chloe","Elizabeth","Ella","Addison","Natalie","Lily","Grace","Samantha","Avery","Sofia","Aubrey","Brooklyn","Lillian","Victoria","Evelyn","Hannah","Alexis","Charlotte","Zoey","Leah","Amelia","Zoe","Hailey","Layla","Gabriella","Nevaeh","Kaylee","Alyssa","Anna","Sarah","Allison","Savannah","Ashley","Audrey","Taylor","Brianna","Aaliyah","Riley","Camila","Khloe","Claire"};

int calc(char c)
{
	return 97+(c-'a');
}

void deal(char* input)
{
	int index = 0;
	int len = strlen(input);
	for(int i = 0; i<len; i++)
		index += calc(input[i]);
	index%=b;
	while(HT[index][0]!=0)
	{
		sTime++;
		index++;
		if(index>=b)
			index%=b;		
	}
	sTime++;
	for(int i = 0; i<strlen(input); i++)
	{
		HT[index][i] = input[i];
	}
}

void search()
{
/**	int index = 0;
	sTime = 0;
	char* name;
	bool find = false;
	for(int i = 0; i<100; i++)
	{
		index = 0;
		name = names[i];
		for(int j = 0; j<strlen(name); j++)
		{
			index += calc(name[j]);
		}
		index %= b;
		for(int j = 0; j<strlen(name); j++)
		{
			if(HT[index][j]==name[j])
			{
				find = true;
			}
			else
			{
				find = false;
				break;
			}
		}
		while(!find)
		{
			index++;
			for(int j = 0; j<strlen(name); j++)
			{
				if(HT[index][j]==name[j])
				{
					find = true;
				}
				else
				{
					find = false;
				}
			}
			if(find == false)
				sTime++;
		}
		sTime++;
	}
	**/
	cout<<"Average Search Time : "<<sTime<<"//"<<(sTime/100.0)<<endl;
}

void init()
{
	for(int i = 0; i<100; i++)
	{
		deal(names[i]);
	}
	search();
}

int main()
{
	init();
} 
