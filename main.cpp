#include <iostream>
#include <iomanip>
#include "User.h"
#include "Train.h"
#include "Ticket.h"

#include <vector>
#include <string>
using namespace std;

vector<Train> searchTrain(vector <Train>& trainDatabase, const string& source, const string& desti, const string&date)
{
	vector <Train> availableTrain;
	for (size_t i = 0; i < trainDatabase.size(); i++)
	{
		if ((source == trainDatabase[i].start) && (desti == trainDatabase[i].destination) && (date == trainDatabase[i].departure.substr(0,4)))
			availableTrain.push_back(trainDatabase[i]);
		
	}
	return availableTrain;
}

void printSchedule(vector<Train>&availableTrain)
{
	cout << "\n\n\nHere are all the available trains at given information\n";
	cout << "-------------------------------------------------------------------\n";
	cout << "TrainID     Source     Destination     Departure Time    Arrival Time\n";
	for (size_t i = 0; i < availableTrain.size(); i++)
	{
		cout << "      " << availableTrain[i].line << "          " << availableTrain[i].start <<"               " << availableTrain[i].destination<<"        ";
		availableTrain[i].printDepart();
		cout << "     ";
		availableTrain[i].printArrival();
		cout << endl;
	}
	cout << "--------------------------------------------------------------------\n";
}

void printSeat(const Train& chosenTrain)
{
	cout << "\n\nThe train ID you preferred is: " << chosenTrain.line << endl;
	cout << "Here are the available seats as below\n";
	cout << "The unavailable seat is marked as X\n";
	cout << "     --------------------------------\n";

	for (int i = 1; i < 21; i++)
	{
		
		if (chosenTrain.seat[i-1] == 0)
		{
			cout << setiosflags(ios::right) <<setw(12) << i;
		}
		else if (chosenTrain.seat[i-1] == 1)
			cout << setiosflags(ios::right)<< setw(12) << "X";

		if (i % 2 == 0)
			cout << endl;
	}
	cout << "     --------------------------------\n";
}

User userInput()
{
	User temp;
	string pass;
	int check = 0;
	cout << "--------------------------------------\n";
	cout << "User Registration\n\n";
	cout << "First Name: ";
	cin >> temp.firstName;
	cout << "Last Name: ";
	cin >> temp.lastName;
	cout << "ID Number: ";
	cin >> temp.IDNumber;
	do {
		cout << "Password (The password should contain less than 12 numbers/letters and at least one capital letter): ";
		cin >> pass;
		check = temp.setPassword(pass);
	} while (check == 0);
	return temp;
}

User userLogin()
{
	User temp;
	cout << "-------------------------------------------\n";
	cout << "Please login before you reserve the ticket.\n";
	cout << "ID Number: ";
	cin >> temp.IDNumber;
	cout << "Password: ";
	cin >> temp.password;
	return temp;
}


void printHistory(const User& c)
{
	cout << "     Source     Destination     Departure Time      Arrival Time     Line     Seat";
	for (size_t i = 0; i < c.userHistory.size(); i++)
	{
		cout << "     " << setw(6) << c.userHistory[i].getStart() << "     " << setw(11) << c.userHistory[i].getDestination() << "     "
			<< c.userHistory[i].getDeparture() << "     " << c.userHistory[i].getArrival() << "     " << c.userHistory[i].getLine() << "     " << c.userHistory[i].getSeatNumber() << endl;

	}
}





