#include <iostream>

using namespace std;

int s[12];

bool checkresult(){
	if(s[1] + s[2] + s[3] + s[4] != 26) return false;
	if(s[0] + s[2] + s[5] + s[7] != 26) return false;
	if(s[0] + s[3] + s[6] + s[10] != 26) return false;	
	if(s[7] + s[8] + s[9] + s[10] != 26) return false;	
	if(s[1] + s[5] + s[8] + s[11] != 26) return false;	
	if(s[4] + s[6] + s[9] + s[11] != 26) return false;
	return true;
}

bool exist(int n){
	for(int i=0; i<12; i++){
		if(s[i] == n) return true;
	}
	return false;
}

bool dfs(int seq){
	if(seq==12) return checkresult();
//	if(seq==5 && s[1] + s[2] + s[3] + s[4] != 26) return false;
//	if(seq==8 && s[0] + s[2] + s[5] + s[7] != 26) return false;
//	if(seq==11 && s[7] + s[8] + s[9] + s[10] != 26) return false;
	if(s[seq] == -1){
		for(int i=1; i<=12; i++){
			if(exist(i)) continue;
			s[seq]=i;
			if(dfs(seq+1)) return true;
			s[seq]=-1;
		}
	} else {
			if(dfs(seq+1)) return true;
	}
	return false;
}

int main(void){
	char tmp;
	int idx=0;
	for(int i=0; i<9*5; i++){
		cin >> tmp;
		if(tmp != '.' && tmp != 'x'){
			s[idx]=tmp-'A'+1;
			idx++;
		} else if(tmp == 'x') {
			s[idx]=-1;
			idx++;
		}
	}

	dfs(0);
	cout << "...." << char(s[0]+'A'-1) << "...." << endl;
	cout << "." << char(s[1]+'A'-1) << "." << char(s[2]+'A'-1) << "." << char(s[3]+'A'-1) << "." << char(s[4]+'A'-1) << "." << endl;
	cout << ".." << char(s[5]+'A'-1) << "..." << char(s[6]+'A'-1) << ".." << endl;
	cout << "." << char(s[7]+'A'-1) << "." << char(s[8]+'A'-1) << "." << char(s[9]+'A'-1) << "." << char(s[10]+'A'-1) << "." << endl;
	cout << "...." << char(s[11]+'A'-1) << "...." << endl;
	return 0;
}
