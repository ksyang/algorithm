#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void){
	int n;
	int ind[1001];
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> ind[i];
	}

	sort(ind, ind + n);

	for(int i=0; i<10000; i++){
		if(n-(lower_bound(ind, ind+n, i)-ind) >= i){
			if(n-(upper_bound(ind, ind+n, i)-ind) <= i){
				printf("%d", i);
				return 0;
			}
		}
	}
	return 0;
}
