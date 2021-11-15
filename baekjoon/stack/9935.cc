#include <stdio.h>
#include <string.h>

char inputStr[1000001];
char stack[1000001]={0,};
char explosionStr[101];
int stackIdx = 0;
int el = 0;

void push(char c){
	stack[stackIdx] = c;
	stackIdx++;
	stack[stackIdx] = NULL;
}

void pop(int n){
	stackIdx -= n;
	stack[stackIdx] = NULL;
}

int check(){
	//printf("check:%s\n", stack + strlen(stack)-strlen(explosionStr));
	for(int i=0; i<el; i++){
		if(stack[stackIdx-el+i] != explosionStr[i]) return 0;
	}
	return 1;
}

int main(void){
	scanf("%s", inputStr);
	scanf("%s", explosionStr);

	el = strlen(explosionStr);
	int len = strlen(inputStr);

	for(int i=0; i<len; i++){
		push(inputStr[i]);
		if(stackIdx>=el && inputStr[i] == explosionStr[el-1]){
			if(check()){
				//printf("aftercheck:%s\n", stack);
				pop(el);
			}
		}
	}
	if(stackIdx == 0) printf("FRULA\n");
	else printf("%s\n", stack);
	return 0;
}
