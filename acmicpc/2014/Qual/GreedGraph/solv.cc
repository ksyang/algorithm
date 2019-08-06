#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void){
	int T;
	cin >> T;
	while(T--){
		int m, n;
		cin >> m >> n;
		cout << "1\n";
		if(m%2 == 0){
			for(int i=0; i<m; i++){
				if(i%2 == 0){
					for(int j=0; j<n; j++){
						printf("(%d,%d)\n",i ,j);
					}
				} else {
					for(int j=n-1; j>=0; j--){
						printf("(%d,%d)\n",i ,j);
					}
				}
			}
		} else {
			for(int i=0; i<m; i++){
				if(i%2 == 0){
					for(int j=1; j<n; j++){
						printf("(%d,%d)\n",i ,j);
					}
				} else {
					for(int j=n-1; j>=1; j--){
						printf("(%d,%d)\n",i ,j);
					}
				}
			}
			for(int i=m-1; i>=0; i--){
				printf("(%d,0)\n",i);
			}
		}
	}
	return 0;
}
