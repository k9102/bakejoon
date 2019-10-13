#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <limits.h>
#include <array>

using namespace std;

enum { E, W, N, S, U, D };
int mv_[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int dice_[D + 1];;
int n_, m_, x_, y_, k_;
int map_[20][20];
bool CanGo(int x, int y)
{
	return (x < 0 || x >= m_ || y < 0 || y >= n_) ? false : true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n_ >> m_ >> x_ >> y_ >> k_;
	for (int r = 0; r < n_; r++)
		for (int c = 0; c < m_; c++)
			cin >> map_[r][c];

	vector<int> cmd(k_);
	for (int i = 0; i < k_; i++) cin >> cmd[i];

	int tbl[4][2] = { {N,S},{S,N},{E,W},{W,E} };
	for (auto c : cmd)
	{	
		c--;
		auto[ir, ic] = mv_[c];
		if (!CanGo(x_ + ic, y_ + ir)) 
			continue;

		auto[f,s] = tbl[c];
		swap(dice_[D], dice_[f]);
		swap(dice_[U], dice_[s]);
		swap(dice_[f], dice_[s]);

		x_ += ic; y_ += ir;
		auto &d = map_[y_][x_];
		if (d == 0) d = dice_[D]; else { dice_[D] = d; d = 0; };

		cout << dice_[U] << endl;
	}

	return 0;
}