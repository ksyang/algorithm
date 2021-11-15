#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cmath>

using namespace std;

int F[20002];

int getLargeFence(int l, int r) {
	if(l == r) return F[l];

	int mid = (l+r)/2;
	int largeFence = max(getLargeFence(l, mid), getLargeFence(mid+1, r));

	int pivL = mid;
	int pivR = mid+1;

	int minHeight = min(F[pivL], F[pivR]);
	largeFence = max(minHeight * 2, largeFence);

	while(l < pivL || pivR < r){
		if(pivR < r && (l==pivL || F[pivL-1] < F[pivR+1])){
			pivR++;
			minHeight = min(minHeight, F[pivR]);
		} else {
			pivL--;
			minHeight = min(minHeight, F[pivL]);
		}
		largeFence = max(largeFence, minHeight * (pivR - pivL + 1));
	}
	return largeFence;
}

int main(void) {
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> F[i];
	}
	cout << getLargeFence(0, N-1) << endl;
	return 0;
}
