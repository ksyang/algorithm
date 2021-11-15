#include <stdio.h>
int main(void)
{
	int N;
	int min;
	int max;
	int tmp;
	int i=0;
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", &tmp);
		if(i==0){
			min = tmp;
			max = tmp;
			continue;
		}
		if(min > tmp) min = tmp;
		if(max < tmp) max = tmp;
	}
	printf("%d", min*max);
}
