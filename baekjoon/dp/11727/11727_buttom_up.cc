#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(void)
{
	int n, dp[1001];
	cin >> n;
	
	dp[0] = 1;
	dp[1] = 3;

	for(int i=2; i<n; i++){
		dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007;
	}

	cout << dp[n-1];
	return 0;
}
