#include <stdio.h>
#include <string.h>

/*
	FUNCTION_DESC: 
		Given two strings str1 and str2 of same length (length must never be 0 or
		negative!), the Hamming Distance of two strings is the number of characters 
		that differ in ith position from position 1 to strlen(str1).
*/
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

/*
	FUNCTION_DESC: 
		Given a string original and pattern, we will count the number of occurrence
		of pattern in original.
*/
int countSubstrPattern (char * strToCheck, char * pattern) {
	char * out;
	int i = 0, j = 0, foundPatterns = 0;
	void getSubstring (char * str, char * output, int startIndex, int endIndex) {
		int x = 0;
		
		for (x = startIndex; x < endIndex; x += 1) {
			output[x-startIndex] = str[x];
		}
		output[x-startIndex] = '\0';
	}
	
	if (strlen(pattern) > strlen(strToCheck)) {
		return 0;
	}
	
	if (strlen(pattern) == strlen(strToCheck) && strcmp(strToCheck, pattern) == 0) {
		return 1;
	} else {
		return 0;
	}
	
	for (; i <= strlen(strToCheck) - strlen(pattern); i += 1) {
		for (j = 0; j < strlen(pattern); j += 1) {
			getSubstring(strToCheck, out, i, i + strlen(pattern));
			if (strcmp(out, pattern) == 0) {
				foundPatterns += 1;
			}
		}	
	}
	
	return foundPatterns;
}

/*
	FUNCTION_DESC: 
		Given an alphabet string where all letters are assumed to be unique, this
		function returns true if the string str is a valid string based on the letters of alphabet.
*/
int isValidString (char * strToCheck, char * alphabet) {
	int i = 0, j = 0, isValid = 0, isValidPerSymbol[strlen(alphabet)];
	
	if (strlen(strToCheck) < 0 || strlen(alphabet) == 0) {
		return -1;
	}
	
	if (strlen(strToCheck) == 0) {
		return 1;
	}
	
	for (; i < strlen(strToCheck); i += 1) {
		isValidPerSymbol[i] = 0;
		for (j = 0; j < strlen(alphabet); j += 1) {
			if (strToCheck[i] == alphabet[i]) {
				isValidPerSymbol[i] = 1;
			}
		}
	}
	
	for (i = 0; i < strlen(alphabet); i += 1) {
		isValid = 1;
		if (isValidPerSymbol[i] == 0) {
			isValid = 0;
			break;
		}
	}
	
	return isValid;
}

/*
	FUNCTION_DESC: 
		Given a genome str of some length q (where q>0), it returns the number of
		Gs minus the number of Cs in the first n nucleotides (q>=n). The value can be zero,
		negative or positive. The first position is one (1) not zero(0) as we typically associate with
		string implementations.
*/
int getSkew (char * strInput, int scope) {
	int i = 1, j = 1, numberOfSkew = 0;
	for (; i <= scope; i += 1) {
		if (strInput[i] == 'G') {
			numberOfSkew += 1;
		}
	}
	
	for (i = 1; i < scope; i += 1) {
		if (strInput[i] == 'G') {
			for (j = i + 1; j <= scope - 1; j += 1) {
				if (strInput[j] == 'C') {
					numberOfSkew -= 1;
				}
			}
		}
	}
	
	return numberOfSkew;
}

/*
	FUNCTION_DESC: 
		Given a genome str of some length q (where q>0), it returns the maximum
		value of the number of Gs minus the number of Cs in the first n nucleotides (q>=n). The
		value can be zero, negative or positive. The first position is one (1) not zero(0) as we
		typically associate with string implementations.
*/
int getMaxSkewN (char * strInput, int scope) {
	int i = 1, numberOfSkew = 0;
	for (; i <= scope; i += 1) {
		if (strInput[i] == 'G') {
			numberOfSkew += 1;
		}
	}
	
	return numberOfSkew;
}

/*
	FUNCTION_DESC: 
		Given a genome str of some length q (where q>0), it returns the minimum
		value of the number of Gs minus the number of Cs in the first n nucleotides (q>=n). The
		value can be zero, negative or positive. The first position is one (1) not zero(0) as we
		typically associate with string implementations.
*/
int getMinSkewN (char * strInput, int scope) {
	int i = 1, j = 1, numberOfSkew = 0;
	for (; i <= scope; i += 1) {
		if (strInput[i] == 'G') {
			if (numberOfSkew != 1) numberOfSkew += 1;
		}
	}
	
	for (i = 1; i <= scope; i += 1) {
		if (strInput[i] == 'G') {
			for (j = i + 1; j <= scope - 1; j += 1) {
				if (strInput[j] == 'C') {
					numberOfSkew -= 1;
				}
			}
		}
	}
	
	return numberOfSkew;
}

int main () {
	return 0;
}