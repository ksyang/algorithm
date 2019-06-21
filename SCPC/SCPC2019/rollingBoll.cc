#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double Answer;

double rad2deg(double radian)
{
	    return radian*180/M_PI;
}

int main(int argc, char** argv)
{
	int T, test_case;
	int R, S, E, N;
	int l[1001], r[1001], h[1001];

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		scanf("%d %d %d", &R, &S, &E);
		scanf("%d", &N);
		Answer=E-S;
		for(int i=0; i<N; i++){
			scanf("%d %d %d", &l[i], &r[i], &h[i]);
			if(h[i] > R){
				Answer += 2 * h[i];
				Answer -= 4 * R;
				Answer += 2 * ((2 * R * M_PI) / 4.0);
			}
			else {
				Answer -= 2 * sqrt(pow(R, 2) - pow(R-h[i], 2));		//높이는 더할 필요가 없나?
				Answer += 2.0 * ((2 * R * M_PI) * (rad2deg(acos((R-h[i])/(double)R))/360.0));
			}
		}
		cout << "Case #" << test_case+1 << endl;
		printf("%.10lf", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}
