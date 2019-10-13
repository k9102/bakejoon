#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int n_;
int tp_[15][2];
int max_ = INT_MIN;

void Traverse(int acc,int dp)
{
	if (dp >= n_) 
	{
		if(dp==n_) max_ = max(max_, acc);
	}
	else
	{
		auto[t, p] = tp_[dp];

		Traverse(acc + p, dp + t);
		Traverse(acc, dp + 1);
	}
}
int main()
{
	cin >> n_;
	for (int i = 0; i < n_; i++)
	{
		auto &[t, p] = tp_[i];
		cin >> t >> p;
	}
	
	Traverse(0,0);

	cout << max_ << endl;
}