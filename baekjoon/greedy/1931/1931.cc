#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct meetingTime_{
	int st;
	int et;
} meetingTime;

bool MTsort(const meetingTime &a, const meetingTime &b){
	if(a.et == b.et)
		return a.st < b.st;
	return a.et < b.et;
}

int printBiggestTime(vector<meetingTime> &MT, int N){
	int ct = 0;
	int MTcnt = 0;

	sort(MT.begin(), MT.end(), MTsort);
	for(vector<meetingTime>::iterator i = MT.begin(); i != MT.end(); i++){
		if(i->st >= ct){
			MTcnt++;
			ct = i->et;
		}
	}
	return MTcnt;
}

int main(void)
{
	int N;
	cin >> N;
	vector<meetingTime> MT;
	MT.resize(N);
	for(int i=0;i<N;i++){
		cin >> MT[i].st >> MT[i].et;
	}

	cout << printBiggestTime(MT, N);
	return 0;
}
