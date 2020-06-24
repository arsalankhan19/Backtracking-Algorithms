#include<iostream>
using namespace std;

void swap(char *a,char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permute(string str,int index)
{
	if(index == str.length())
	{
		cout<<str<<endl;
		return;
	}

	else{

		for(int i=index;i<str.length();i++)
		{
			swap(&str[i],&str[index]);
			permute(str,index+1);
			swap(&str[i],&str[index]);
		}
	}
}

int main()
{
	string str;
	cin >> str;

	cout<<"ALL PERMUTATIONS ARE:"<<endl;
	permute(str,0);
}