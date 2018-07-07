#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dp[10000];

int getBest(int P[], int Q[], int N) {
	if(N == 0) {
		dp[N] = max(P[N], Q[N]);
		return dp[N];
	}
	if(N == -1) return 0;
	if(dp[N] == 0) {
		dp[N] = max(P[N] + getBest(P, Q, N-1), Q[N] + getBest(P, Q, N-2));
		return dp[N];
	}
	return dp[N];
}

int main(void) {
  int T, caseCnt = 0;

	cin >> T;
	while(T--){
		memset(dp, 0, sizeof(int)*10000);
		caseCnt++;
		int N;
		cin >> N;
		int P[10000], Q[10000];
		
		for(int i=0; i<N; i++){
			cin >> P[i];
		}

		for(int i=0; i<N; i++){
			cin >> Q[i];
		}

		cout << "Case #" << caseCnt << "\n";
		cout << getBest(P, Q, N-1) <<"\n";
	}
	return 0;
}
