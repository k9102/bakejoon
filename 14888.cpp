#include <iostream>
#include <vector>
#include <limits.h>
#include <array>
#include <functional>

using namespace std;

int n_;
array<int,11> num_;

function<int(int, int)> fn[4] = { 
	[](int a,int b) {return a + b; }, 
	[](int a,int b) {return a - b; },
	[](int a,int b) {return a * b; },
	[](int a,int b) {return a / b; }
};

int max_ = INT_MIN;
int min_ = INT_MAX;
int main()
{
	vector<int> op;
	cin >> n_;
	for (int i = 0; i < n_; i++) cin >> num_[i];
	for (int i = 0; i < 4; i++)
	{
		int cnt; cin >> cnt; for (int j = 0; j < cnt; j++) op.push_back(i);
	}

	do {
		int a = num_[0];
		for (vector<int>::size_type i = 0; i < op.size(); i++)
		{
			a = fn[op[i]](a, num_[i+1]);
		}

		min_ = min(min_, a);
		max_ = max(max_, a);

	} while (next_permutation(begin(op), end(op)));


	cout << max_ << endl << min_<< endl;
	return 0;
}