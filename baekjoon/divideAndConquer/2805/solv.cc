#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

long long int N;
long long int M;
long long int tree[1000001];

int main(void){
	cin >> N >> M;
	long long int max = -1;
	for(int i=0; i<N; i++){
		scanf("%lld", &tree[i]);
		if(tree[i] > max) max = tree[i];
	}

	long long int start = 0, end = max;
	long long int mid;
	while(start <= end){
		long long int sumTree = 0;
		mid = (start+end)/2;
		for(int i=0; i<N; i++){
			if(tree[i] > mid) sumTree += tree[i] - mid;
		}
		if(sumTree >= M){
			start = mid + 1;
		}
		else if(sumTree < M){
			end = mid - 1;
		}
	}
	
	printf("%lld", end);
	return 0;
}
