#include <iostream>
#include <algorithm>

using namespace std;

long long int getDeviation(dolls, pos, len){
	
}

int main(void){
	int N, K;
	int dolls[501];
	cin >> N >> K;
	for(int i=0; i<N; i++){
		cin >> dolls[i];
	}

	int minDiv;
	int flag = 0;
	for(int len=K; len<=N; len++){
		for(int pos=0; pos<=N-len; pos++){
			if(flag == 0){
				minDiv = getDeviation(dolls, pos, len);
				flag = 1;
			}
			else min(minDiv, getDeviation(dolls, pos, len))
		}
	}
	return 0;
}
