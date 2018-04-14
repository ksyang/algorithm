#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int checkSorted(int *L_odd, int *L_even, int oddLen, int evenLen, int len){
   int i = 0;
   int index = 0;
   sort(L_odd, L_odd+oddLen);
   sort(L_even, L_even+evenLen);
   while(1){
      if(oddLen > evenLen && i+1 >= oddLen) break;
			if(oddLen == evenLen && i+1 > oddLen) break;
      if(L_odd[i] > L_even[i])
         return i*2;
			if(oddLen > evenLen && i+1 <= evenLen && L_even[i] > L_odd[i+1])
				return i*2+1;
      if(oddLen == evenLen && i+1 < evenLen && L_even[i] > L_odd[i+1])
				return i*2+1;
      i++;
   }
   return -1;
}

int main(void)
{
   int T;
   int caseCnt = 0;
   
   cin >> T;
   while(T--){
      int L_odd[100001];
      int L_even[100001];
      int oddLen = 0;
      int evenLen = 0;
			int len = 0;

      caseCnt++;
      cin >> len;
      for(int i=0;i<len;i++){
         if(i%2 == 0){
            cin >> L_odd[oddLen];
            oddLen++;
         } else {
            cin >> L_even[evenLen];
            evenLen++;
         }
      }
      
      cout << "Case #"<< caseCnt << ": ";
      int res = checkSorted(L_odd, L_even, oddLen, evenLen, len);
      if(res == -1) cout << "OK\n";
      else cout << res << '\n';
   }
   return 0;
}
