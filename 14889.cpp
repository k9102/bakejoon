#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits.h>

using namespace std;

int n_;
int mat_[20][20];

int calc(int (&s)[20])
{
	int sum = 0;
	for (int i = 0; i < n_/2; i++)
		for (int j = i + 1; j < n_/2; j++)
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

	int s[20], l[20];
	do {
		auto[si, li] = pair{ 0,0 };

		for (int i = 0; i < n_; i++)
		{
			if (t[i]) s[si++]=i; else l[li++]=i;
		}

		auto[a, b] = pair{ calc(s),calc(l) };

		auto[c, d] = minmax(a, b);

		min_ = min(min_, d - c);

	} while (next_permutation(begin(t), end(t)));

	std::cout << min_ << endl;

	return 0;
}