#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define PRINT_HEADER(type) \
	printf("%s: %*c%2zd bytes\n", #type, 11 - (int)strlen(#type), ' ', sizeof(type)); \
	
#define PRINT_RANGE(type, up_type) \
	PRINT_HEADER(type) \
	printf("min value: %*c%lld\n", 2, ' ', (long long)up_type ## _MIN); \
	printf("max value: %*c%lld\n", 3, ' ', (long long)up_type ## _MAX); \
	printf("max unsigned: %llu (2^%zd - 1)\n\n", (long long unsigned)U ## up_type ## _MAX, sizeof(type) * 8); \

#define PRINT_FLOAT_RANGE(type, up_type) \
	PRINT_HEADER(type) \
	printf("range: %*c+/-%Lf\n\n", 7, ' ', (long double)up_type ## _MAX); \

int
main(int argc, char *argv[])
{
	printf("System type: %lld-bit\n\n", (long long)__WORDSIZE);
	PRINT_RANGE(char, CHAR);
	PRINT_RANGE(short, SHRT);
	PRINT_RANGE(int, INT);
	PRINT_RANGE(long, LONG);
	PRINT_RANGE(long long, LLONG);
	PRINT_FLOAT_RANGE(float, FLT);
	PRINT_FLOAT_RANGE(double, DBL);
	PRINT_FLOAT_RANGE(long double, LDBL);
	
	return 0;
}
