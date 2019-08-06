#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void){
	int n;
	char s[101];
	int numEight = 0;
	cin >> n;
	cin >> s;
	for(int i=0; i<n; i++){
		if(s[i] == '8') numEight++;
	}
	int tmpCnt = n/11;
	printf("%d", min(tmpCnt, numEight));
	return 0;
}
