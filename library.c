#include <stdio.h>
#include <string.h>

int getHammingDistance (char * str1, char * str2) {
	int i = 0, inversions = 0;
	
	if (strlen(str1) != strlen(str2)) {
		return -1;
	}
	
	if (strlen(str1) == 0) {
		return 0;
	}
	
	for (; i < strlen(str1); i += 1) {
		if (str1[i] == str2[i]) {
			inversions += 1;
		}
	}
	
	return inversions;
}

int countSubstrPattern (char * strToCheck, char * pattern) {
	return 0;
}

int isValidString (char * strToCheck, char * alphabet) {
	return 0;
}

int getSkew (char * strInput, int scope) {
	return 0;
}

int getMaxSkewN (char * strInput, int scope) {
	return 0;
}

int getMinSkewN (char * strInput, int scope) {
	return 0;
}

int main () {
	return 0;
}