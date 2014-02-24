#include <stdio.h>

int primes [] = {2,3,5,7,11};

#define getcx getchar
inline long inp() {
	long n = 0;
	int ch = getcx();
	while(ch < '0' || ch > '9') { 
		ch = getcx();
	}
	
	while(ch >= '0' && ch <= '9') { 
		n = (n << 3) + (n << 1) + ch - '0', 
		ch = getcx();
	}

	return n;
}

// main entry point for program
int main() {
	int repeatcount = 0;	///< Repeat count, which is input in first line
	char str [50][8] = {0};		///< Taking static array, taking 8 so, that double * doesn't take next string
	int i=0;
	repeatcount = inp (); // taking input for no. of test cases from user

	// taking input 
	for (i=0;i<repeatcount;i++)
		gets (str[i]);
		

	// passing each array to function for output
	for (i = 0 ; i < repeatcount ; i++) {
		
		double b = *(double *)str[i];
		long long l = b;
		int j=0;
		while (l != b) {

			b *= primes[(j+1)%5];
			j++;
			l = b;

		}

		printf("%.1lf %d\n", b, j);
	}	
}
