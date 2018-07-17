#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <functional>

using namespace std;

int palindrome[199];

bool checkPalin(int n){
	char num[100];
	sprintf(num, "%d", n);
	for(int i=0; i<strlen(num)/2; i++){
		if(num[i] != num[strlen(num)-i-1])
			return 0;
	}
	return 1;
}

int main(void){
	setbuf(stdout, NULL);
	int T, caseCnt;

	cin >> T;

	int palinNum = 0;
	for(int i=1; i<=10000; i++){
		if(checkPalin(i)){
			palindrome[palinNum] = i;
			palinNum++;
		}
	}
	palindrome[198] = 0;

	while(T--){
		caseCnt++;
		
		int testNum;
		
		cin >> testNum;

		int out[3];
		memset(out, 0, 3);
		for(int i=0; i<199; i++){
			for(int j=0; j<199; j++){
				for(int z=0; z<199; z++){
					if((palindrome[i] + palindrome[j] + palindrome[z]) == testNum){
						out[0] = palindrome[i];
						out[1] = palindrome[j];
						out[2] = palindrome[z];
						break;
					}	
				}
			}
		}

		sort(out, out + 3, greater<int>());
		int cntNum = 0;
		for(int i=0; i<3; i++){
			if(out[i] != 0)
				cntNum++;
		}

		cout << "Case #" << caseCnt << "\n";
		cout << cntNum;
		for(int i=0; i<3; i++){
			if(out[i] != 0)
				cout << ' ' << out[i];
		}
		cout << "\n";
	}
	return 0;
}
