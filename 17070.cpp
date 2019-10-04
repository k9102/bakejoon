#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

int N;
int map[16][16];
int mv[3][2] = { {0,1},{1,1},{1,0} };
int pb[3][3] =
{
	{true,true,false},
	{true,true,true},
	{false,true,false}
};

pair<int,int> ck[3][3] = 
{
	{{0,1},{0,0},{0,0}},
	{{0,1},{1,1},{1,0}},
	{{1,0},{0,0},{0,0}}
};

bool Blocked(int r, int c)
{
	if (r >= N || c >= N) 
		return false;
	
	return map[r][c];

}
bool CanGo(int r,int c,int cdr,int ndr)
{
	if (mv[cdr][ndr] == false) return false;

	for (int i = 0; i < 3; i++)
	{
		auto [r_,c_] = ck[cdr][i];
		if (Blocked(r + r_, c + c_)) 
			return false;
	}

	return true;

}

int paths = 0;
void traverse(int r,int c,int dir)
{
	if (r == N - 1 && c == N - 1)
	{
		paths++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if (CanGo(r, c, dir, i)) {
			auto[r_, c_] = ck[dir][i];
			traverse(r + r_, c + c_, i);
		}
	}
}


int main()
{
	string str;
	cin >> N;
	getline(std::cin, str);
	for (int i = 0; i < N; i++)
	{
		getline(std::cin, str);
		for (int j = 0; j < str.size(); j++)
		{
			if (j % 2 == 0) map[i][j / 2] = str[j]=='0' ? 0:1;
		}
	}

	traverse(0, 1, 0);

	cout << paths << endl;
	return 0;
}