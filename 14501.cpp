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
int tp_[1000][2];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n_;
	for (int i = 0; i < n_; i++)
	{
		auto &[t, p] = tp_[i];
		cin >> t >> p;
	}
	return 0;
}