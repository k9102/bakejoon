#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <limits.h>

using namespace std;

int T;
int N, K;
int W;

vector<int>  D;
vector<vector<int>> S;
map<int, int> ca;

int traverse(int w)
{
	int mx = INT_MIN;

	if (ca.find(w) != end(ca)) return ca[w];

	for (int p : S[w])
	{
		int tm = traverse(p) + D[p];
		if (mx < tm) mx = tm;
	}

	int ret = mx == INT_MIN ? 0 : mx;
	ca[w] = ret;

	return ret;
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
		ca.clear();
		D.resize(N + 1);
		S.resize(K + 1);

		for (int i = 1; i <= N; i++)
		{
			cin >> D[i];
		}


		for (int i = 1; i <= K; i++)
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


