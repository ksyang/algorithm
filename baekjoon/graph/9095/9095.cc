#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;

void dfs(int n){
	if(n < 0) return;
	if(n == 0) { cnt++; return; }
	for(int i=1;i<4;i++){
		dfs(n - i);
	}
	return;
}

int main(void)
{
	int T, N;

	cin >> T;

	while(T--){
		cnt = 0;
		cin >> N;
		dfs(N);
		cout << cnt << endl;
	}
	return 0;
}
