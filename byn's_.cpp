#include "UserINFO.h"
#include "SeatINFO.h"
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>

using namespace std;

//예매확인으로 넘어갈 때의 함수 
void Bookingcheck() {
	//(1) 고유번호 입력하기
	cout << "자신의 예매번호를 입력하세요 : ";

	//cin >> 고유번호;

	//(2) 파일 open
	/*string filepath = "./UserList.dat"; // 사용자 파일
	int fd = open(filepath.c_str(), O_CREAT | O_APPEND | O_WRONLY, 0644); //열고
	if (fd == -1) {
		perror("open() error");
	}*/
	//(3) 정보 검색..

	//(4)정보 출력

	cout << "본인의 예매번호" << endl;
	cout << "예매한 좌석 정보" << endl;

}


//book.cpp 끌어옴
typedef struct Node {
	Seat data; // 데이터 저장 공간
	struct Node* next; // 다음 노드의 연결을 위한 포인터
}Node;

Node* head = NULL;
Node* tail = NULL;
Node* cur = NULL;
void insert();
void seat_print();
void Booking();



int main(int argc, int argv[]) {


	list <User> UL; //User List 
	list <Seat> SL; //Seat List 

	cout << "______ __   __ _   _  _____          _____  _" << endl;
	cout << "| ___ || | / /| | | |/  ___|        /  __ |(_)                            _____" << endl;
	cout << "| |_/ / | V / | |_| || `--.  ______ | /  |/ _  _ ___   ____   __________  /`__  |  " << endl;
	cout << "| ___ |  | /  | ._` | `--. ||______|| |    | || '__ | / _`_ | |` _   _  | | |_| |" << endl;
	cout << "| |_/ / _| |  | | | |/___/ /        | |__ /| || | | || |___/  | | | | | | |  _  |" << endl;
	cout << "|____ / |_ /  |_| |_/_____/         |____/ |_||_| |_||_____|  |_| |_| |_| |_| |_| " << endl;

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

	//예매한 뒤에 이름 입력. 입력받고 고유함수로 저장
	string usrname;
	cout << "이름을 입력하세요: ";
	cin >> usrname;


	return 0;
}
