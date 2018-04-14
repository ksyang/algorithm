#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

#define CHARGE 4
#define SHOOT 2

using namespace std;

int len = 0;

int countDamage(int *instruct){
   int dmg = 1;
   int atk = 0;

   for(int i=0; i<len; i++){
      if(instruct[i] == SHOOT) atk+=dmg;
      if(instruct[i] == CHARGE) dmg*=2;
   }

   return atk;
}

int countBeam(int D, int *instruct){
   int countSwap = 0;

   if(D >= countDamage(instruct)) return countSwap;

   for(int i=len-1; i>=0; i--){
      if(instruct[i] == CHARGE){
         for(int j=i; j<len-1; j++){
            if(instruct[j+1] == CHARGE) break;
            instruct[j] = SHOOT;
            instruct[j+1] = CHARGE;
            countSwap++;
            if(D >= countDamage(instruct)) return countSwap;
         }
      }
   }

   return -1;
}

int main(void)
{
   int T;
   int caseNum = 0;

   cin >> T;
   getchar();

   while(T--){
      int D;
      char tmp;
      int instruct[31];
      
      len=0;
      caseNum++;

      cin >> D;
      getchar();

      for(int i=0;i<31;i++){
         tmp = getchar();
         if(tmp == '\n') break;
         if(tmp == 'S') instruct[i] = SHOOT;
         if(tmp == 'C') instruct[i] = CHARGE;
         len++;
      }
      int res = countBeam(D, instruct);
      cout << "Case #" << caseNum << ": ";
      if(res == -1) cout << "IMPOSSIBLE\n";
      else cout << res << '\n';
   }
   return 0;
}
