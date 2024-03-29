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
	this->resNum = "";
	memset(this->booker, 0x00, MAX_Booker_LEN+1);
}

Seat::Seat(int snum, int pprice, std::string rnum, std::string bbooker) 
{
	seatNum = snum;
	price = pprice;
	resNum = rnum;
	this->state = 0;
	memcpy(this->booker, bbooker.c_str(), MAX_Booker_LEN);
}
Seat::Seat(int snum, int pprice, string rnum, std::string bbooker, int state) {
	seatNum = snum;
	price = pprice;
	resNum = rnum;
	state = state;
	memcpy(this->booker, bbooker.c_str(), MAX_Booker_LEN);
}

//---------------SEAT SETTER-----------------
void Seat::setSeatNum(int snum) {
	this->seatNum = snum;
}

void Seat::setPrice(int p) {
	this->price = p;
}
void Seat::setState(int s) {  //setter for State
	this->state = 0;
}
void Seat::setResNum(std::string resNum) {
	this->resNum = resNum;
}
void Seat:: setBooker(std::string booker) {
	memcpy(this->booker, booker.c_str(), MAX_Booker_LEN);
}

//------------SEAT GETTER-------------------
int  Seat::getSeatNum() { return this->seatNum; }
int Seat::getPrice() { return this->price; }
int Seat::getState() { return this->state; }
string  Seat::getResNum() { return this->resNum; }
string  Seat::getBooker() { return this->booker; }

//================================================================================

//---------------USER CONSTRUCTOR----------------------
User::User() {
	memset(this->name, 0x00, MAX_Booker_LEN + 1); 
	this->resNum = "";
	this->seatNum=0;
}

User::User(std::string nname, string rNum, int seatNum)

{

	resNum = rNum;

	seatNum = seatNum;

	memcpy(this->name, nname.c_str(), MAX_Booker_LEN);

}


//----------------USER SETTER---------------
void User::setName(std::string nname) {
	memcpy(this->name, nname.c_str(), MAX_Booker_LEN);
}
void User::setResNum(std::string resNum) {
	this->resNum = resNum;
}
void User:: setSeatNum(int snum)          
{
	this->seatNum = snum;
}
//------------USER GETTER----------------
string User::getName(void) { return this->name; }
string User::getResNum(void) { return this->resNum; }
int User::getSeatNum() { return this->seatNum; }
