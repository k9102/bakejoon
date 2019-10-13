#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <limits.h>
#include <array>

using namespace std;

int n_, m_;
int map_[500][500];

void Traverse(int r, int c, int dp)
{

}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n_ >> m_;
	for (int r = 0; r < n_; r++)
		for (int c = 0; c < m_; c++)
			cin >> map_[r][c];

	for (int r = 0; r < n_; r++)
	for (int c = 0; c < m_; c++)
	{
		Traverse(r, c,0);
	}

	return 0;
}