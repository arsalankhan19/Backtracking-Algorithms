#include<iostream>
#define n 8
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

void print_board(int board[][n])
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool is_safe(int board[][n],int row,int col)
{
	//row
	for(int i=0;i<col;i++)
		if(board[row][i] == 1)
			return false;

	//left diagonal
	int i=row,j=col;
	while(i >= 0 && j >= 0)
	{
		if(board[i][j] == 1)
			return false;

		i--;
		j--;
	}

	//right diagonal
	i=row,j=col;
	while(i >= 0 && j >= 0)
	{
		if(board[i][j] == 1)
			return false;

		i++;
		j--;
	}

	return true;

}

bool place_queen(int board[][n],int col)
{
	cout<<col<<endl;
	if(col >= n)
		return true;

	for(int row=0;row<n;row++)
	{
		if(is_safe(board,row,col)){

			board[row][col] = 1;

			if(place_queen(board,col+1))
				return true;

			board[row][col] = 0;             //backtrack
				
		}
	}

	return false;	
}

int main()
{
	int board[n][n];

	rep(i,n)
	{
		rep(j,n)
		{
			board[i][j] = 0;
		}
	}

	if(place_queen(board,0) == true)
		print_board(board);

	else
		cout<<"NO WAY OUT!!!"<<endl;
}