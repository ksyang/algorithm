#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getEqualNumber(int N){
	for(int i=0; i<N; i++){
		rem = N;
		en = rem % i;
		while(1){
			if(rem < i) break;
			if(rem != i) break;
			rem = rem / i;
			en = rem % i;
			
		}
	}
}

int main(void){
	int T;

	cin >> T;
	for(int caseNum = 1; caseNum <= T; caseNum++){
		int N;
		cin >> N;
		int equalNumber = 0;
		for(int i=0; i<N; i++){
			equalNumber = getEqualNumber(N);
		}
		cout << "Case #" << caseNum << '\n';
		cout << '\n';
	}
	return 0;
}
