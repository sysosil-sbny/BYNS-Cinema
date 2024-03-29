#ifndef __USERINFO_H__
#define __USERINFO_H__
#include <string>
#define MAX_Booker_LEN 32
using namespace std;

class User {
public:
	User();
	User(std::string name, std::string resNum,int seatNum); //resNum=reservation number, name= name of the user

	void setName(std::string name);    //setter for name 
	void setResNum(std::string resNum);        //setter for resNum
	void setSeatNum(int snum);            //setter for Seat number 

	std::string getName(void);        //getter for name
	std::string getResNum(void);             //getter for resNum
	int getSeatNum();				//getter for Seat number 

private:
	char name[MAX_Booker_LEN + 1];   //name= name of the user
	string resNum;                      //resNum=reservation number
	int seatNum;					 //seatNum=seat Number
};


#endif
