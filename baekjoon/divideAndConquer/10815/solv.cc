#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int A[500001];
int N;

bool isExist(int tmp){
	int start, end, mid;
	bool flag = false;
	start = 0;
	end = N-1;
	while(start <= end){
		mid = (start+end)/2;
		if(A[mid] > tmp){
			end = mid-1;
		}
		else if(A[mid] < tmp){
			start = mid+1;
		} else {
			flag = true;
			break;
		}
	}
	return flag;
}

int main(void){
	cin >> N;
	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
	sort(A, A+N);
	int M;
	cin >> M;
	for(int i=0; i<M; i++){
		int tmp;
		scanf("%d", &tmp);
		printf("%d ", isExist(tmp));
	}
	return 0;
}
