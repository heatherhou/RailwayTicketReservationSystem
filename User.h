#include <string>
#include <vector>
#include "Ticket.h"
using namespace std;

#ifndef USER_H
#define USER_H

class User
{

	friend User userInput();
	friend User userLogin();
	friend void printHistory(const User);

	
public:
	
	static const int max = 30;
	User(const string& = "", const string& = "", const string& = "", const string& = "");
	
	string getFirstName()const ;
	string getLastName()const;
	string getPassword()const;
	string getID()const;
	vector<Ticket> getUserHistory() const;

	bool operator==(const User&);

	void setFirstName(const string &);
	void setLastName(const string&);
	int setPassword(const string&);
	void setID(const string&);
	void setHistory(const Ticket&);
	void printHistory();


public:
	string firstName;
	string lastName;
	string password;
	string IDNumber;
	vector <Ticket> userHistory;
};

#endif 

