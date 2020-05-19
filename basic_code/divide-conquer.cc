#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cmath>

using namespace std;

int getSum(int N) {
	if(N == 1) return 1;

	if(N % 2 == 0) {
		return (getSum(N/2) * 2) + pow(N/2, 2);
	} else {
		N++;
		return (getSum(N/2) * 2) + pow(N/2, 2) - N;
	}
}

int main(void) {
	int N;
	cin >> N;

	cout << getSum(N);
	return 0;
}
