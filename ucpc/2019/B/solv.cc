#include <iostream>

using namespace std;

int main(void){
	int N, M;
	char map[101][101];

	cin >> N >> M;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}

	for(int j=M-1; j>=0; j--){
		for(int i=0; i<N; i++){
			if(map[i][j] == '-')
				cout << '|';
			else if(map[i][j] == '|')
				cout << '-';		
			else if(map[i][j] == '/')
				cout << '\\';
			else if(map[i][j] == '\\')
				cout << '/';	
			else if(map[i][j] == '^')
				cout << '<';		
			else if(map[i][j] == '<')
				cout << 'v';	
			else if(map[i][j] == 'v')
				cout << '>';	
			else if(map[i][j] == '>')
				cout << '^';
			else
				cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}
