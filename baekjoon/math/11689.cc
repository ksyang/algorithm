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
			while(n%i == 0){
				n /= i;
			}
		}
	}

	if(n != 1){
		euler /= n;
		euler *= n-1;
	}
	return euler;
}

int main(void){
	long long n;
	scanf("%lld", &n);
	long long euler = get_euler(n);
	printf("%lld\n", euler);
	return 0;
}
