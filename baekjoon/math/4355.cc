#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> divisor;

int get_euler(int N){
	int i, cnt=0;
	int n = N, euler = N;
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
	int n;
	while(1){
		scanf("%d", &n);
		if(n == 0) break;
		int euler = get_euler(n);
		if(euler == 1) euler=0;
		printf("%d\n", euler);
	}
	return 0;
}
