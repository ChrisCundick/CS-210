/*
 * Project1.cpp
 *
 *  Date: 7/16/2023
 *  Author: Chris Cundick
 */

 /*
  * Clock program to output 2 different clock types.
  * The standard clock on the left and the military time on the right.
  * User input can add one second, minute or one hour.
  * 
  */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;


//Functions

//User Menu
void userMenu() {
	cout << "**************************" << endl;
	cout << "* 1 - Add One Hour       *" << endl;
	cout << "* 2 - Add One Minute     *" << endl;
	cout << "* 3 - Add One Second     *" << endl;
	cout << "* 4 - Exit Program       *" << endl;
	cout << "**************************" << endl;
	cout << endl << endl;
}


string twoDigitString(unsigned int n) {
	/**
	 * You may wish to change this function when you bring it into your program.
	 * For now please get it to work here with the existing function signature.
	 * You may assume <string> has been included.
	 */
	 // TODO: your code here to implement the method -- Cant figure out how to get into the displayTime function

	//if n is a single diget, place a 0 in the front
	if (n <= 9) {
		cout << setw(2) << setfill('0');
	}
	//convert the integer to a string
	string s = to_string(n);
	cout << s;

	// Numbers between 10 and 59 just need to be converted to a string
	// Numbers from 0 to 9 need a "O" tacked onto the front of the string representation of the number

	// Return the two digit string representation of n
	return s;
}

//Display 12 and 24 hour clock
void displayTime(int hour24, int minute, int second) {
	
	int hour;
	string meridiem;
	hour = hour24;

	//Convert military time to standard - Nighttime
	if (hour24 >= 12) {  
		meridiem = "PM";
	
		if (hour24 >= 12) { 
			hour = hour24 - 12;
		}  
	} 
	//Convert military time to standard - Daytime
	if (hour24 < 12) {  
		meridiem = "AM";
	}
	if (hour24 == 0) { 
		hour = 12;
	}
	
	
	//Create the display
	cout << "**************************       **************************" << endl;
	cout << "*    12 - Hour Clock     *       *    24 - Hour Clock     *" << endl;
	cout << "*       " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " " << meridiem << "      *       *        " << setw(2) << setfill('0') << hour24 << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << "        *" << endl;
	cout << "**************************       **************************" << endl;
	cout << endl << endl;


	//Create the display

	/* FIXME -- Cant get the twoDigitString() function to work
	cout << "**************************       **************************" << endl;
	cout << "*    12 - Hour Clock     *       *    24 - Hour Clock     *" << endl;
	cout << "*       " << twoDigitString(hour) << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " " << meridiem << "      *    *        " << setw(2) << setfill('0') << hour24 << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << "        *" << endl;
	cout << "**************************       **************************" << endl;
	cout << endl << endl;
	*/
}


int main()
{
	//Declare Variables
	int userInput;
	int second;
	int minute;
	int hour24;
	string meridiem;
	bool exit = false;

	second = 0;
	minute = 0;
	hour24 = 0;
	
	while ( exit == false)
	{
		
		userMenu();
		cin >> userInput;
		
		switch (userInput) {
		case 1:
			hour24 += 1;
			break;
		case 2:
			minute += 1;
			break;
		case 3:
			second += 1;
			break;
		case 4:
			exit = true;
			break;
		default:
			cout << "Invalid input." << endl;
			break;

		}

		if (second > 59) {
			second = 0;
			minute += 1;
		}

		if (minute > 59) {
			minute = 0;
			hour24 += 1;
		}

		if (hour24 > 23) {
			hour24 = 0;
		}
		
		displayTime(hour24, minute, second);
	
	}
	
	return 0;
}