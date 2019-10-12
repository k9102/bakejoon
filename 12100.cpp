#include <iostream>
#include <tuple>
#include <array>
#include <algorithm>
#include <numeric>
#include <map>
#include <limits.h>

using namespace std;

template<typename T, int s = 20> using arr = array<T, s>;

int n_;

arr<arr<int>> mat_;
enum {N,S,W,E};
int mv_[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int max_=INT_MIN;

void SqueezeN(arr<arr<int>> &mat)
{
	for (int c = 0; c < n_; c++)
	{
		for (int r = 0; r < n_; r++)
		{
			if (mat[r][c] == 0) continue;
			for (int i = r+1; i < n_; i++)
			{
				if (mat[i][c] == 0) continue;
				if (mat[r][c] == mat[i][c])
				{
					mat[r][c] = 2 * mat[r][c];
					mat[i][c] = 0;
				}
				
				break;
			}
		}

		for (int r = 0; r < n_; r++)
		{
			if (mat[r][c] != 0) continue;
			for (int i = r + 1; i < n_; i++)
			{
				if (mat[i][c] != 0)
				{
					mat[r][c] = mat[i][c];
					mat[i][c] = 0;
					break;
				}
			}
		}

	}
}


void SqueezeS(arr<arr<int>> &mat)
{
	for (int c = 0; c < n_; c++)
	{
		for (int r = n_-1; r >= 0; r--)
		{
			if (mat[r][c] == 0) continue;
			for (int i = r - 1; i >= 0; i--)
			{
				if (mat[i][c] == 0) continue;
				if (mat[r][c] == mat[i][c])
				{
					mat[r][c] = 2 * mat[r][c];
					mat[i][c] = 0;
				}

				break;
			}
		}

		for (int r = n_-1; r >= 0; r--)
		{
			if (mat[r][c] != 0) continue;
			for (int i = r -1 ; i >= 0; i--)
			{
				if (mat[i][c] != 0)
				{
					mat[r][c] = mat[i][c];
					mat[i][c] = 0;
					break;
				}
			}
		}

	}
}

void SqueezeW(arr<arr<int>> &mat)
{
	for (int r = 0; r < n_; r++)
	{
		for (int c = 0; c < n_; c++)
		{
			if (mat[r][c] == 0) continue;
			for (int i = c + 1; i < n_; i++)
			{
				if (mat[r][i] == 0) continue;
				if (mat[r][c] == mat[r][i])
				{
					mat[r][c] = 2 * mat[r][c];
					mat[r][i] = 0;
				}

				break;
			}
		}

		for (int c = 0; c < n_; c++)
		{
			if (mat[r][c] != 0) continue;
			for (int i = c + 1; i < n_; i++)
			{
				if (mat[r][i] != 0)
				{
					mat[r][c] = mat[r][i];
					mat[r][i] = 0;
					break;
				}
			}
		}

	}
}

void SqueezeE(arr<arr<int>> &mat)
{
	for (int r = 0; r < n_; r++)
	{
		for (int c = n_-1; c >=0; c--)
		{
			if (mat[r][c] == 0) continue;
			for (int i = c - 1; i >= 0; i--)
			{
				if (mat[r][i] == 0) continue;
				if (mat[r][c] == mat[r][i])
				{
					mat[r][c] = 2 * mat[r][c];
					mat[r][i] = 0;
				}

				break;
			}
		}

		for (int c = n_ - 1; c >= 0; c--)
		{
			if (mat[r][c] != 0) continue;
			for (int i = c - 1; i >= 0; i--)
			{
				if (mat[r][i] != 0)
				{
					mat[r][c] = mat[r][i];
					mat[r][i] = 0;
					break;
				}
			}
		}

	}
}



void Traverse(arr<arr<int>> mat, int d)
{
	if (d == 5) {
		for(int r=0;r<n_;r++)
		for (int c = 0; c < n_; c++)
		{
			max_ = max(mat[r][c], max_);
		}
		return;
	}

	decltype(mat) m;
	m = mat; SqueezeN(m); Traverse(m, d + 1);
	m = mat; SqueezeS(m); Traverse(m, d + 1);
	m = mat; SqueezeE(m); Traverse(m, d + 1);
	m = mat; SqueezeW(m); Traverse(m, d + 1);
}


int main()
{
	cin >> n_;
	for(int r=0;r<n_;r++)
		for (int c = 0; c < n_; c++)
		{
			cin >> mat_[r][c];
		}

	Traverse(mat_,0);

	cout << max_ << endl;
	return 0;
}