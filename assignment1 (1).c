/*
	This program executes that for a given date, determines which weekday (Monday through Sun-
day) the date corresponds to, and how many times the given day-and-month
falls on the same weekday starting with the next year and ending on a given
year. Zeller's congruence has been used for algorithm.

*/

#include<stdio.h>
#include<stdlib.h>
#define ZERO_BASED_CENTURY_CONSTANT 100

int main () {
	
	/* Declare variables */
	int year, month, day, end_year;
	int zeller, j, k, buf, buf1;
	/* Define variables */
	int count=0, buf_zeller, i=0;
	
	/* User Interface */
	printf("Enter date [year month day]: ");
	scanf("%d %d %d", &year, &month, &day);
	
	/* Leap years */
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if(day<0 || day>31) {
			printf("Invalid date.");
			return EXIT_FAILURE;
		}
	}
	
	if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) {
		if(day<0 || day>30) {
			printf("Invalid date.");
			return EXIT_FAILURE;
		}
	}
	
	/* User Interface */
	printf("Enter end year: ");
	scanf("%d", &end_year);
	
	/* For Zeller's congruence*/
	if(month == 1 || month == 2) {
		month += 12;
		year--;
	}
	
	/* Zeller's congruence*/
	j = year / ZERO_BASED_CENTURY_CONSTANT;
	buf = year % 10;
	buf1 = year / 10;
	k = buf + (10 * (buf1 % 10));
	
	zeller = (day + (13*(month+1)/5) + k + (k/4) + (j/4) + (5*j)) % 7;
	
	/* Output with decision structure */
	switch(zeller) {
		case 0:
			printf("It's a Saturday.\n"); break;
		case 1:
			printf("It's a Sunday.\n"); break;
		case 2:
			printf("It's a Monday.\n"); break;
		case 3:
			printf("It's a Tuesday.\n"); break;
		case 4:
			printf("It's a Wednesday.\n"); break;
		case 5:
			printf("It's a Thursday.\n"); break;
		case 6:
			printf("It's a Friday.\n"); break;						
	}
	
	/* Zeller's congruence */
	for(i=year+1; i<=end_year; i++) {
		
		j = i / ZERO_BASED_CENTURY_CONSTANT;
		buf = i % 10;
		buf1 = i / 10;
		k = buf + (10 * (buf1 % 10));
		buf_zeller = (day + (13*(month+1)/5) + k + (k/4) + (j/4) + (5*j)) % 7;
		
		if(buf_zeller == zeller)
			count++;
	}
	
	/* Output */
	if (month == 13 || month == 14) {
		printf("Same day-and-month on same weekday between %d and %d: %d", year+2, end_year, count);
	}
	else {
		printf("Same day-and-month on same weekday between %d and %d: %d", year+1, end_year, count);
	}
			
	return EXIT_SUCCESS;
}
