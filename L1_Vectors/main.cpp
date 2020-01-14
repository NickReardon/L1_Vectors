/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon and Danin Namiranian
 * Lab #1			: Vectors
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 01 / 13 / 20
 *****************************************************************************/
#include "main.h"

using std::cout;
using std::endl;
using std::string;
using std::setw;

int main()
{

	/*
	 * HEADER OUTPUT
	 */
	PrintHeader(cout, "Prompt.txt");

	/********************************************************************/


	srand(time(NULL));
	std::vector<int> intVect(15);
	std::vector<int> revVect(15);
	std::vector<int> sumVect(15);

	// Part A and B 
	cout << " ** Populating with random  numbers" << endl << endl;
	for (int i = 0; i < 15; i++)
	{
		intVect.at(i) = (rand() % 900 + 100);
	}



	//Part C 
	cout << " ** Sorting vectors" << endl << endl;
	sort(intVect.begin(), intVect.end());



	//Part D and E 
	cout << " ** Reversing digits and storing in new vector" << endl << endl;

	string reverse;
	char temp;
	for (int i = 0; i < 15; i++)
	{
		reverse = std::to_string(intVect[i]);
		temp = reverse[0];
		reverse[0] = reverse[2];
		reverse[2] = temp;
		revVect[i] = stoi(reverse);
	}



	//Part F and G
	cout << " ** Summing the digits and storing in new vector" << endl << endl;

	int mod;
	int num;
	int sum;
	for (int i = 0; i < 15; i++)
	{
		sum = 0;  num = intVect[i];
		while (num > 0)
		{
			mod = num % 10;
			sum = sum + mod;
			num = num / 10;
		}
		sumVect[i] = sum;
	} string output;



	//Part H

	cout << std::left << setw(10) << "Original" << setw(10) << "Reversed" << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << setw(10) << intVect[i];
		if (revVect[i] < 100)
		{
			if (revVect[i] < 10)
			{
				output = string("00" + std::to_string(revVect[i]));
				cout << setw(10) << output;
			}
			else 
			{
				output = string("0" + std::to_string(revVect[i]));
				cout << setw(10) << output;
			}
		}
		else 
		{
			cout << setw(10) << revVect[i];
		}

		cout << "Sum of the digits of " << intVect[i] << " is " << sumVect[i] << endl;
	}

	system("pause");
	return 0;
}
