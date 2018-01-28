#include <iostream>
#include "User.h"
#include <ctype.h>
#include <iomanip>
#include <string>
using namespace std;
class Ticket;
User::User(const string& first, const string&last, const string& pass, const string & number)
	:firstName(first), lastName(last), password(pass), IDNumber(number)
{
	
}

void User::setFirstName(const string& first)
{
	firstName = first;
}

void User::setID(const string& ID)
{
	IDNumber = ID; 
}

void User::setLastName(const string& last)
{
	lastName = last;
}

int User::setPassword(const string & pass)
{
	int check = 0;
	//char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	if (pass.size() < 12)
	{
		for (size_t i = 0; i < pass.size(); i++)
		{

				if (isupper(pass[i]))
				{
					password = pass;
					check = 1;
				}
				
		}
		if (check == 0)
		
			cout <<"\nThe pass word must contain at least one capital letter\n";
	
				
	}
	else
		cout << "\nThe length of the password should be less than 12 letters/numbers\n";
	return check;
	
}

void User::setHistory(const Ticket& passTicket)
{
	userHistory.push_back(passTicket); 
}

bool User::operator== (const User& b)
{
	if ((IDNumber == b.IDNumber) && (password == b.IDNumber))
		return true;
	else
		return false;

}
string User::getFirstName()const 
{
	return firstName;
}

string User::getID()const
{
	return IDNumber;
}

string User::getPassword()const
{
	return password; 
}

string User::getLastName() const
{
	return lastName;
}


void User::printHistory()
{
	cout << "                                  Purchasing History\n";
	cout << "     -----------------------------------------------------------------------------\n";
	cout << "     Source     Destination     Departure Time      Arrival Time     Line     Seat\n";
	for (size_t i = 0; i < userHistory.size(); i++)
	{
		cout << "     " << setw(6) << userHistory[i].getStart() << "     " << setw(11) << userHistory[i].getDestination() << "     ";
		userHistory[i].printDepart();
		cout << "         ";
		userHistory[i].printArrival();
		cout<< "       " << userHistory[i].getLine() << "       " << userHistory[i].getSeatNumber() +1 << endl;

	}
}

