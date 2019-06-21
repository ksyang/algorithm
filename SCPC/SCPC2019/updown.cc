/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int Answer;
int dp[1000004];
int sum[1000004];

int main(int argc, char** argv)
{
	int T, test_case;
	int S, E;

	for(int i=0; i<1000003; i++){
		dp[i] = 0;
		sum[i] = 0;
	}
	
	dp[2]=1;
	sum[1]=0;
	sum[2]=1;
	for(int i=4; i<1000003; i+=2){
		dp[i] = dp[i/2]+1;
		dp[i-1] = dp[i]+1;
		sum[i-1] = sum[i-2] + dp[i-1];
		sum[i] = sum[i-1] + dp[i];
	}

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		scanf("%d %d", &S, &E);
		Answer = sum[E] - sum[S-1];
		// Print the answer to standard output(screen).
		printf("Case #%d\n%d\n", test_case+1, Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}