int main()
{
	

	vector <User> userDatabase;
	userDatabase.reserve(500);
	vector <Train> trainDatabase;
	trainDatabase.reserve(45);
	Train train1("05200810","05200910","A", "B", 1);
	Train train2("05201200", "05201300", "A", "B", 2);
	Train train3("05201730", "05201830", "B", "A", 3);
	Train train4("05200910", "05201130", "A", "C", 4);
	
	

	trainDatabase.push_back(train1);
	trainDatabase.push_back(train2);
	trainDatabase.push_back(train3);
	trainDatabase.push_back(train4); 

	

	vector <Ticket> ticketReserve;

	cout << "\n\nWelcome to the Railway Ticket Reservation System." << endl;
	int choice;
	cout << "Please register or login before ticket reservation" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Please choose the service you need\n";
	cout << "1. User Registration\n";
	cout << "2. User login\n";
	cout << "Choice: ";
	cin >> choice;
	if (choice == 1)
	{
		User localUser;
		
		localUser = userInput();
		userDatabase.push_back(localUser);
	}
	

	User currentUser = userLogin();

	bool check = false;
	for (size_t i = 0; i < userDatabase.size(); i++)
	{
		if ((currentUser.getID() == userDatabase[i].getID()) && (currentUser.getPassword() == userDatabase[i].getPassword()))
		{
			check = true;
			currentUser = userDatabase[i];
		}	

	}

	while (check == false)
	{
		cout << "Login failed, please recheck your ID and password\n";
		User currentUser = userLogin();

		
		for (size_t i = 0; i < userDatabase.size(); i++)
		{
			if ((currentUser.getID() == userDatabase[i].getID()) && (currentUser.getPassword() == userDatabase[i].getPassword()))
			{
				check = true;
				currentUser = userDatabase[i];
			}

		}
		
	}
	

	string source;
	string desti;
	string date;
	int secchoice;
	cout << "\n\nWelcome to the Railway Ticket Reservation System \n";
	cout << "Please choose the service you need\n";
	cout << "1. Book ticket\n";
	cout << "2. Check previous purchasing history\n";
	cout << "Choice: ";
	cin >> secchoice;
	if (choice == 1)
	{

		do
		{
			cout << "Our booking system provide searching and booking services for train between six stations (A,B,C,D,E,F)\n";
			cout << "You may start booking your ticket now\n";
			cout << "--------------------------------------------------------------------------------------------------------\n";
			cout << "Your source station(A,B,C,D,E,F): ";
			cin >> source;
			cout << "Your destination station(A,B,C,D,E,F): ";
			cin >> desti;
			cout << "Your departure date(MMDD): ";
			cin >> date;
			vector <Train> availableTrain;
			availableTrain = searchTrain(trainDatabase, source, desti, date);
			printSchedule(availableTrain);


			int choiceTrain;
			cout << "Please choose the train you preferred: ";
			cin >> choiceTrain;

			Train chosenTrain = availableTrain[choiceTrain - 1];

			printSeat(chosenTrain);
	

			int choiceSeat;
			cout << "Please choose your seat number: ";
			cin >> choiceSeat;

			if (chosenTrain.seatCheck(choiceSeat -1) == 1)
				cout << "The seat has been reserved please re-choose the seat\n";
			else
			{
				for (size_t i = 0; i < trainDatabase.size(); i++)
				{
					if (trainDatabase[i].getLine() == chosenTrain.getLine())
					{
						trainDatabase[i].setSeat(choiceSeat );
		
					}
				}


				cout << "\n\nYour ticket has been successfully reserved\n";
				cout << "Here is information about the ticket you reserved\n";
				cout << "     ---------------------------------------------------\n";
				cout << setiosflags(ios::left) << setw(30) << "     Train ID:       " << chosenTrain.getLine() << "        " << endl;
				cout << setiosflags(ios::left) << setw(30) << "     Departure Time: ";
				chosenTrain.printDepart();
				cout << endl;
				cout << setiosflags(ios::left) << setw(30) << "     Passenger Name: " << currentUser.getFirstName() << " " << currentUser.getLastName() << "  " << endl;
				cout << setiosflags(ios::left) << setw(30) << "     Passenger id:   " << currentUser.getID() << "     " << endl;
				cout << setiosflags(ios::left) << setw(30) << "     ---------------------------------------------------\n";

				Ticket ticket1 = { chosenTrain, (choiceSeat - 1) };
				currentUser.setHistory(ticket1);


				cout << "\n\nPlease choose the service you need\n";
				cout << "1. Book ticket\n";
				cout << "2. Check previous purchasing history\n";
				cout << "Choice: ";
				cin >> secchoice;
			}
		} while (secchoice == 1);

	}

	if (secchoice == 2)
	{
		currentUser.printHistory();
	}

}


