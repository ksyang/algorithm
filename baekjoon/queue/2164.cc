#include <stdio.h>
#include <queue>

using namespace std;

int main(void){
	queue<int> q;
	int n;
	scanf("%d", &n);

	for(int i=1; i<n+1; i++){
		q.push(i);
	}

	for(int i=0; i<n-1; i++){
		q.pop();
		q.push(q.front());
		q.pop();
	}

	printf("%d", q.front());
	return 0;
}
