/*
	This C program gets an integer as input and calculates
the prime factorization of the input.
*/

#include<stdio.h>

int main () {
	
	/* Defining and declaring variables */
	int number_from_user, prime=2, exponent=0;
	/* User Interface */
	printf ("Enter a number: ");
	scanf ("%d", &number_from_user);
	
	/* Validation */
	while (number_from_user <= 1) {
		printf("Enter a valid number: ");
		scanf ("%d", &number_from_user);
	}
	
	/* User Interface */
	printf("Prime Factorization of %d: ", number_from_user);
	
	/* Main Algorithm */
	while (number_from_user > 1) {
		/* If the prime is not full coefficient increase the prime */
		if (number_from_user % prime != 0) {
			p++;
		}
		/* If the prime is full coefficient divide the number with prime, increase the exponent */
		while (number_from_user % prime == 0) {
			exponent++;
			number_from_user /= prime;
		}
		if (exponent != 0) {
			printf ("%d ^ %d ", prime,exponent);
			printf(" * ");
			exponent = 0;
		}
	
	}

	return 0;
}
