#include "random.h"
#include <iostream> // c++ style of including header file
using namespace std; // use namespace std for cout

int main()
{
	VG101_Random random;
	int i, sum, N=100000;
	
	for (i=sum=0; i<N; i++)
		if (random.nextInteger(1,6) == 3) sum++;
	cout << "The probability of face = 3 is " << (double)sum/N << endl;
	cout << "FYI, 1/6 = " << 1.0/6 << endl;
	return 0;
}
