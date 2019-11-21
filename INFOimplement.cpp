#include <stdlib.h>
#include <string>
#include <string.h>
#include "UserINFO.h"
#include "SeatINFO.h"
using namespace std;
//-----------------SEAT CONSTRUCTOR-------------------
Seat::Seat() {		
	this->seatNum = 0;			
	this->price = 10000;
	this->resNum = 0;
	memcpy(this->booker, 0x00, MAX_Booker_LEN+1);
}

Seat::Seat(int snum, int pprice, int rnum, std::string bbooker = NULL) 
{
	seatNum = snum;
	price = pprice;
	resNum = rnum;
	memcpy(this->booker, bbooker.c_str(), MAX_Booker_LEN);
}

//---------------SEAT SETTER-----------------
void Seat::setSeatNum(int snum) {
	this->seatNum = snum;
}

void Seat::setPrice(int p) {
	this->price = p;
}
void Seat::setResNum(int resNum) {
	this->resNum = resNum;
}
void Seat:: setBooker(std::string booker) {
	memcpy(this->booker, booker.c_str(), MAX_Booker_LEN);
}

//------------SEAT GETTER-------------------
int  Seat::getSeatNum() { return this->seatNum; }
int Seat::getPrice() { return this->price; }
int  Seat::getResNum() { return this->resNum; }
string  Seat::getBooker() { return this->booker; }

//================================================================================

//---------------USER CONSTRUCTOR----------------------
User::User() {
	memcpy(this->name, 0x00, MAX_Booker_LEN + 1); 
	this->resNum = 0;
	this->seatNum=0;
}

User::User(std::string nname, int rNum, int seatNum)

{

	resNum = rNum;

	seatNum = seatNum;

	memcpy(this->name, nname.c_str(), MAX_Booker_LEN);

}


//----------------USER SETTER---------------
void User::setName(std::string nname) {
	memcpy(this->name, nname.c_str(), MAX_Booker_LEN);
}
void User::setResNum(int rNum) {
	this->resNum = rNum;
}
void User:: setSeatNum(int snum)          
{
	this->seatNum = snum;
}
//------------USER GETTER----------------
string User::getName(void) { return this->name; }
int User::getResNum(void) { return this->resNum; }
int User::getSeatNum() { return this->seatNum; }