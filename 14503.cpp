#include <iostream>
#include <algorithm>
#include <limits.h>
#include <array>


using namespace std;


using uchar = unsigned int;

int n_, m_;
int r_, c_;
uchar d_;
int mv_[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; /*N E S W*/
array<array<int, 50>, 50> mat_;

int main()
{
	int clean_cnt = 0;
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
			clean_cnt++;
			mat_[r_][c_] = 2;
		}

		/*2b*/
		for (int i = 0; i < 4; i++)
		{
			uchar d = (d_-(i+1)) % 4;
			auto[ir, ic] = mv_[d];
			int r = r_, c = c_;

			r += ir;
			c += ic;

			/*2a*/
			if (mat_[r][c] == 0)
			{
				d_ = d;
				r_ = r;
				c_ = c;
				break;
			}
		}

		
		if (mat_[r_][c_] != 0)
		{
			uchar d = (d_ + 2) % 4;
			auto[ir, ic] = mv_[d];
			int r = r_, c = c_;
			r += ir;
			c += ic;
		
			if (mat_[r][c] != 1)  /*2c*/
			{
				r_ = r;
				c_ = c;
			}
			else   /*2d*/
			{
				break;
			}
		}

	}

	cout << clean_cnt << endl;
}