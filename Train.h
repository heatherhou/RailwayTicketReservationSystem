#include <string>
#include <vector>
using namespace std;

#ifndef TRAIN_H
#define TRAIN_H
class Train
{

	friend vector<Train> searchTrain(vector <Train>&, const string&, const string&, const string&);
	friend void printSchedule(vector<Train>& );
	friend void printSeat(const Train&);



public:
	
	Train(const string& = "", const string& = "", const string& = "", const string& = "", int = 0 );
	void setDeparture(const string&);
	void setArrival(const string&);
	void setDestination(const string&);
	void setStart(const string&);
	void setLine(const int);
	void setSeat(const int);
	string getDeparture()const;
	string getArrival() const;
	string getDestination()const;
	string getStart()const;
	int getLine()const;
	int* getSeat()const;
	void printDepart()const;
	void printArrival()const;
	int seatCheck(const int);

protected:

	string departure;
	string arrival;
	string destination;
	string start;
	int line; 
	int seat[20];
	

};
#endif


