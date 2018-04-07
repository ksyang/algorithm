#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<int> > triangle;
vector< vector<int> > dp;
int n;

int maxsum(int x, int y){
	if(x == n - 1) return triangle[x][y];
	if(!dp[x][y])
		dp[x][y] = max(maxsum(x+1, y+1) + triangle[x][y], maxsum(x+1, y) + triangle[x][y]);
	return dp[x][y];
}

int main(void)
{
	cin >> n;
	triangle.resize(n);
	dp.resize(n);
	for(int i=0; i<n; i++){
		triangle[i].resize(n);
		dp[i].resize(n);
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<i+1; j++){
			cin >> triangle[i][j];
		}
	}
	cout << maxsum(0, 0);
	return 0;
}
