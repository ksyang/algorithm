#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> divisor;

long long get_euler(long long N){
	long long i, cnt=0;
	long long n = N, euler = N;
	for(i=2; i<=sqrt(N); i++){
		if(n%i == 0){
			euler /= i;
			euler *= i-1;
			while(n%i == 0) n /= i;
		}
	}

	if(n > 1){
		euler /= n;
		euler *= n-1;
	}
	return euler;
}

void get_divisor(long long N){
	long long i;
	for(i=1; i<=sqrt(N); i++){
		if(N%i == 0){
			divisor.push_back(i);
			if(i * i == N) continue;
			divisor.push_back(N/i);
		}
	}
}

int main(void){
	long long n;

	scanf("%lld", &n);

	if(n==1 || n==2){
		printf("%lld\n", n);
		return 0;
	}

	get_divisor(n);

	for(auto it = divisor.begin(); it != divisor.end(); it++){
		if(get_euler(*it) == n / *it){
			printf("%lld\n", *it);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
