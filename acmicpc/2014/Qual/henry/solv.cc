#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int getInit(int b, int a){
	return (int)ceil((double)b/a);
}

int main(void){
	int T;
	cin >> T;
	while(T--){
		int a, b;
		scanf("%d %d", &a, &b);
		int Atmp, Btmp;
		int x1 = getInit(b, a);
		Atmp = a;
		a = a*x1-b;
		Btmp = b;
		b = b*x1;
		while(1){
			if(a==0) break;
			x1 = getInit(b, a);
			Atmp = a;
			a = a*x1-b;
			Btmp = b;
			b = b*x1;
		}
		printf("%d\n", Btmp/Atmp);
	}
	return 0;
}
