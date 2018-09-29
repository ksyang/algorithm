#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define MAXFILE 2100000000

using namespace std;

int page[501];
int dp[501][501];
int sum[502];
int K;

int getPage(int start, int end){
	if(end-start == 1)
		dp[start][end] = page[start]+page[end];

	if(dp[start][end] != -1) return dp[start][end];

	int minFile = MAXFILE;
	for(int i=1; i<=end-start; i++){
		minFile = min(minFile, getPage(start, start+i-1) + getPage(start+i, end) + sum[end+1] - sum[start]);
	}
	dp[start][end] = minFile;
	return dp[start][end];
}

int main(void){
	int T;
	cin >> T;
	while(T--){
		scanf("%d", &K);
		for(int i=0; i<501; i++){
			for(int j=0; j<501; j++){
				dp[i][j] = -1;
				sum[i] = 0;
			}
		}
		sum[0] = 0;
		for(int i=0; i<K; i++){
			scanf("%d", &page[i]);
			dp[i][i] = 0;
			sum[i+1] = sum[i] + page[i];
		}
		printf("%d\n", getPage(0, K-1));
	}
	return 0;
}
