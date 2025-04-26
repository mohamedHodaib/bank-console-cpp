#pragma once
#include<iostream>
#include"clsUtility.h"
#include"clsInputValidate.h"
#include"My.h"
#include"input.h"
using namespace std;
class clsArray
{
public:

		int TimesRepeated(int Number, int arr[100], int arrLength)
		{
			int count = 0;
			for (int i = 0; i <= arrLength - 1; i++)
			{
				if (Number == arr[i])
				{
					count++;
				}
			}
			return count;
		}
		int MaxNumberInArray(int arr[100], int arrLength)
		{
			int Max = 0;
			for (int i = 0; i < arrLength; i++)
			{
				if (arr[i] > Max)
				{
					Max = arr[i];
				}
			}
			return Max;
		}
		int MinNumberInArray(int arr[100], int arrLength)
		{
			int Min = 0;
			Min = arr[0];
			for (int i = 0; i < arrLength; i++)
			{
				if (arr[i] < Min)
				{
					Min = arr[i];
				}
			}
			return Min;
		}
		int SumArray(int arr[100], int arrLength)
		{
			int Sum = 0;
			for (int i = 0; i < arrLength; i++)
			{
				Sum += arr[i];
			}
			return Sum;
		}
		float ArrayAverage(int arr[100], int arrLength)
		{
			return (float)SumArray(arr, arrLength) / arrLength;
		}
		void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
		{
			for (int i = 0; i < arrLength; i++)
				arrDestination[i] = arrSource[i];
		}
		short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
		{
			/*This function will search for a number in array and return its index,
			or return -1 if it does not exists*/
			for (int i = 0; i < arrLength; i++)
			{
				if (arr[i] == Number)
					return i;// and return the index
			}
			//if you reached here, this means the number is not found
			return -1;
		}
		bool IsNumberInArray(int Number, int arr[100], int arrLength)
		{
			return FindNumberPositionInArray(Number, arr, arrLength) != -1;
		}
		bool IsPalindromeArray(int arr[100], int Length)
		{
			for (int i = 0; i < Length; i++)
			{
				if (arr[i] != arr[Length - i - 1])
				{
					return false;
				}
			};
			return true;
		}
		int OddCount(int arr[100], int arrLength)
		{
			int Counter = 0;
			for (int i = 0; i < arrLength; i++)
			{
				if (arr[i] % 2 != 0)
				{
					Counter++;
				}
			}
			return Counter;
		}
		int EvenCount(int arr[100], int arrLength)
		{
			int Counter = 0;
			for (int i = 0; i < arrLength; i++)
			{
				if (arr[i] % 2 == 0)
				{
					Counter++;
				}
			}
			return Counter;
		}
		int PositiveCount(int arr[100], int arrLength)
		{
			int Counter = 0;
			for (int i = 0; i < arrLength; i++)
			{
				if (arr[i] >= 0)
				{
					Counter++;
				}
			}
			return Counter;
		}
		int NegativeCount(int arr[100], int arrLength)
		{
			int Counter = 0;
			for (int i = 0; i < arrLength; i++)
			{
				if (arr[i] < 0)
				{
					Counter++;
				}
			}
			return Counter;
		}
		void PrintArray(int arr[100], int arrLength)
		{
			for (int i = 0; i < arrLength; i++)
				cout << arr[i] << " ";
			cout << "\n";
		}
		void ReadArray(int arr[100], int arrLength)
		{
			for (int i = 0; i < arrLength; i++)
			{
				cout << "Element [" << i + 1 << "] : ";
				cin >> arr[i];
			}
			cout << endl;
		}
		void FillArrayWithRandomNumbers(int arr[100], int arrLength)
		{
			for (int i = 0; i < arrLength; i++)
				arr[i] = clsUtil::RandomNumber(1, 100);
		}
		void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Lenght)
		{
			for (int i = 0; i < arrLength; i++)
			{
				if (clsInputValidate::CheckPrime(arrSource[i]) == clsInputValidate:: Prime)
				{
					arrDestination[i] = arrSource[i];
				}
			}
		}
		void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
		{
			for (int i = 0; i < arrLength; i++)
			{
				arrSum[i] = arr1[i] + arr2[i];
			}
		}
		void ShuffleArray(int arr[100], int arrLength)
		{
			for (int i = 0; i < arrLength; i++)
			{
				clsUtil::MySwap(arr[clsUtil::RandomNumber(1, arrLength) - 1], arr[clsUtil::RandomNumber(1, arrLength) - 1]);
			}
		}
		void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
		{
			for (int i = 0; i < arrLength; i++)
				arrDestination[i] = arrSource[arrLength - 1 - i];
		}
		void FillArrayWithKeys(string arr[100], int arrLength)
		{
			for (int i = 0; i < arrLength; i++)
				arr[i] = clsUtil::GenerateKey();
		}
		void PrintStringArray(string arr[100], int arrLength)
		{
			cout << "\nArray elements:\n\n";
			for (int i = 0; i < arrLength; i++)
			{
				cout << "Array[" << i << "] : ";
				cout << arr[i] << "\n";
			}
			cout << "\n";
		}
		void PrintNumberPosition(int Number, int arr[100], int arrLength)
		{
			short NumberPosition = FindNumberPositionInArray(Number, arr, arrLength);
			if (NumberPosition == -1)
				cout << "The number is not found :-(\n";
			else
			{
				cout << "The number found at position: ";
				cout << NumberPosition << endl;
				cout << "The number found its order: ";
				cout << NumberPosition + 1 << endl;
			}
		}
		void PrintFoundOrNotFound(int Number, int arr[100], int arrLength)
		{
			// main يمكنك كتابة فقط هذه الجملة من الكود أو الكو د كامل ا في فانكشون الرئيس ي
			cout << "\nNumber you are looking for is: " << Number << endl;
			if (!IsNumberInArray(Number, arr, arrLength))
				cout << "No, The number is not found :-(\n";
			else
			{
				cout << "Yes, it is found :-)\n";
			}
		}
		void AddArrayElement(int Number, int arr[100], int& arrLength)
		{
			//its a new element so we need to add the length by 1
			arrLength++;
			arr[arrLength - 1] = Number;
		}
		void InputUserNumbersInArray(int arr[100], int& arrLength)
		{
			bool AddMore = true;
			do
			{
				AddArrayElement(clsInputValidate::ReadNumber("Enter the element that you want to add:"), arr, arrLength);
				cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
				cin >> AddMore;
			} while (AddMore);
		}
		void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
		{
			for (int i = 0; i < arrLength; i++)
				AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
		}
		void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
		{
			for (int i = 0; i < arrLength; i++)
				if (arrSource[i] % 2 != 0)
				{
					AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
				}
		}
		void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
		{
			for (int i = 0; i < arrLength; i++)
				if (clsInputValidate::CheckPrime(arrSource[i]) ==clsInputValidate:: Prime)
				{
					AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
				}
		}
		void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
		{
			for (int i = 0; i < SourceLength; i++)
			{
				if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
				{
					AddArrayElement(arrSource[i], arrDestination, DestinationLength);
				}
			}
		}
		static  void FillArrayWith1toN(int arr[100], int arrLength)
		{
			for (int i = 0; i < arrLength; i++)
				arr[i] = i + 1;
		}
};

