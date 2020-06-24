#include<iostream>
#define n 5
using namespace std;

void print_maze(int maze[][n])
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool is_safe(int maze[][n],int x,int y)
{
	if(x < n && y < n && maze[x][y] != 0)
		return true;

	else
		return false;
}

void solve_maze(int maze[][n],int x,int y)
{
	if(x >= n-1 && y >= n-1){
		print_maze(maze);
		return;
	}

	//right movement
	if(is_safe(maze,x+1,y)){

		maze[x+1][y] = 2;

		solve_maze(maze,x+1,y);

		maze[x][y] = 0;
	}

	//down movement
	if(is_safe(maze,x,y+1)){

		maze[x][y+1] = 2;

		solve_maze(maze,x,y+1);

		maze[x][y] = 0;
	}
}

int main()
{
	int maze[n][n] = {
   {1, 0, 0, 0, 0},
   {1, 1, 0, 1, 0},
   {0, 1, 1, 1, 0},
   {0, 0, 0, 1, 0},
   {1, 1, 1, 1, 1}
};

    solve_maze(maze,0,0);
}