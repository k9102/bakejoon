#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <limits.h>
#include <array>

using namespace std;

int N_;
int pop_[10];
vector<vector<int>> adj_;
array<bool, 10> tbl_;
array<bool, 10> visited_;
bool flag_;
int mi_ = INT_MAX;

void traverse(int loc)
{
	visited_[loc] = true;

	for (auto n : adj_[loc])
	{
		if (tbl_[n] == flag_ && !visited_[n])
		{
			traverse(n);
		}
	}
}

int main()
{
	cin >> N_;

	for (int i = 0; i < N_; i++)   cin >> pop_[i];

	for (int i = 0; i < N_; i++) {
		int n; cin >> n;
		vector<int> vec;
		for (int j = 0; j < n; j++) { 
			int v; cin >> v; vec.push_back(v-1);
		}
		adj_.push_back(move(vec));
	}

	
	for (int g = 1; g <= N_/2; g++)
	{
		tbl_[N_- g] = true;

		do {
			fill_n(begin(visited_), N_,false);
			
			for (auto flag : {true,false})
			for(int loc=0;loc<N_;loc++)
				if (tbl_[loc] == flag) {
					flag_ = flag;
					traverse(loc);
					break;
				}

			bool ret = all_of(begin(visited_), begin(visited_)+N_, [](auto v) { return v == true; });
			if (ret)
			{
				auto[tsum, fsum] = tuple(0, 0);
				for (int i = 0; i < N_; i++)
				{
					if (tbl_[i]) tsum += pop_[i]; else fsum += pop_[i];
				}
				auto[a, b] = minmax(tsum, fsum);
				mi_ = min(mi_, b - a);
			}
		} while (next_permutation(begin(tbl_), begin(tbl_)+N_));
		
	}

	if (mi_ == INT_MAX) mi_ = -1;
	cout << mi_ << endl;

	return 0;
}