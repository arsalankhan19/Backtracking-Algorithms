#include<iostream>
using namespace std;

void generate_par(int index,int open_b,int closed_b,int n,char output[])
{
	if(index == 2*n)
	{
		output[index] = '\0';
		for(int i=0;i<index;i++)
			cout<<output[i];

		cout<<endl;

		return;
	}

	if(open_b < n){
		output[index] = '{';

		generate_par(index+1,open_b+1,closed_b,n,output);
	}

	if(closed_b < open_b){
		output[index] = '}';

		generate_par(index+1,open_b,closed_b+1,n,output);
	}

}

int main()
{
	int n;
	cin >> n;

	char output[2*n];
	generate_par(0,0,0,n,output);
}