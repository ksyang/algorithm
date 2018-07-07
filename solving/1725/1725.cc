#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> histogram;

int findMaxSquare(int s, int f){
	if(s==f) return histogram[s];

	int maxSquare = max(findMaxSquare(s, (s+f)/2), findMaxSquare((s+f)/2+1, f));

	int pivot = min(histogram[(s+f)/2], histogram[(s+f)/2+1]);

	int maxArea = pivot*2;
	int kan=2;
	int lft = (s+f)/2-1, rit = (s+f)/2+2;
	while(lft != s-1 ||	rit != f+1){
		if(histogram[lft] > histogram[rit]){
			pivot = min(pivot, histogram[lft]);
			lft -=1;
			if(lft == s-2) lft=s-1;
		} else {
			pivot = min(pivot, histogram[rit]);
			rit += 1;
			if(rit == f+2) rit=f+1;
		}
		kan++;
		maxArea = max(maxArea, kan*pivot);
	}

	maxSquare = max(maxSquare, maxArea);
	return maxSquare;
}

int main(void){
	int N;

	cin >> N;
	histogram.resize(N);

	for(int i; i<N; i++){
		cin >> histogram[i];
	}
	cout << findMaxSquare(0, N-1);
	return 0;
}
