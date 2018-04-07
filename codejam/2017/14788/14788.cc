#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int len = 0;

void flop(int *cake, int n, int K){
	for(int i=0; i<K; i++){
			cake[n+i] = !cake[n+i];
	}
}

int doCake(int *cake, int K){
	int flopNum = 0;
	for(int i=0; i<=len - K; i++){
		if(cake[i] == 0){
			flop(cake, i, K);
			//for(int j=0;j<len;j++)
			//	cout << cake[j];
			//cout <<endl;
			flopNum++;
		}
	}

	for(int i=len-K;i<len;i++){
		if(cake[i] == 0) return -1;
	}

	return flopNum;
}

int main(void)
{
	int t;
	int caseNum = 0;
	cin >> t;
	while(t--){
		int cake[1000];
		int K;
		char pm;
		len = 0;
		caseNum++;
		getchar();
		for(int i=0; i<1001; i++){
			pm = getchar();
			if(pm == ' ') break;
			if(pm == '-') cake[i] = 0;
			if(pm == '+') cake[i] = 1;
			len++;
		}
		cin >> K;
		int res = doCake(cake, K);
		cout << "Case #" << caseNum << ": ";
		if(res == -1) cout << "IMPOSSIBLE\n";
		else cout << res << '\n';
	}
	return 0;
}
