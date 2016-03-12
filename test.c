#include "library.h"

int main () {
	printf("Hamming result: %d\n", getHammingDistance("AACCTT", "GGCCTT"));
	printf("Count substring result: %d\n", countSubstrPattern("AACCTT", "AC"));
	printf("Valid string %s? %d\n", "GCAA", isValidString("GCAA", "GAC"));
	return 0;
}