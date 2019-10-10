#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <limits.h>
#include <array>

using namespace std;

int N_, M_, K_;
array<array<int,50>,50> mat_;
int rcs_[6][3];

int dir_[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int mi_ = INT_MAX;

int main()
{
	cin >> N_ >> M_ >> K_;
	for (int r = 0; r < N_; r++)
		for (int c = 0; c < M_; c++)
		{
			cin >> mat_[r][c];
		}

	for (int r = 0; r < K_; r++)
		for (int c = 0; c < 3; c++)
		{
			cin >> rcs_[r][c];
		}

	int seq[] = {0,1,2,3,4,5 };

	array<array<int, 50>, 50> mat;
	do {
		 mat = mat_;
		for (int k = 0; k < K_; k++)
		{
			auto[r, c, s] = rcs_[seq[k]]; r--, c--;

			for (int sl = 1; sl <= s; sl++)
			{
				auto[cr, cc, cv] = tuple(r - sl, c - sl, mat[r - sl][c - sl]);
				for (int d = 0; d < 4; d++)
				{
					auto[ir, ic] = dir_[d];
					for (int i = 0; i < 2 * sl; i++)
					{
						auto[nr, nc, nv] = tuple(cr + ir, cc + ic, mat[cr + ir][cc + ic]);

						mat[nr][nc] = cv;

						tie(cr, cc, cv) = tuple(nr, nc, nv);
					}
				}
			}
		}

		int mi = INT_MAX;
		for (int r = 0; r < N_; r++)
		{
			mi = min(mi, accumulate(begin(mat[r]),end(mat[r]),0));
		}

		mi_ = min(mi_, mi);

	} while (next_permutation(seq, seq + K_));

	cout << mi_ << endl;
	return 0;
}