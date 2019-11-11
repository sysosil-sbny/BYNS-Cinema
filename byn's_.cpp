#include "UserINFO.h"
#include "SeatINFO.h"
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>

using namespace std;

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