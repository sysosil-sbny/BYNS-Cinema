#include "UserINFO.h"
#include "SeatINFO.h"
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>

using namespace std;


	
//예매확인으로 넘어갈 때의 함수 
void Bookingcheck(){
//(1) 고유번호 입력하기
cout << "자신의 예매번호를 입력하세요 : ";

//cin >> 고유번호;

//(2) 파일 open
string filepath = "./UserList.dat"; // 사용자 파일
int fd = open(filepath.c_str(), O_CREAT | O_APPEND | O_WRONLY, 0644); //열고
if (fd == -1) {
	perror("open() error");
}
//(3) 정보 검색..
	
//(4)정보 출력

cout << "본인의 예매번호"<<endl;
cout << "예매한 좌석 정보"<<endl;


	

int main(int argc, int argv[]) {
	cout << "______ __   __ _   _  _____          _____  _" << endl;
	cout << "| ___ || | / /| | | |/  ___|        /  __ |(_)" << endl;
	cout << "| |_/ / | V / | |_| || `--.  ______ | /  |/ _  _ ___   ____  ________  _____     "<< endl;
	cout << "| ___ |  | /  | ._` | `--. ||______|| |    | || '__ | / __ ||` _   _  | |_` |" << endl;
	cout << "| |_/ / _| |  | | | |/___/ /        | |__ /| || | | |||___/ | | | | | | (_| |" << endl;
	cout << "|____ / |_ /  |_| |_/_____/         |____/ |_||_| |_||____| | |_| |_| |_| |_| " << endl;

	int choice = 0;

	cout << "-----------MEMU-------------" << endl;
	cout << "1. 예매하기" << endl;
	cout << "2. 예매확인" << endl;

	cin >> choice;

	switch (choice)
	{
	case 1: Booking();
	case 2: Bookingcheck();
	default:
		break;
	}

	return 0;
}
	
	
void write_usr(string name, int resnum, int seatnum) { //고유번호 받은 후 사용자 파일에 저장하는 함수
	User usr(name, resnum, seatnum); // 유저 구조체 생성
	string filepath = "./UserList.dat"; // 사용자 파일
	int fd = open(filepath.c_str(), O_CREAT | O_APPEND | O_WRONLY, 0644); //열고
	if (fd == -1) {
		perror("open() error");
		//return 1;
	}
	if (write(fd, &usr, sizeof(User)) == -1) { // 씀
		perror("write() error");
		// return 2;
	}

	close(fd);//닫음
}

void read_usr(int resNum) { //예매 확인 할 때 입력된 고유번호가 사용자 파일에 있는지 확인하는 함수
	string filepath = "./UserList.dat";
	int fd = open(filepath.c_str(), O_RDONLY);
	if (fd == -1) {
		perror("open() error");
		// return 1;
	}
	ssize_t rSize = 0;
	User usr = User();
	list<User> usrList;
	do {
		rSize = read(fd, &sur, sizeof(User)); // 유저 구조체 단위로 읽어서

		if (rSize == -1) {
			perror("read() error!");
			// return 2;
		}

		if (rSize == 0) {
			/// break;
		}

		usrList.push_back(usr);// 유저리스트에 넣는다.
	} while (rSize > 0);

	close(fd);

	list<User>::iterator iter;

	for (iter = usrList.begin(); iter != usrList.end(); ++iter) { // 유저리스트 서치 동안 고유번호 찾으면 
		if (iter->getResNum == resNum)
			cout << getSeatNum << " 좌석 예매 되어있습니다." << endl; // 출력
		else
			cout << "예매한 좌석이 없습니다." << endl; // 못찾으면 출력
	}
}

int main(int argc, int argv[]) {

	list <User> UL; //User List 
	list <Seat> SL; //Seat List



	return 0;
}
