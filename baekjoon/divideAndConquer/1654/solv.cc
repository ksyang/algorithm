#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void){
	int K, N;
	int lan[10001];

	cin >> K >> N;
	int maxLen = -1;
	for(int i=0; i<K; i++){
		scanf("%d", &lan[i]);
		if(lan[i] > maxLen) maxLen = lan[i];
	}

	int start = 0, end = maxLen;
	int mid = 0;
	while(start <= end){
		int sumLan = 0;
		mid = (start+end)/2;
		for(int i=0; i<K; i++){
			sumLan += lan[i]/mid;
		}
		if(sumLan >= N)
			start = mid + 1;
		else
			end = mid - 1;
	}
	printf("%d", end);
	return 0;
}
