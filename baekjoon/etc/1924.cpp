#include <iostream>

using namespace std;

int main(void)
{
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0, remainder;
    int m, n;

    cin >> m >> n;
    for(int i=1;i<m;i++)
    {
	total += month[i];
    }
    total += n;
    remainder = total % 7;
    
    switch(remainder) 
    {
	case 1: cout << "MON"; break;
	case 2: cout << "TUE"; break;
	case 3: cout << "WED"; break;
	case 4: cout << "THU"; break;
	case 5: cout << "FRI"; break;
	case 6: cout << "SAT"; break;
	case 0: cout << "SUN"; break;
    }
    return 0;
}
