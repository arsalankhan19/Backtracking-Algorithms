#include<iostream>
#include<climits>
using namespace std;

int ans = INT_MAX;

void update_res(int subset_sum,int sum)
{
	int temp;
	temp = sum - subset_sum;

	if(ans > abs(subset_sum-temp)){
		ans = abs(subset_sum-temp);
	}
}

void subset_part(int a[],int index,int sum,int curr_sum,int n)
{
	for(int i=index;i<n;i++)
	{
		if(curr_sum != 0 || curr_sum != sum)
			update_res(curr_sum,sum);

		subset_part(a,index+1,sum,curr_sum+a[i],n);
	}
}

int main()
{
	int n,sum=0;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	subset_part(a,0,sum,0,n);
	cout<<ans<<endl;
}