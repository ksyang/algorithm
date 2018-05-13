#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int T;
	int caseCnt = 0;

	cin >> T;
	while(T--){
		int N, J;
		vector<int> rock;
		caseCnt++;
		cin >> N;
		rock.resize(N);
		for(int i=0; i<N; i++){
			cin >> rock[i];
		}
		cin >> J;
		
		int curPos = 0;
		int jmpCnt = 0;
		for(int i=0; i<N; i++){
			if((rock[i] - curPos) <= J){
				if(i < (N-1) && (rock[i+1] - curPos) <= J){
					continue;
				}
				curPos = rock[i];
				jmpCnt++;
			} else {
				jmpCnt = -1;
				break;
			}
		}
		
		cout << "Case #" << caseCnt << '\n';
		cout << jmpCnt << '\n';
	}
	return 0;
}
