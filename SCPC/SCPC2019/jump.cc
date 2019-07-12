#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int Answer;

int getResult(int N){
	int cnt=0, tmp;
	while(N>1){
		cnt++;
		tmp = (sqrt(1+8*N)-1)/2;
		cnt += tmp;
		N -= tmp;
		printf("%d\n", N);
	}
	return cnt;
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		Answer = 0;
		int maxValue = getResult(x);
		for(int i=x+1; i<=y; i++){
			printf("get %d-----------", i);
			maxValue = max(maxValue, getResult(i));
		}
		cout << "Case #" << test_case+1 << endl;
		cout << maxValue << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
