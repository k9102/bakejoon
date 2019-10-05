#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <limits.h>

using namespace std;

int N, M, D;
int map[15][15];

int main()
{
	cin >> N >> M >> D;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> map[r][c];
	
	vector<bool> tbl(M);
	tbl[M - 1] = true; tbl[M - 2] = true; tbl[M - 3] = true;


	int mx_dead = 0;
	do {

		int dead = 0;
		for (int ar_c = 0; ar_c < M; ar_c++)
		{
			if (tbl[ar_c])
			{
				for (int ar_r = N; ar_r <= 1; ar_r--)
				{
					pair<int, int> mp;
					int md = INT_MAX;
					for(int r=0;r<ar_r;r++)
					for (int c = 0; c < M; c++)
					{
						int dr = ar_r - r;
						int dc = ar_c - c > 0 ? ar_c-c:c-ar_c;

						if (dr + dc < md)
						{
							mp = { r,c };
							md = dr + dc;
						}
					}

					if (md == INT_MAX) { break; }
					auto[r, c] = mp;
					map[r][c] = 0;
					dead++;
				}
			}
		}

		mx_dead = max(mx_dead, dead);

	} while (next_permutation(begin(tbl),end(tbl)));

	return 0;
}