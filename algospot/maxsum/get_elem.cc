#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cmath>

using namespace std;

int N[100001];

int main(void) {
	int T;
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N[i];
	}

	int result = 0;
	int cur_sum = 0;
	for(int i=0; i<T; i++){
		cur_sum = max(0, cur_sum) + N[i];
		result = max(result, cur_sum);
	}
	cout << result;
	return 0;
}
