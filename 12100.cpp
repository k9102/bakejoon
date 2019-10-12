#include <iostream>
#include <tuple>
#include <array>
#include <algorithm>
#include <numeric>
#include <map>


using namespace std;

int n_;
int mat_[20][20];

int main()
{
	cin >> n_;
	for(int r=0;r<n_;r++)
		for (int c = 0; c < n_; c++)
		{
			cin >> mat_[r][c];
		}

	return 0;
}