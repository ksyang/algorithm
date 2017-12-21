#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, five = 0, three = 0, min = -1, tmp, flag = 0;
    cin >> N;

    for(int i=0;;i++) {
	tmp = N;
	tmp = tmp - i*5;
	if(tmp < 0) break;
	five = i;
	three = tmp/3;
	if(tmp%3 != 0) continue;
	else {
	    if(flag == 0) {
		min = five + three;
		flag = 1;
	}
	else if((five+three) < min) {
	    min = five + three;
	}
    }
							    }
		        
    cout << min << endl;
    return 0;
}

