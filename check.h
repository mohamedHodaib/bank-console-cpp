#pragma once
#include<iostream>
	enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };
using namespace std;
namespace check {
	enPrimeNotPrime CheckPrime(int Number)
	{
		int M = round(Number / 2);
		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return NotPrime;
		}
		return Prime;
	}
	bool isPerfectNumber(int Number)
	{
		int Sum = 0;
		for (int i = 1; i < Number; i++)
		{
			if (Number % i == 0)
				Sum += i;
		}
		return Number == Sum;
	}
	int ReverseNumber(int Number)
	{
		int Remainder = 0, Number2 = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;
		}
		return Number2;
	}
	bool IsPalindromeNumber(int Number)
	{
		return Number == ReverseNumber(Number);
	}

}
