#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int A[100001];

bool isExist(int isN){
	int start, end;
	bool flag = false;
	start = 0;
	end = N-1;
	while(start <= end){
		if(A[(start + end)/2] < isN) {
			start = (start + end)/2+1;
		}
		else if(A[(start + end)/2] > isN) {
			end = (start + end)/2-1;
		} else {
			flag = true;
			break;
		}
	}
	return flag;
}

int main(void){
	int M;
	cin >> N;
	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}

	sort(A, A+N);

	cin >> M;
	for(int i=0; i<M; i++){
		int isN;
		scanf("%d", &isN);
		printf("%d\n", isExist(isN));
	}
	return 0;
}
