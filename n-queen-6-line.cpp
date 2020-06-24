#include<iostream>
#include<bitset>
using namespace std;

bitset<30> row,d1,d2;

void solveNqueen(int n,int col,int &ans)
{
	if(col >= n){ans++; return;}

	for(int i=0;i<n;i++){

		if(!row[i] && !d1[i-col+n-1] && !d2[i+col])
		{
			row[i] = d1[i-col+n-1] = d2[i+col] = 1;

			solveNqueen(n,col+1,ans);

			row[i] = d1[i-col+n-1] = d2[abs(i+col)] = 0;
		}	
	}
}

int main()
{
	int n;
	cin >> n;

	int ans=0;
	solveNqueen(n,0,ans);
	cout<<ans<<endl;
}