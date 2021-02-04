#ifndef __RANDOM_H__
#define __RANDOM_H__

class VG101_Random
{
	int current_seed; // current random seed
public:
	VG101_Random(); // constructor
	VG101_Random(int seed); // constructor
	double nextDouble(double lower, double upper); /* range in [lower, upper) */
	int nextInteger(int lower, int upper); /* range in [lower upper] */
	int nextBoolean(double p); /* return a random number, which is 1 with probability p (0¡Üp¡Ü1), and 0 with probability 1-p */
};

#endif /* __RANDOM_H__ */
