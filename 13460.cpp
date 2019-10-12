#include <iostream>
#include <tuple>
#include <algorithm>
#include <limits.h>

using namespace std;

int n_, m_;
char mat_[10][10];

int mv_[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
enum { N, E, S, W };
int min_ = INT_MAX;


bool IsBlocked(int r, int c)
{
	auto v = mat_[r][c];
	return (v == 'R' || v == 'B' || v == '#' || v == 'O') ? true : false;
}

bool Roll(pair<int, int> &rp, int d)
{
	auto&[r, c] = rp;
	auto[ir, ic] = mv_[d];

	while (!IsBlocked(r + ir, c + ic)) { r += ir; c += ic; }

	return mat_[r + ir][c + ic] == 'O' ? true : false;
}

void traverse(pair<int, int> rp, pair<int, int> bp, int rolls)
{
	auto[rr, rc] = rp;
	auto[br, bc] = bp;

	if (rolls >= 10) return;

	for (int d = 0; d < 4; d++)
	{
		bool rfirst = false;
		switch (d)
		{
		case N:
			if (rr < br) rfirst = true;
			break;
		case E:
			if (rc > bc) rfirst = true;
			break;
		case S:
			if (rr > br) rfirst = true;
			break;
		case W:
			if (rc < bc) rfirst = true;
			break;
		}

		int rret, bret;
		if (rfirst)
		{
			rret = Roll(rp, d);
			auto[rr, rc] = rp; if (!rret) mat_[rr][rc] = 'R'; bret = Roll(bp, d); mat_[rr][rc] = '.';
		}
		else
		{
			bret = Roll(bp, d);
			auto[br, bc] = bp; if (!bret) mat_[br][bc] = 'B'; rret = Roll(rp, d); mat_[br][bc] = '.';
		}

		if (!bret)
		{
			if (rret)
			{
				min_ = min(min_, rolls + 1);
			}
			else
			{
				if (rp != pair{ rr, rc } || bp != pair{ br,bc }) traverse(rp, bp, rolls + 1);
			}
		}

		rp = { rr, rc };
		bp = { br, bc };
	}
}

int main()
{
	pair<int, int> rp, bp;
	cin >> n_ >> m_;

	for (int r = 0; r < n_; r++)
	{
		for (int c = 0; c < m_; c++)
		{
			auto &d = mat_[r][c];
			cin >> d;
			if (d == 'R') { rp = { r,c }; d = '.'; };
			if (d == 'B') { bp = { r,c }; d = '.'; }
		}
	}

	traverse(rp, bp, 0);

	cout << (min_ == INT_MAX ? -1 : min_) << endl;


	return 0;
}