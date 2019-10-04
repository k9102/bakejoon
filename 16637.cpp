#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#include <algorithm>

using namespace std;

#define NM(v) (ex[2+2*(v)]-'0')
#define OP(v) (ex[1+2*(v)])

int N,n;
char ex[19 + 1];
int mx;

int cal(int op,int a, int b)
{
	switch (op)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
	}

	return 0;
}

void traverse(int r,int d,bool pending)
{
	if (d == n)
	{
		mx = max(mx, r);
		return;
	}

	if (int r_;pending)
	{
		r_ = cal(OP(d-1),r,cal(OP(d), NM(d - 1),NM(d)));
		traverse(r_,d+1,false);
	}
	else
	{
		if(d!=n-1) traverse(r, d + 1, true);

		r_ = cal(OP(d), r, NM(d));
		traverse(r_, d + 1, false);
	}
}

int main()
{
	cin >> N;
	cin >> ex;
	n = N / 2;

	mx = INT_MIN;
	
	traverse(ex[0] - '0', 0, false);

	cout << mx << endl;
	return 0;
}