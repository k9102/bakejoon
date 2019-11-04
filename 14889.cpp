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
int mat_[20][20];

int calc(const vector<int> &s)
{
	int sum = 0;
	for (size_t i = 0; i < s.size(); i++)
		for (size_t j = i + 1; j < s.size(); j++)
		{
			sum += mat_[s[i]][s[j]] + mat_[s[j]][s[i]];
		}

	return sum;
}

int min_ = INT_MAX;
int main()
{
	int cnt = 0;
	cin >> n_;

	for (int r = 0; r < n_; r++)
		for (int c = 0; c < n_; c++)
		{
			cin >> mat_[r][c];
		}

	vector<int> t(n_, 0);
	fill_n(begin(t) + n_ / 2, n_ / 2, 1);

	do {
		vector<int> s,l;
		for (int i = 0; i < n_; i++)
		{
			if (t[i]) s.push_back(i); else l.push_back(i);
		}

		auto[a, b] = pair{ calc(s),calc(l) };

		auto[c, d] = minmax(a, b);

		min_ = min(min_, d - c);

	} while (next_permutation(begin(t), end(t)));

	std::cout << min_ << endl;

	return 0;
}