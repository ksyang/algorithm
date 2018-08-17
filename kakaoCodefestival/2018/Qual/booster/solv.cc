#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, Q;
vector<pair<int, pair<int, int > > > initCoord;
vector<pair<int, pair<int, int > > > coordX;
vector<pair<int, pair<int, int > > > coordY;
bool visited[250005];

bool cmpX(const pair<int, pair<int, int> > &i, const pair<int, pair<int, int> > &j){
	return i.second.first < j.second.first;
}

bool cmpY(const pair<int, pair<int, int> > &i, const pair<int, pair<int, int> > &j){
	return i.second.second < j.second.second;
}

bool isPossible(int src, int dest, int hp){
	q.push();
}

int main(void){
	cin >> N >> Q;
	initCoord.resize(N);
	coordX.resize(N);
	coordY.resize(N);

	for(int i=0; i<N; i++){
		initCoord[i].first = i+1;
		cin >> initCoord[i].second.first;
		cin >> initCoord[i].second.second;

		coordX[i].second.first = coordY[i].second.first = initCoord[i].second.first;
		coordX[i].second.second = coordY[i].second.second = initCoord[i].second.second;
	}

	sort(coordX.begin(), coordX.end(), cmpX);
	sort(coordY.begin(), coordY.end(), cmpY);
	
	int src, dest, hp;
	for(int i=0; i<Q; i++){
		for(int j=0; j<250005; j++){
			visited[j] = false;
		}
		cin >> src >> dest >> hp;
		if(isPossible(src, dest, hp)) cout << "YES";
		else cout << "NO";
	}
	return 0;
}
