///@file tests.c
#include <assert.h>
#include "tests.h"
#include "prime.h"
#include <stdio.h>
/*
* Helper function for checking if value is in array
* @param arr array
* @param size size of array
* @param value value to check wether 
*/
int InArray(int* arr, int size, int value) 
{
	for (int i = 0; i < size; i++) 
	{
		if (arr[i] == value) 
		{
			return 1;
		}
	}
	return 0;
}
int PrimeTest() 
{
	int primes[10] = { 2,3,5,7,11,13,17,19,23,29 };
	for (int i = 0; i < 30; i++) {
		if (InArray(primes, 10, i) && !IsPrime(i)) 
		{
			return 0;
		}
		if (!InArray(primes, 10, i) && IsPrime(i)) 
		{
			return 0;
		}
	}
	return 1;
}
/**
* Testing for internal In Array function for testing.
*/
void TestInArray() 
{
	int list[5] = { 1,2,3,4,5 };
	assert(InArray(list, 5, 1));
	assert(InArray(list, 5, 9)==0);
}
/**
* Testing to make sure generator function works in required order
*/
void TestGetNextPrime()
{
	printf("Testing GetNextPrime...");
	assert(GetNextPrime() == 2);
	assert(GetNextPrime() == 3);
	assert(GetNextPrime() == 5);
	assert(GetNextPrime() == 7);
	assert(GetNextPrime() == 11);
	printf("OK\n");
}
/**
* Testing to make sure IsPrime function recognizes primes correctly
*/
void TestIsPrime()
{
	printf("Testing IsPrime...");
	//Testing to make sure that we will never get a non prime from function
	for (int i = 0; i < 50; i++) {
		assert(IsPrime(GetNextPrime()));
	}

	//Testing for internal IsPrime function
	assert(IsPrime(0) == 0);
	assert(IsPrime(1) == 0);
	assert(IsPrime(2) == 1);
	assert(IsPrime(3) == 1);
	assert(IsPrime(4) == 0);
	assert(IsPrime(5) == 1);
	assert(IsPrime(6) == 0);

	//Making sure that IsPrime works for first 10 primes
	assert(PrimeTest());
	TestInArray();
	printf("OK\n");
}
void tests()
{
	TestGetNextPrime();
	TestIsPrime();
}
	

	

	


