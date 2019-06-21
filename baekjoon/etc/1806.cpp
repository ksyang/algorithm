#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int N, S;
	int num[100001];
	cin >> N >> S;
	for(int i=0; i<N; i++){
		cin >> num[i];
	}

	int start=0, end=0;
	int sum=num[0];
	int minLen=100001;
	while(start <= end && end < N){
		if(sum<S) {
			end++;
			sum+=num[end];
		}
		else {
			if(end - start + 1 < minLen) minLen = end - start + 1;
			sum-=num[start];
			start++;
		}
	}
	
	if(minLen == 100001) minLen = 0;

	cout << minLen;
}
