#ifndef UTILS_H
#define UTILS_H

#define GET_STATIC_ARRAY_LENGTH(ARR) (sizeof(ARR)/sizeof(ARR[0]))

int get_random_int(int a, int b)
{
	int ans = rand() % (b - a + 1) + a;
	return ans;
}

float get_random_float(float a, float b)
{
	float ans = (((float)(rand())) / ((float)(RAND_MAX))) * (b - a) + a;
}

#endif
