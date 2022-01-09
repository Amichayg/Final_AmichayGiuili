///@file prime.c
#include "prime.h"
int current = 1;
/*
* Generator function that returns next prime on each call
* @return nextPrime
*/
int GetNextPrime() {
	int i = current + 1;
	while (!IsPrime(i)) {
		i++;
	}
	current = i;
	return current;
}
/*
* Check if number is prime
* @param number
* @return isPrime
*/
int IsPrime(int number) {
	if (number <= 3) {
		return number > 1;
	}
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0) {
			return 0;
		}
	}
	return 1;
}