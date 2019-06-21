#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int N, M;
	int num[10001];
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> num[i];
	}

	int result=0;
	for(int i=0; i<N; i++){
		int sum=0;
		for(int j=i; j<N; j++){
			sum+=num[j];
			if(sum==M) {
				result++;
				break;
			}
			if(sum > M) break;
		}
	}
	cout << result << '\n';
}
