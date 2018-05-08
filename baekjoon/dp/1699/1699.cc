#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100001];

int dpSN(int n){
	if(n == 0) return 0;
	
	if(dp[n] != n+1) return dp[n];

	for(int i=1; i*i <= n; i++){
		dp[n] = min(dp[n], dpSN(n - i*i) + 1);
	}
	return dp[n];
}

int main(void){
	int N;
	cin >> N;
	for(int i=0; i<100001; i++) dp[i] = i+1;
	dpSN(N);
	cout << dp[N];
	return 0;
}
