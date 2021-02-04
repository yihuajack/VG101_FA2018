#include <cstdlib>
#include <ctime>
#include "random.h"

// constructor
VG101_Random::VG101_Random()
{
	current_seed = time(NULL);
	srand(current_seed);
}

// constructor
VG101_Random::VG101_Random(int seed)
{
	current_seed = seed;
	srand(current_seed);
}

/* range in [lower, upper) */
double VG101_Random::nextDouble(double lower, double upper)
{
	return lower + rand() / (RAND_MAX+1.0) * (upper-lower);
}

/* range in [lower, upper] */
int VG101_Random::nextInteger(int lower, int upper)
{
	return lower + (int) (rand() / (RAND_MAX+1.0) * (upper-lower + 1));
}

int VG101_Random::nextBoolean(double p)
{
	if (nextDouble(0, 1) < p) return 1;
	else return 0;
}
