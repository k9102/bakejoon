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
int mat_[50][50];
int rcs_[6][3];

int dir_[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

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

	for (int k = 0; k < K_; k++)
	{
		auto[r, c, s] = rcs_[k]; r--, c--;
		
		for (int sl = 1; sl <= s; sl++)
		{
			auto[cr, cc,cv] = tuple(r-sl,c-sl, mat_[r-sl][c-sl]);
			for (int d = 0; d < 4; d++)
			{
				auto[ir, ic] = dir_[d];
				for (int i = 0; i < 2*sl; i++)
				{			
					auto[nr, nc, nv] = tuple(cr + ir, cc + ic, mat_[cr + ir][cc + ic]);
					
					mat_[nr][nc] = cv;

					tie(cr, cc, cv) = tuple(nr, nc, nv);
				}
			}
		}
	}

	int mi = INT_MAX;
	for (int r = 0; r < N_; r++)
	{
		mi = min(mi,accumulate(mat_[r], mat_[r] + M_, 0));
	}

	cout << mi << endl;
	return 0;
}