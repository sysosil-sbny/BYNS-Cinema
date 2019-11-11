#ifndef __USERINFO_H__
#define __USERINFO_H__


#include <string>
#define MAX_Booker_LEN 32

class User {
public:
	User();
	User(std::string name, int resNum); //resNum=reservation number, name= name of the user

	void setName(std::string name);    //setter for name 
	void setResNum(int resNum);        //setter for resNum 

	std::string getName(void);        //getter for name
	int getResNum(void);             //setter for resNum

private:
	char name[MAX_Booker_LEN + 1];   //name= name of the user
	int resNum;                      //resNum=reservation number
};


#endif