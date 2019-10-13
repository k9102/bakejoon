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
array<array<int,8>,8> map_;
array<array<int, 8>, 8> tmap_;
vector<pair<int, int>> spc_;
vector<pair<int, int>> vrs_;
int max_ = INT_MIN;

inline bool CanGo(int r, int c)
{
	return (r < 0 || r >= n_ || c < 0 || c >= m_) ? false : true;
}
void Traverse(int r, int c)
{

	if (!CanGo(r, c) || tmap_[r][c] != 0) return;
	

	tmap_[r][c] = 2;

	Traverse(r + 1, c);
	Traverse(r - 1,c);
	Traverse(r, c+1);
	Traverse(r, c-1);
}

int main()
{
	cin >> n_ >> m_;
	for(int r=0;r<n_;r++)
		for (int c = 0; c < m_; c++)
		{
			auto &d = map_[r][c];
			cin >> d;
			if (d == 0) spc_.push_back({ r, c });
			if (d == 2) vrs_.push_back({ r, c });
		}

	auto sz = size(spc_);
	vector<bool> comb(sz,false);
	
	comb[sz - 1] = comb[sz - 2] = comb[sz - 3] = true;

	do {
		tmap_ = map_;
		for (size_t i = 0; i < sz; i++)
		{
			if (comb[i]) {
				auto[r, c] = spc_[i];
				tmap_[r][c] = 1;
			}
		}

		for (auto[r, c] : vrs_)
		{
			tmap_[r][c] = 0;
			Traverse(r, c);
		}

		int cnt = 0;
		for (int r=0;r<n_;r++)
			for (int c = 0; c < m_; c++)
			{
				if (!tmap_[r][c]) cnt++;
			}
	
		max_ = max(max_, cnt);

	} while (next_permutation(begin(comb), end(comb)));

	cout << max_ << endl;
}