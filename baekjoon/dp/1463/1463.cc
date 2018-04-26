#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<int> dp;

int getMinAction(int n){
	if(n == 1) return 0;

	if(dp[n] != 0) return dp[n];

	int minAction = INT_MAX;
	if(n%2 == 0) minAction = min(getMinAction(n/2), minAction);
	if(n%3 == 0) minAction = min(getMinAction(n/3), minAction);
	minAction = min(getMinAction(n-1), minAction);

	dp[n] = minAction + 1;

	return dp[n];
}

int main(void)
{
	int n;
	cin >> n;
	dp.resize(n+1);

	cout << getMinAction(n);
	return 0;
}
