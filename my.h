#pragma once
#include<iostream>
using namespace std;
namespace my {
	float MyABS(float Number)
	{
		if (Number > 0)
			return Number;
		else
			return Number * -1;
	}
	float GetFractionPart(float Number)
	{
		return Number - int(Number);
	}
	int MyRound(float Number)
	{
		int IntPart;
		IntPart = int(Number);
		float FractionsPart = GetFractionPart(Number);
		if (FractionsPart >= .5)
		{
			if (Number > 0)
			{
				return ++IntPart;
			}
			else
			{
				return --IntPart;
			}
		}
		else
		{
			return IntPart;
		}
	}
	int MyFloor(float Number)
	{
		if (Number > 0)
			return int(Number);
		else
			return int(Number) - 1;
	}
	int MyCeil(float Number)
	{
		if (abs(GetFractionPart(Number)) > 0)
		{
			if (Number > 0)
				return int(Number) + 1;
			else
				return int(Number);
		}
		else
		{
			return int(Number);
		}
	}
	int MySqrt(float Number)
	{
		return pow(Number, 0.5);
	}
	int MyCeil(float Number)
	{
		if (MyABS(GetFractionPart(Number)) > 0)
		{
			if (Number > 0)
				return int(Number) + 1;
			else
				return int(Number);
		}
		else
		{
			return int(Number);
		}
	}
	void MySwap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	void FillArrayWith1toN(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = i + 1;
	}

}