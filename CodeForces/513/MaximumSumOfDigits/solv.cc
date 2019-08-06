#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void){
	long long int n;
	int cnt = 0;
	cin >> n;
	while(1){
		int tmp = (n%10)+10;
		if(tmp == 19) tmp = 9;
		if(n >=10) cnt += tmp;
		else{
			cnt += n;
			break;
		}
		n = (n-tmp)/10;
	}
	cout << cnt;
	return 0;
}
