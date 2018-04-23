#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dp[1001];

int countTiling(int n){
	if(n == 1) return 1;
	if(n == 2) return 3;

	if(dp[n] == -1){
		dp[n] = (countTiling(n-1) + 2*countTiling(n-2)) % 10007;
	}

	return dp[n];
}

int main(void)
{
	int n;

	memset(dp, -1, 1001 * sizeof(int));
	cin >> n;
	cout << countTiling(n);
	return 0;
}
