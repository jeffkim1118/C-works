#include<iostream>
using namespace std;

// ASCII value of lower case 'k' * 10
// My last name's first character is 'k' from "Kim"
// Lower case 'k' has ASCII value of 107
// Therefore the value of my A is 107 * 10 = 1070
const int A = 1070;
// My full name is Yoonsung Kim
// The total number of alphabetic letters in my full name is 11
// Therefore my B value is 250 * 11 = 2750
const int B = 2750;
// My last name is between G and L there fore my N value is 3
const int N = 3;

bool isPrime(int x) {
	int i = 0;
	int last = x / 2;
	// The prime number must be greater than 1.
	if (x <= 1) {
		return false;
	}

	//Testing for the value
	for (i = 2; i <= last; i++)
	{
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}


bool endsWithMyDigit(int y) {
	/* testing the number if the number ends with the digit '3'
	by using modulus of 10 to find the remainder of 3.
	If the statement is true, return true to the main function. Otherwise return false*/
	if (y % 10 == N) {
		return true;
	}
	else
	{
		return false;
	}
}


int main() {
	// Created an int variable "count" to count the total value.
	int count = 0;

	for (int num = A; num <= B; num++) {
		if (isPrime(num) && endsWithMyDigit(num)) {
			count++;
		}
	}
	cout << count << endl;
	// The result is to be 58!
	return 0;
}