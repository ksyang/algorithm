#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int divisor[10001];
int cnt=0;

void get_divisor(int N){
	int i, tmp;
	for(i=1; i<=sqrt(N); i++){
		if(N%i == 0){
			divisor[cnt] = i;
			cnt++;
			if(i * i == N) continue;
			divisor[cnt] = N/i;
			cnt++;
		}
	}
	sort(divisor, divisor+cnt);
}

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	get_divisor(N);
	if(cnt<K){
		printf("0");
	}
	else{
		printf("%d", divisor[K-1]);
	}
	return 0;
}
