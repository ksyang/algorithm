#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int n, m;
	vector<vector<long long int > > box;
	vector<vector<bool > > ping;
	cin >> n >> m;

	box.resize(n);
	ping.resize(n);
	for(int i=0; i<n; i++){
		box[i].resize(m);
		ping[i].resize(m);
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> box[i][j];
			ping[i][j] = false;
		}
	}
	long long int allSum = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			allSum+=box[i][j];
		}
	}

	long long int sum = 0;
	for(int i=0 ;i<n; i++){
		long long int maxNum = -1;
		int xPos, yPos;
		for(int j=0; j<m; j++){
			if(box[i][j] > maxNum){
				maxNum = box[i][j];		
				xPos = i;
				yPos = j;
			}
		}
		ping[xPos][yPos] = true;
		sum += maxNum;
	}
	for(int j=0 ;j<m; j++){
		long long int maxNum = -1;
		int xPos, yPos;
		for(int i=0; i<n; i++){
			if(box[i][j] > maxNum){
				maxNum = box[i][j];
				xPos = i;
				yPos = j;
			}
		}
		if(ping[xPos][yPos] == false){
			sum += maxNum;
		}
	}
	cout << allSum - sum;
	return 0;
}
