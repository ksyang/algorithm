#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	vector<int> sports;
	int num, result = 1, sum = 0, sumR = 0;
	
	cin >> num;
	sports.resize(num);

	for(int i=0; i<num; i++){
		cin >> sports[i];
		sum+=sports[i];
	}
	
	for(int i=1; i<=num-1; i++){
		sumR+=i;
	}

	if(sum!=sumR){
		result = -1;	
	}
	else{
		vector<int>::iterator it = sports.begin();
		for(int i=0; i<num; i++){
			sort(it, sports.end());
			it++;
	
			int loseCnt = num - i - sports[i] - 1;
			for(int j=1; j<=loseCnt ;j++){
				sports[num-j]--;
				if(sports[num-j] < 0){
					result = -1;
					break;
				}
			}
		}
	}
	cout << result;
	return 0;
}
