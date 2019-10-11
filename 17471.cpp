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
array<bool, 10> com_;
array<bool, 10> visit_;
bool flag_;
int min_ = INT_MAX;

void traverse(int loc)
{
	visit_[loc] = true;

	for (auto n : adj_[loc])  if (com_[n] == flag_ && !visit_[n]) traverse(n);
	
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
		com_[N_- g] = true;

		do {
			fill_n(begin(visit_), N_,false);
			
			for (auto flag : {true,false})
			for(int loc=0;loc<N_;loc++)
				if (com_[loc] == flag) {
					flag_ = flag;
					traverse(loc);
					break;
				}

			if (bool r = all_of(begin(visit_), begin(visit_) + N_, [](auto v) { return v == true; });r)
			{
				auto[tsum, fsum] = tuple(0, 0);
				for (int i = 0; i < N_; i++) if (com_[i]) tsum += pop_[i]; else fsum += pop_[i];
				auto[a, b] = minmax(tsum, fsum);
				min_ = min(min_, b - a);
			}
		} while (next_permutation(begin(com_), begin(com_)+N_));
		
	}

	if (min_ == INT_MAX) min_ = -1;
	cout << min_ << endl;

	return 0;
}