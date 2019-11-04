#include <iostream>
#include <array>


using namespace std;

using uint = unsigned int;

int n_, m_, r_, c_;
uint d_;
int mv_[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
array<array<int, 50>, 50> mat_;

pair<int,int> mv(int d,int r, int c)
{
	auto[ir, ic] = mv_[d];

	r += ir;
	c += ic;

	return { r,c };
}

int main()
{
	int cnt = 0;
	cin >> n_ >> m_;
	cin >> r_ >> c_ >> d_;

	for(int r=0;r<n_;r++)
		for (int c = 0; c < m_; c++)
		{
			cin >> mat_[r][c];
		}

	while(true) {

		/*1*/
		if (mat_[r_][c_] == 0)
		{
			cnt++;
			mat_[r_][c_] = 2;
		}

		/*2b*/
		for (int i = 0; i < 4; i++)
		{
			uint d = (d_-(i+1)) % 4;
			auto[r, c] = mv(d, r_, c_);

			/*2a*/
			if (!mat_[r][c])
			{
				d_ = d; r_ = r; c_ = c;
				break;
			}
		}

		if (mat_[r_][c_])
		{
			uint d = (d_ + 2) % 4;
			auto[r, c] = mv(d, r_, c_);
		
			if (mat_[r][c] != 1)  /*2c*/
			{
				r_ = r; c_ = c;
			}
			else { /*2d*/
				break;
			}
		}

	}

	cout << cnt << endl;
}