#include "Train.h"

#include <string>

using namespace std;

#ifndef TICKET_H
#define TICKET_H

class Ticket : public Train
{
	
public:
	Ticket(const string& = "", const string& = "", const string& = "", const string& = "", int = 0, int = 0);
	Ticket(const Train &,  int= 0);
	void setPersonalSeat(int);
	int getSeatNumber() const;
	

private: 
	int seatNumber;
};

#endif


