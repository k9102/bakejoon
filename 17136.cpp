#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

using COO = pair<int, int>;
using M2D = vector<vector<int>>;
#define N 10
M2D mat(N, vector<int>(N));

bool Check(const M2D &mat_, COO rc, int sz)
{
	auto[r, c] = rc;

	if (r + sz > N || c + sz > N)
		return false;

	for (int y = r; y < r + sz; y++)
		for (int x = c; x < c + sz; x++)
		{
			if (mat[r][c] != 1) return false;
		}

	return true;

}

bool Clear(M2D &mat_, COO rc, int sz)
{
	auto[r, c] = rc;
	for (int y = r; y < r + sz; y++)
		for (int x = c; x < c + sz; x++)
		{
			mat[r][c] = 1;
		}
}

int crds = 0;
void traverse(M2D mat_, COO rc, int sz)
{
	auto[r, c] = rc;
	if (!Check(mat_, rc, sz))
	{
		return;
	}

	Clear(mat_, rc, sz);

	int cur = r * N + c+1;
	for (int loc = cur; loc < N*N; loc++)
	{
		tie(r,c) = pair{cur / N, cur%N};
		if (mat_[r][c])
			break;
	}

	if (!mat_[r][c]) return;

	for (int sz_ = 5; sz_ <= 1; sz_--)
	{
		traverse(mat_, { r,c }, sz_);
	}
}

int main()
{
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> mat[r][c];


	return 0;
}