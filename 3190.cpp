#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <set>

using namespace std;
using rc = pair<int, int>;
vector<rc> sn_ = { {1,1} };
set<rc> ap_;
map<int,int> cmd_;

int n_, k_,l_;

enum {N,E,S,W};
unsigned char dr_ = E;
rc mv_[4] = { {-1,0},{0,1},{1,0},{0,-1} };

int main()
{
	cin >> n_ >> k_;
	for (int i = 0; i < k_; i++) {
		int r, c;
		cin >> r >> c;
		ap_.emplace(r,c);
	}

	cin >> l_;
	for (int i = 0; i < l_; i++) {
		int x; char c;
		cin >> x >> c; cmd_[x]= c=='L' ? -1:1;
	}

	int tm = 0;

	while (true) {
		tm++;

		auto[r, c] = sn_.back();
		auto [ir, ic] = mv_[dr_];
	
		r += ir;
		c += ic;

		auto sn = find(begin(sn_), end(sn_), pair{ r,c });

		if (sn != end(sn_)) break;
		if (1 > r || r > n_ || 1 > c || c > n_) break;
		
		sn_.emplace_back(r, c);

		auto ap = ap_.find(pair{ r,c });
		if (ap == end(ap_)) sn_.erase(begin(sn_)); else ap_.erase(ap);

		auto cmd = cmd_.find(tm);
		if (cmd != end(cmd_))
		{
			dr_ = dr_ + cmd->second;  dr_ &= 0b11;
		}
	}

	cout << tm << endl;
	
	return 0;
}