#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void){
	int T, caseCnt = 0;
	
	cin >> T;
	while(T--){
		vector<int> people;
		int peopleNum, k;
		caseCnt++;
		
		cin >> peopleNum;
		cin >> k;

		people.resize(peopleNum);
		for(int i=0; i<peopleNum; i++){
			cin >> people[i];
		}

		sort(people.begin(), people.end());
		
		int maxBus = 0;
		
		vector<int>::iterator iter;
		vector<int>::iterator lb;

		for(iter = people.begin(); iter != people.end(); iter++){
			lb = lower_bound(iter, people.end(), *iter+k+1);
			int dis = distance(iter, lb);
			maxBus = max(maxBus, dis);
		}

		cout << "Case #" << caseCnt << "\n";
		cout << maxBus <<"\n";
	}
	return 0;
}
