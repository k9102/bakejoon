#include <iostream>
#include <vector>


using namespace std;

int n_,b_,c_;
vector<int> aj_;

int main()
{
	cin >> n_; aj_.resize(n_);
	for (int i = 0; i < n_; i++) cin >> aj_[i];
	cin >> b_ >> c_;

	long long cnt = n_;
	for (auto d : aj_)
	{
		if (auto r = d - b_; r > 0) {
			cnt += r / c_;
			if (r%c_) cnt++;
		}

	}

	cout << cnt << endl;
	return 0;
}