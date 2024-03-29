#ifndef __SEATINFO_H__
#define __SEATINFO_H__

#include <string>
#define MAX_Booker_LEN 32
using namespace std;

class Seat {
public:
	Seat();                                                         //default constructor of the class Seat
	Seat(int snum, int pprice, string rnum, std::string bbooker); //constructor when parameter exist
													      	//snum=seat Number, pprice=price, rnum=reservation number, bbooker= booker
	Seat(int snum, int pprice, string rnum, std::string bbooker,int state);
	
	void setSeatNum(int snum);            //setter for Seat number 
	void setPrice(int p);				  //setter for Price 
	void setState(int S);
	void setResNum(std::string resNum);			  //setter for reservation number 
	void setBooker(std::string booker);   //setter for booker 
	

	int getSeatNum(); //getter for Seat number 
	int getPrice();  //setter for Price
	int getState();  //setter for State
	std::string getResNum();
	std::string getBooker();
	
private:
	int seatNum;					 //seatNum=seat Number
	int price;						 //price of the seat
	int state;
	string resNum;						 //reservations number if reserved 
	char booker[MAX_Booker_LEN + 1]; //booker= user who reserved this seat
	
};
#endif
