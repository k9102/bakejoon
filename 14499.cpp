#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <limits.h>
#include <array>

using namespace std;

enum {W,E,S,N,U,D};
int face[D+1] = {0,0,0,0,0,0};
int n_, m_,x_,y_;
int map_[20][20];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n_>> m_ >> x_ >> y_;
	for (int r = 0; r < n_; r++)
		for (int c = 0; c < n_; c++)
			cin >> map_[r][c];

	return 0;
}