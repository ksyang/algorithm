#include <iostream>

using namespace std;

int main(void){
	int n;
	int r;
	cin >> n;
	n=n%8;
	if(n==1) r= 1;
	else if(n==2) r= 2;
	else if(n==3) r= 3;
	else if(n==4) r= 4;
	else if(n==5) r= 5;
	else if(n==6) r= 4;
	else if(n==7) r= 3;
	else if(n==0) r= 2;
	cout << r;
	return 0;
}
