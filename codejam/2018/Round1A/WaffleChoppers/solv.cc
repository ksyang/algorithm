#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int R, C;
int H, V;
int sumChoco = 0;

int checkRow(bool cake[][101], int *rowPartition){
	int sumArray[101];
	int partitionSum = 0;
	int partition = 0;
	int rowPartitionIDX = 0;

	sumChoco = 0;

	memset(sumArray, 0, sizeof(int) * R);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			sumArray[i] += cake[i][j];
			sumChoco += cake[i][j];
		}
		if(i != 0) sumArray[i] += sumArray[i-1];
	}

	if(sumChoco % (H+1) != 0) return -1;
	partition = partitionSum = sumChoco / (H+1);

	rowPartition[rowPartitionIDX] = 0;
	rowPartitionIDX++;
	for(int i=0; i<R; i++){
		if(sumArray[i] > partitionSum) return -1;
		if(sumArray[i] == partitionSum){
			rowPartition[rowPartitionIDX] = i+1;
			rowPartitionIDX++;
			partitionSum += partition;
		}
	}
	return 0;
}

int checkColumn(bool cake[][101], int *columnPartition){
	int sumArray[101];
	int partitionSum = 0;
	int partition = 0;
	int columnPartitionIDX = 0;

	sumChoco = 0;

	memset(sumArray, 0, sizeof(int) * C);
	for(int i=0; i<C; i++){
		for(int j=0; j<R; j++){
			sumArray[i] += cake[j][i];
			sumChoco += cake[j][i];
		}
		if(i != 0) sumArray[i] += sumArray[i-1];
	}

	if(sumChoco % (V+1) != 0) return -1;
	partition = partitionSum = sumChoco / (V+1);

	columnPartition[columnPartitionIDX] = 0;
	columnPartitionIDX++;
	for(int i=0; i<C; i++){
		if(sumArray[i] > partitionSum) return -1;
		if(sumArray[i] == partitionSum){
			columnPartition[columnPartitionIDX] = i+1;
			columnPartitionIDX++;
			partitionSum += partition;
		}
	}
	return 0;
}

int checkPartition(bool cake[][101], int *rowPartition, int *columnPartition){
	int chocoCnt = 0;
	for(int i=1; i<=H+1; i++){
		for(int j=1; j<=V+1; j++){
			chocoCnt = 0;
			for(int x=rowPartition[i-1]; x<rowPartition[i]; x++){
				for(int y=columnPartition[j-1]; y<columnPartition[j]; y++){
					if(cake[x][y] == 1) chocoCnt++;
				}
			}
			if(chocoCnt != sumChoco / (H+1+V+1)) return -1;
		}
	}
}

int main(void)
{
	int T;
	int caseNum = 0;

	cin >> T;
	while(T--){
		int rowPartition[101];
		int columnPartition[101];
		bool cake[101][101];
		char tmp;
		
		cin >> R >> C >> H >> V;

		caseNum++;

		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				cin >> tmp;
				if(tmp == '.') cake[i][j] = 0;
				else if(tmp == '@') cake[i][j] = 1;
			}
		}
		
		cout << "Case #" << caseNum << ": ";
		if(checkRow(cake, rowPartition) == -1){ cout << "IMPOSSIBLE\n"; continue; }
		if(checkColumn(cake, columnPartition) == -1){ cout << "IMPOSSIBLE\n"; continue; }
		if(checkPartition(cake, rowPartition, columnPartition) == -1){ cout << "IMPOSSIBLE\n"; continue; }
		cout << "POSSIBLE\n";
	}
	return 0;
}
