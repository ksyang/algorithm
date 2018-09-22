#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void){
	int n, w, L;
	int weight[1001];
	queue<int> Q;

	cin >> n >> w >> L;

	for(int i=0; i<n; i++){
		cin >> weight[i];
	}

	int cnt = 0;
	int idxW = 0;
	int sSize = 0;

	for(int i=0; i<w; i++){
		Q.push(0);
	}

	for(int i=0; i<n*w; i++){
		sSize -= Q.front();
		Q.pop();
		if(sSize + weight[idxW] <= L && idxW < n){
			Q.push(weight[idxW]);
			sSize += Q.back();
			idxW++;
		} else {
			Q.push(0);
		}
		if(sSize == 0) break;
		cnt++;
	}
	cout << cnt+1;
	return 0;
}
