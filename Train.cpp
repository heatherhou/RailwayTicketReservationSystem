#include <iostream>
#include <string>
#include "Train.h"
#include <vector>

using namespace std;


Train::Train(const string& depar, const string& arri, const string& init, const string& des, int lineNumber)
	:departure(depar), arrival(arri), start(init), destination(des), line(lineNumber)
{
	
	for (int i = 0; i < 20; i++)
	{
		seat[i] = 0;
	}
}

void Train::setArrival(const string& arriv)
{
	arrival = arriv;
}

void Train::setDeparture(const string& depart)
{
	departure = depart;
}

void Train::setStart(const string& init)
{
	start = init;
}

void Train::setDestination(const string& destin)
{
	destination = destin;
}

void Train::setLine(const int lineNumber)
{
	line = lineNumber; 
}

void Train::setSeat(const int seatNumber)
{
	seat[seatNumber - 1] = 1;
}

string Train::getDeparture()const
{
	return departure;
}

string Train::getArrival()const
{
	return arrival;
}

string Train::getStart()const
{
	return start;
}

string Train::getDestination()const
{
	return destination;
}

int Train::getLine()const
{
	return line;
}

int* Train::getSeat()const
{
	int *temp = new int[20];
	for (int i = 0; i < 20; i++)
		temp[i] = seat[i];
	return temp;
}

void Train::printArrival()const
{
	cout<< arrival.substr(0,2) << "/" << arrival.substr(2, 2) << " " << arrival.substr(4,2) << ":"<<arrival.substr(6,2);
}

void Train::printDepart()const
{
	cout << departure.substr(0, 2) << "/" << departure.substr(2, 2) << " " << departure.substr(4,2) << ":" << departure.substr(6,2);
}

int Train::seatCheck(const int chosenSeat)
{
	if (seat[chosenSeat] == 1)
		return 1;
	else 
		return 0;

}