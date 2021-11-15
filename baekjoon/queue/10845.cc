#include <stdio.h>
#include <queue>
#include <string>

using namespace std;

int main(void){
	int cnt;
	queue<int> q;
	string tmp;
	char s[10001];

	scanf("%d", &cnt);

	while(cnt--){
		scanf("%s", s);
		tmp = s;
		if(tmp == "push"){
			int n;
			scanf("%d", &n);
			q.push(n);
		} else if(tmp == "pop"){
			if(q.empty()){
				printf("-1\n");
				continue;
			}
			printf("%d\n", q.front());
			q.pop();
		} else if(tmp == "size"){
			printf("%d\n", q.size());
		} else if(tmp == "empty"){
			printf("%d\n", q.empty());
		} else if(tmp == "front"){
			if(q.empty()){
				printf("-1\n");
				continue;
			}
			printf("%d\n", q.front());
		} else if(tmp == "back"){
			if(q.empty()){
				printf("-1\n");
				continue;
			}
			printf("%d\n", q.back());
		}




	}
	return 0;
}
