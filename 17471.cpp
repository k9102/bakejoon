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

	for (int g = 1; g <= 5; g++)
	{
		vector<int> tbl(10,0);
		for (int i = 0; i < g; i++) tbl[10 - i] = true;

		do {

		} while (next_permutation(begin(tbl), end(tbl)));
		
	}


	return 0;
}