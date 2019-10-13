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
vector<pair<int, int>> spc_;
int main()
{
	cin >> n_ >> m_;
	for(int r=0;r<n_;r++)
		for (int c = 0; c < m_; c++)
		{
			auto &d = map_[r][c];
			cin >> d;
			if (d == 0) spc_.push_back({ r, c });
		}

	auto sz = size(spc_);
	vector<bool> comb(sz,false);
	
	comb[sz - 1] = comb[sz - 2] = comb[sz - 3] = true;

	do {
		auto tmap = map_;
		for (int i = 0; i < sz; i++)
		{
			if (comb[i]) {
				auto[r, c] = spc_[i];
				tmap[r][c] = 1;
			}
		}


	} while (next_permutation(begin(comb), end(comb)));
}