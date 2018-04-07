#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long int> dp;
int n;
long long int method = 0;

long long int tile(int num){
	long long int cases = 0;
	if(num == 1)
		return 1;
	if(num == 2)
		return 3;
	if(dp[num-1] != 0){
		cases += dp[num-1];
	}
	else{
		dp[num-1] = tile(num-1);
		cases += dp[num-1];
		
	}
	if(dp[num-2 != 0]){
		cases += dp[num-2];
	}
	else{
		dp[num-2] = tile(num-2) * 2;
		cases += dp[num-2];
	}
	return cases % 10007;
}

int main(void)
{
	cin >> n;
	dp.resize(n);
	cout << tile(n) % 10007;
	return 0;
}
