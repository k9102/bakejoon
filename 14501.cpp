#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <limits.h>
#include <array>

using namespace std;


int n_;
int tp_[15][2];

int max_ = INT_MIN;

void Traverse(int acc,int dp)
{
	if (dp >= n_) 
	{
		if(dp==n_) max_ = max(max_, acc);
		return;
	}

	auto[t, p] = tp_[dp];
	
	Traverse(acc + p, dp + t);
	Traverse(acc, dp + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n_;
	for (int i = 0; i < n_; i++)
	{
		auto &[t, p] = tp_[i];
		cin >> t >> p;
	}
	
	Traverse(0,0);

	cout << max_ << endl;
	return 0;
}