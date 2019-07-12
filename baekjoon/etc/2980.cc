#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int N, L;
	int D[101], R[101], G[101];

	cin >> N >> L;

	D[0]=R[0]=G[0]=0;
	for(int i=1; i<=N; i++){
		cin >> D[i] >> R[i] >> G[i];
	}

	int sLoc=0;
	for(int i=1; i<=N; i++){
		sLoc += D[i]-D[i-1];
		int modP = sLoc%(R[i]+G[i]);
		if(modP < R[i])
			sLoc += R[i]-modP;
	}
	sLoc += L-D[N];

	cout << sLoc;
	return 0;
}
