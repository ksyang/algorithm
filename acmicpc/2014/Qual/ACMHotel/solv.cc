#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void){
	int T;
	cin >> T;
	while(T--){
		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);
		if(N%H == 0) printf("%d%02d\n", H, (int)ceil((double)N/H));
		else printf("%d%02d\n", N%H, (int)ceil((double)N/H));
	}
	return 0;
}
