#include <iostream>

using namespace std;

int N;
int map[16][16];
int mv[4][2] = { {0,1},{1,1},{1,0},{0,0} };

int cango[3][3] = 
{
{true,true,false},
{true,true,true},
{false,true,true}
};

int cp[3][3] = 
{
	{0,3,3},
	{0,1,2},
	{2,3,3}
};

inline bool Blocked(int r, int c)
{
	if (r >= N || c >= N) return true;
	
	return map[r][c];

}
inline bool CanGo(int r,int c,int cdr,int ndr)
{
	if (!cango[cdr][ndr]) return false;

	for (int i = 0; i < 3; i++)
	{
		auto [r_,c_] = mv[cp[ndr][i]];
		if (Blocked(r + r_, c + c_)) return false;
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
			auto[r_, c_] = mv[i];
			traverse(r + r_, c + c_, i);
		}
	}
}


int main()
{
	cin >> N;

	for (int r = 0; r < N; r++)
	for (int c = 0; c < N; c++)
		cin >> map[r][c];

	traverse(0, 1, 0);

	cout << paths << endl;
	return 0;
}