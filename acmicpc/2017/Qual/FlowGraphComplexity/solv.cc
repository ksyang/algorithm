#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

char P[80000];
int cnt = 0;

void getString(){
	char tmp;
	while(1){
		scanf("%c", &tmp);
		if(tmp == ' ') continue;
		if(tmp == '\n') break;
		P[cnt] = tmp;
		cnt++;
	}
	P[cnt] = '\x00';
}

void breakProcess(int n){
	//cout << n << endl;
	printf("-1");
	exit(0);
}

int main(void){
	int W;
	int nS = 0, nL = 0, nB = 0;
	stack<char> s;

	scanf("%d", &W);
	getchar();
	getString();
	
	if(!(P[0] == 'S' || P[0] == 'B' || P[0] == 'L'))
		breakProcess(0);
	
	if(!(P[cnt-1] == 'S' || P[cnt-1] == ']' || P[cnt-1] == ')'))
		breakProcess(0);

	for(int i=0; i<cnt; i++){
		if(P[i] == 'S'){
			nS++;
			if(i != cnt-1)
				if(!(P[i+1] == ',' || P[i+1] == ')' || P[i+1] == ']'))
					breakProcess(0);
		}
		else if(P[i] == 'L'){
			nL++;
			if(i == cnt-1)
				breakProcess(1);
			if(!(P[i+1] == '(' || P[i+1] == '['))
				breakProcess(1);
		}
		else if(P[i] == 'B'){
			nB++;
			if(i == cnt-1)
				breakProcess(2);
			if(!(P[i+1] == '(' || P[i+1] == '['))
				breakProcess(2);
		}
		else if(P[i] == '['){
			if(i == 0)
				breakProcess(3);
			if(!(P[i-1] == 'B' || P[i-1] == 'L'))
				breakProcess(3);
			s.push('[');
		}
		else if(P[i] == ']'){
			if(cnt && !(P[i-1] == 'S' || P[i-1] == ')' || P[i-1] == ']'))
				breakProcess(3);
			if(s.size() == 0)
				breakProcess(3);
			if(s.top() == '[')
				s.pop();
			else 
				breakProcess(3);
		}
		else if(P[i] == '('){
			if(i == 0)
				breakProcess(3);
			if(!(P[i-1] == 'B' || P[i-1] == 'L'))
				breakProcess(3);
			s.push('(');
		}
		else if(P[i] == ')'){
			if(cnt && !(P[i-1] == 'S' || P[i-1] == ')' || P[i-1] == ']'))
				breakProcess(4);
			if(s.size() == 0)
				breakProcess(4);
			if(s.top() == '(')
				s.pop();
			else
				breakProcess(4);
		}
		else if(P[i] == ','){
			if(i == 0 || i == cnt-1)
				breakProcess(5);
			if(!(P[i-1] == 'S' || P[i-1] == ')' || P[i-1] == ']'))
				breakProcess(5);
			if(!(P[i+1] == 'S' || P[i+1] == 'L' || P[i+1] == 'B'))
				breakProcess(5);
		}
		else
			breakProcess(7);
	}

	if(s.size() != 0)
		breakProcess(8);

	int nV = nS + nL*2 + nB*2;
	int EB = nL;
	int EF = nV-1+nB;

	cout << EF + W*EB - nV + 2;	
	return 0;
}
