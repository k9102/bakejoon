#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <limits.h>
#include <array>

using namespace std;



array<int, 9> seq_ = { 0,1,2,3,4,5,6,7,8};
array<array<int, 9>, 50> tbl_;
int N_;
int mx_score = INT_MIN;

inline int Play(array<int, 9> seq)
{
	int base[7];
	int score = 0;
	int out = 0;
	int nth = 0;
	
	swap(seq[0], seq[3]);

	for (int i = 0; i < N_; i++)
	{
		out = 0;
		fill(begin(base), end(base), 0);
		while(1)
		{
			int h = tbl_[i][seq[nth++%9]];
			if (h==0)
			{
				out++;
				if (out == 3) break;
			} else {
				copy_backward(begin(base), begin(base) + 3, begin(base) + h + 3);
				fill_n(begin(base), h, 0);
				base[h-1] = 1;
				
				score = accumulate(begin(base) + 3, end(base), score);
				fill(begin(base)+3,end(base), 0);
			}
		}
	}

	return score;
}

int main()
{
	cin >> N_;
	for (int r = 0; r < N_; r++)
		for (int c = 0; c < 9; c++)
		{
			cin >> tbl_[r][c];
		}

	do
	{
		int score = Play(seq_);
		mx_score = max(mx_score, score);

	} while (next_permutation(begin(seq_)+1, end(seq_)));

	cout << mx_score << endl;
	return 0;
}