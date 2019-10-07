#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <limits.h>

using namespace std;

int N, M, D;

int main()
{
	cin >> N >> M >> D;

	vector<vector<int>> data(N,vector<int>(M));

	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> data[r][c];

	vector<bool> tbl(M);

	tbl[M - 1] = true; 
	tbl[M - 2] = true; 
	tbl[M - 3] = true;


	int mx_dead = 0;
	do {

		int dead = 0;
		
		auto map = data;

		for (int ar_r = N; ar_r >= 1; ar_r--)
		{
			vector<pair<int, int>> dp = {};
			for (int ar_c = 0; ar_c < M; ar_c++)
			{
				if (tbl[ar_c])
				{
					pair<int, int> mp;
					int md = INT_MAX;
					for (int c = 0; c < M; c++)
					for (int r = 0; r < ar_r; r++)
						{
							if (map[r][c])
							{
								int dr = ar_r - r;
								int dc = max(ar_c - c, c - ar_c);
								int d = dr + dc;
								if (d<=D && md>d)
								{
									mp = { r,c };
									md = dr + dc;
								}
							}
						}

					if (md == INT_MAX) continue;
					auto[r, c] = mp;
					if (map[r][c] != 2)
					{
						dp.push_back(mp);
						map[r][c] = 2;
						dead++;
					}
				}
			}

			for (auto[r, c] : dp)
			{
				map[r][c] = 0;
			}
		}
		mx_dead = max(mx_dead, dead);
	} while (next_permutation(begin(tbl), end(tbl)));

	std::cout << mx_dead << endl;
	
	return 0;
}