#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <limits.h>
#include <stack>
#include <algorithm>

using namespace std;

int T;
int N, K;
int W;

vector<int>  D;
vector<vector<int>> S;
map<int, int> ca;

int traverse_(int W_)
{
	int r = 0;
	int pop =  false;

	stack<tuple<int, int, int>> st;

	st.push({W_,0,0});
	while (!st.empty())
	{
		auto &[w,mx,i] = st.top();
		if (pop) {
			pop = false;
			mx = max(r, mx);
		}
		
		if (i < S[w].size()) {
			if (ca.find(S[w][i]) != end(ca)) {
				r = ca[S[w][i]];
				pop = true;
			}
			else {
				st.push({ S[w][i],0 ,0 });
			}
			i++;
		}
		else {
			r = mx+D[w];
			ca[w] = r;
			st.pop();
			pop = true;
		}
	}

	return r;
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


		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			S[Y].push_back(X);
		}

		cin >> W;
		R.push_back(traverse_(W));

	}

	for (int t = 0; t < T; t++)
	{
		cout << R[t] << endl;
	}
	return 0;
}


/*
1
4 5
10 1 100 10
1 2
1 3
2 4
3 4
2 3
4
*/

