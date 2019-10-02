// baekjoon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <map>


using namespace std;
map<int, tuple<int, int>> c;

tuple<int,int> fibonacci(int n) {

	int z, o;

	if (c.find(n) != end(c))
		return c[n];
	if (n == 0) {
		z = 1;
		o = 0;
	}
	else if (n == 1) {
		z = 0;
		o = 1;
	}
	else {

		auto [a,b] =fibonacci(n - 1);
		auto [c,d] = fibonacci(n-2);
		z = a + c;
		o = b + d;
	}

	c[n] = { z,o };
	return c[n];
}

int main()
{
	int N;

	cin >> N;

	vector<int> n(N);

	for (int i = 0; i < N; i++)
	{
		cin >> n[i];
	}

	for (int i = 0; i < N; i++)
	{
		auto [z,o] =  fibonacci(n[i]);
		cout << z << " " << o << endl;
	}
}

