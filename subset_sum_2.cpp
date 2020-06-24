#include <bits/stdc++.h>
using namespace std;

vector<stack<int>> sol={};

bool Safe(int sum, int tar)
{
    return (sum<=tar);
}

void printsol(vector<stack<int>>& sol)
{
    int i, j;
    for(i=0; i<sol.size(); i++)
    {
        cout<<i+1<<"-"<<endl;
        while(!sol[i].empty())
        {
            cout<<sol[i].top()<<" ";
            sol[i].pop();
        }
        cout<<endl;
    }
}

void Solve(int x, stack<int>& arr, vector<int>& wt, int n, int tar, int sum)
{
    int i;
    if(tar == sum)
    {
        sol.push_back(arr);
        return;
    }

    for(i=x; i<n; i++)
    {
        if(Safe(sum+wt[i], tar))
        {
            arr.push(wt[i]);
            Solve(i+1, arr, wt, n, tar, sum+wt[i]);
            arr.pop();
        }
    }
}

void generateSubsets(vector<int>& wt, int n, int tar)
{
    stack<int> arr;

    Solve(0, arr, wt, n, tar, 0);

    if(sol.size()==0)
        cout<<"No Solution"<<endl;

    else 
    {
        printsol(sol);
        return;
    }
    
}

int main() {
    vector<int> wt={1, 5, 6, 2, 3};
	//vector<int> wt={15, 22, 14, 26, 32, 9, 16, 8};
    // vector<int> wt={10, 7, 5, 18, 12, 20, 15}; 
    int tar=10;
    // tar=35;
	//sort(wt.begin(), wt.end());
	generateSubsets(wt, wt.size(), tar); 
	return 0;
}
