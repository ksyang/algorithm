#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool sortSec(const pair<int, int> &a, const pair<int, int> &b){
	if(a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}

int main(void){
	int T;
	int caseNum = 0;

	cin >> T;
	while(T--){
		int N, L;
		int idx = 0;
		int leftP = 0;
		vector< pair<int, int> > preChooseLanguage;		//first arg is choosen people, second arg is nearest upper.
		
		cin >> N >> L;
		
		leftP = N;
		
		caseNum++;

		preChooseLanguage.resize(L+1);
		
		for(int i=0; i<L; i++){
			cin >> preChooseLanguage[i].first;
			leftP -= preChooseLanguage[i].first;
		}
		preChooseLanguage[L].first = 0;	
		
		for(int i=0; i<=L; i++){
			for(float j=0; j<=(N - preChooseLanguage[i].first); j++){
				float calc = (preChooseLanguage[i].first + j) / N * 100;
				if(int(calc + 0.5) > int(calc)){
					preChooseLanguage[i].second = j;
					break;
				}
				if(j == N - preChooseLanguage[i].first){
					preChooseLanguage[i].second = -1;
				}
			}
		}

		sort(preChooseLanguage.begin(), preChooseLanguage.end(), sortSec);

		//for(int i=0; i<=L; i++){
			//cout << preChooseLanguage[i].first << ' ' << preChooseLanguage[i].second << endl;
		//}

		int sumPercentage = 0;
		for(int i=0; i<=L; i++){
			float tmp;

			if(preChooseLanguage[i].second == -1){
				tmp = float(preChooseLanguage[i].first) / N * 100;
				sumPercentage += int(tmp+0.5);
				continue;
			}
			if(preChooseLanguage[i].first == 0){
				while(leftP-preChooseLanguage[i].second > 0){
					leftP -= preChooseLanguage[i].second;
					tmp = float(preChooseLanguage[i].first + preChooseLanguage[i].second) / N * 100;
					sumPercentage += int(tmp+0.5);
				}
			}
			if(preChooseLanguage[i].second <= leftP){
				leftP -= preChooseLanguage[i].second;
				tmp = float(preChooseLanguage[i].first + preChooseLanguage[i].second) / N * 100;
				sumPercentage += int(tmp+0.5);
			} else {
				tmp = float(preChooseLanguage[i].first) / N * 100;
				sumPercentage += int(tmp+0.5);
			}
		}

		if(leftP > 0){
			sumPercentage += float(leftP) / N * 100;
		}

		cout << "Case #" << caseNum << ": " << sumPercentage << '\n';
	}
	return 0;
}
