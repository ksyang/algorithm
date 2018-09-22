#include <iostream>

using namespace std;

bool is_loop[1000] = {0,};

int getFNum(int N){
	int f_num = 0;
	while(N){
		int n;
		n = N%10;
		f_num += n*n;
		N /= 10;
	}
	return f_num;
}

int main(void){
	int N;
	int f_num;

	cin >> N;

	f_num = getFNum(N);
	while(1){
		f_num = getFNum(f_num);
		if(f_num == 1){
			cout << "HAPPY";
			break;
		}
		if(is_loop[f_num]){
			cout << "UNHAPPY";
			break;
		}
		is_loop[f_num] = 1;
	}
	return 0;
}
