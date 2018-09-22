#include <iostream>
#include <algorithm>

using namespace std;

int n[10001];
int sub[6];

int main(void){
	int N;
	int sublen = 0;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> n[i];
	}

	sort(n, n+N);

	if(N>=5){
		sublen = 5;
		sub[0] = n[0];
		sub[1] = n[1];
		sub[2] = n[N-3];
		sub[3] = n[N-2];
		sub[4] = n[N-1];
	}
	else if(N = 4){
		sublen=4;
		for(int i=0; i<4; i++){
			sub[i] = n[i];	
		}
	}
	else if(N = 3){
		sublen=3;
		for(int i=0; i<3; i++){
			sub[i] = n[i];	
		}
	}
	int flag = 0;
	int twoMax;
	for(int i=0; i<sublen-1; i++){
		for(int j=i+1; j<sublen; j++){
			if(flag == 0){
				flag = 1;
				twoMax = sub[i]*sub[j];
			}
			else
				twoMax = max(sub[i]*sub[j], twoMax);
		}
	}
	for(int i=0; i<sublen-2; i++){
		for(int j=i+1; j<sublen-1; j++){
			for(int t=j+1; t<sublen; t++){
				twoMax = max(sub[i]*sub[j]*sub[t], twoMax);
			}
		}
	}
	cout << twoMax;
	return 0;
}
