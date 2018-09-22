#include <iostream>
#include <algorithm>

using namespace std;

int page[501];
int dp[501][501] = {{0,},};
int N;

int getPage(int s, int d){
	if(dp[s][d]) return dp[s][d];
	if(pow(s-d) == 1) return page[s] + page[d];
	int minPage = ;
	for(int i=s; i<d; i++){
		minPage = min(minPage, getPage(s, i) + getPage(i, d));
	}
	
	return minPage;
}

int main(void){
	int T;
	cin >> T;
	while(T--){
		cin >> N;
		for(int i=0; i<N; i++){
			cin >> page[i];
		}
		cout << getPage(0, N-1);
	}
	return 0;
}
