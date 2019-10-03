#include <iostream>
#include <vector>
#include <map>

using namespace std;

int T, N, K, W;

vector<int>  D;
vector<vector<int>> S;
map<int, int> C;

int traverse(int w)
{
	int mx = 0;
	if (C.find(w) != end(C)) return C[w];
	for (int p : S[w])
	{
		int tm = traverse(p) + D[p];
		if (mx < tm) mx = tm;
	}
	C[w] = mx;
	return mx;
}

int main()
{

	cin >> T;
	vector<int>  R;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		cin >> K;

		D.clear();
		S.clear();
		C.clear();
		D.resize(N + 1);
		S.resize(N + 1);

		for (int i = 1; i <= N; i++)
		{
			cin >> D[i];
		}


		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			S[Y].push_back(X);
		}

		cin >> W;
		R.push_back(traverse(W) + D[W]);

	}

	for (int t = 0; t < T; t++)
	{
		cout << R[t] << endl;
	}

}