#ifndef __USERINFO_H__
#define __USERINFO_H__


#include <string>
#define MAX_Booker_LEN 32

class User {
public:
	User();
	User(std::string name, int resNum,int seatNum); //resNum=reservation number, name= name of the user

	void setName(std::string name);    //setter for name 
	void setResNum(int resNum);        //setter for resNum
	void setSeatNum(int snum);            //setter for Seat number 

	std::string getName(void);        //getter for name
	int getResNum(void);             //getter for resNum
	int getSeatNum();				//getter for Seat number 

private:
	char name[MAX_Booker_LEN + 1];   //name= name of the user
	int resNum;                      //resNum=reservation number
	int seatNum;					 //seatNum=seat Number
};


#endif