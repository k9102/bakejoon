#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <limits.h>

using namespace std;


#define N 10

using COO = pair<int, int>;
using M2D = vector<vector<int>>;
M2D mat_(N, vector<int>(N));


bool Covered(const M2D &mat, COO rc, int sz)
{
	auto[r, c] = rc;

	if (r + sz > N || c + sz > N)
		return false;

	for (int y = r; y < r + sz; y++)
		for (int x = c; x < c + sz; x++)
		{
			if (mat[y][x] != 1) return false;
		}

	return true;

}

void Clr(M2D &mat, COO rc, int sz)
{
	auto[r, c] = rc;
	for (int y = r; y < r + sz; y++)
		for (int x = c; x < c + sz; x++)
		{
			mat[y][x] = 0;
		}
}

int crds[5+1] = { 0,5,5,5,5,5};
int min_crds = INT_MAX;
bool traverse(M2D mat, COO rc, int sz)
{
	auto[r, c] = rc;

	if (crds[sz] == 0) return true; /*run out of card*/

	if (!Covered(mat, rc, sz)) return false;

	Clr(mat, rc, sz);

	crds[sz]--;

	int cur = r * N + c+1;
	for (; cur < N*N; cur++)
	{
		tie(r,c) = pair{cur / N, cur%N};
		if (mat[r][c])
			break;
	}

	if (cur == N * N) { /*sucess to cover the board*/
		int sum = accumulate(begin(crds), end(crds), 0);
		min_crds = min(min_crds,25 - sum);
	}
	else
	{
		for (int sz = 1; sz <= 5; sz++)
		{
			int ret = traverse(mat, { r,c }, sz);
			if (!ret) break;
		}
	}

	crds[sz]++;

	return true;
}

int main()
{
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> mat_[r][c];


	int r, c;
	for (int cur=0; cur < N*N; cur++)
	{
		tie(r, c) = pair{ cur / N, cur%N };
		if (mat_[r][c])
			break;
	}

	for (int sz = 1; sz <= 5; sz++)
	{
		int ret = traverse(mat_, { r,c }, sz);
		if (!ret) break;
	}

	if (min_crds == INT_MAX)
		cout << -1 << endl;
	else
		cout << min_crds << endl;
	return 0;
}