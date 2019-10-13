#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <limits.h>
#include <array>

using namespace std;

int n_, m_;
int map_[500][500];
bool vis_[500][500];
int max_ = INT_MIN;
pair<int,int> mv_[8] = {
	{-1,-1},{-1,0} ,{-1,1},
	{ 0,-1}        ,{ 0,1},
	{ 1,-1},{ 1,0} ,{ 1,1}
};
inline bool Safe(int r,int c)
{
	return (r < 0 || r >= n_ || c < 0 || c >= m_) ? false : true;
}

void Traverse(int r, int c, int acc, int dp)
{
	if (dp == 4)
	{
		max_ = max(max_, acc);
		return;
	}

	if (!Safe(r, c) || vis_[r][c]) return;

	if (dp != 0)
	{
		bool adj = false;
		for (auto p : { 1,3,4,6 })
		{
			auto[ir, ic] = mv_[p];
			if (Safe(r + ir, c + ic) && vis_[r + ir][c + ic]) { adj = true; break; }
		}

		if (!adj) return;
	}
	
	vis_[r][c] = true;

	dp++; acc += map_[r][c]; 
	
	for (auto [ir,ic]: mv_)
	{
		Traverse(r+ir, c+ic,acc,dp);
	}

	vis_[r][c] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n_ >> m_;
	for (int r = 0; r < n_; r++)
		for (int c = 0; c < m_; c++)
			cin >> map_[r][c];

	for (int r = 0; r < n_; r++)
		for (int c = 0; c < m_; c++)
		{
			Traverse(r, c, 0,0);
		}

	cout << max_ << endl;
	return 0;
}