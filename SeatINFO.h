#ifndef __SEATINFO_H__
#define __SEATINFO_H__

#include <string>
#define MAX_Booker_LEN 32

class Seat {
public:
	Seat();
	Seat(int snum, int pprice, int rnum, std::string bbooker=NULL); //resNum=예약번호, booker=예약자
	
	void setSeatNum(int snum);
	void setPrice(int p);
	void setResNum(int resNum);
	void setBooker(std::string booker);
	

	int getSeatNum();
	int getPrice();
	int getResNum();
	std::string getBooker();
	
private:
	int seatNum;
	int price;
	int resNum;
	char booker[MAX_Booker_LEN + 1];
	
};
#endif