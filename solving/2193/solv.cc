#include <iostream>
#include <cstdio>

using namespace std;

int N;
long long int dp[91];

long long int getNum(int n){
	if(dp[n] != -1) return dp[n];
	dp[n] = getNum(n-1) + getNum(n-2);
	return dp[n];
}

int main(void){
	cin >> N;

	for(int i=0; i<91; i++){
		dp[i] = -1;
	}

	dp[0] = 1;
	dp[1] = 1;
	
	cout << getNum(N-1);
	return 0;
}
