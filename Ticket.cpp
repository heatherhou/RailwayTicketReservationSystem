#include <iostream>
#include "Ticket.h"
#include "User.h"
#include <string>
#include <vector>
using namespace std;

Ticket::Ticket(const string& depar, const string& arriv, const string& init, const string& desti, int lineNumber, int seatNum)
	:Train(depar,arriv,init,desti,lineNumber)
{
	setSeat(seatNum);
}

Ticket::Ticket(const Train& train, int seat) : Train(train)
{
	seatNumber = seat;
}
void Ticket::setPersonalSeat(int seatNum)
{
	Train::setSeat(seatNum);
	seatNumber = seatNum;
}

int Ticket::getSeatNumber()const
{
	return seatNumber;
}

