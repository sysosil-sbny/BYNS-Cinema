#include "UserINFO.h"
#include "SeatINFO.h"
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>

#define win_abc 9
#define win_num 9
#define find_abc 8
#define find_num 8
#define black_abc 5
#define black_num 5

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

// 사용함수 선언
void insert();
void seat_print(list<Seat> SL, int abc, int num);
void Booking(list<Seat> SL, int abc, int num);
list<Seat> setting(int abc, int num);
void menu(list<Seat> SL, int abc, int num);
void movie();

// 연결리스트 목록
list<User> UL;
list<Seat> winter = setting(win_abc, win_num);
list<Seat> FM = setting(find_abc, find_num);
list<Seat> black = setting(black_abc, black_num);

int main() {
	cout << "______ __   __ _   _  _____          _____  _" << endl;
	cout << "| ___ || | / /| | | |/  ___|        /  __ |(_)                            _____" << endl;
	cout << "| |_/ / | V / | |_| || `--.  ______ | /  |/ _  _ ___   ____   __________  /`__  |  " << endl;
	cout << "| ___ |  | /  | ._` | `--. ||______|| |    | || '__ | / _`_ | |` _   _  | | |_| |" << endl;
	cout << "| |_/ / _| |  | | | |/___/ /        | |__ /| || | | || |___/  | | | | | | |  _  |" << endl;
	cout << "|____ / |_ /  |_| |_/_____/         |____/ |_||_| |_||_____|  |_| |_| |_| |_| |_| " << endl;

	while(1)
	{
		cout << "\n-----------MENU-------------" << endl;
		cout << "1. 예매하기" << endl;
		cout << "2. 예매확인" << endl;
		cout << "* 끝내시려면 0을 누르세요 *\n";

		int choice = 0;
		cout << ">> ";
		cin >> choice;

		switch (choice)
		{
		case 0: return 0;
		case 1: movie();
				break;
		case 2: Bookingcheck();
				break;
		default: continue;
		}
	}
}

void movie()
{
    while(1)
    {
        cout << "\n---------- MOVIE ----------" << endl;
        cout << "1. 겨울왕국2" << endl;
        cout << "2. 나를 찾아줘" << endl;
        cout << "3. 블랙머니" << endl;
        cout << "* 메뉴로 돌아가시려면 0번을 누르세요 *\n";

        int movie = 0;
        cout << ">> ";
        cin >> movie;

        switch (movie)
        {
        case 0: return;
        case 1: Booking(winter, win_abc, win_num);
                break;
        case 2: Booking(FM, find_abc, find_num);
                break;
        case 3: Booking(black, black_abc, black_num);
                break;
        default: continue;
        }
    }
}

string name()
{
	//예매한 뒤에 이름 입력. 입력받고 고유함수로 저장
	string usrname;
	cout << "이름을 입력하세요: ";
	cin >> usrname;

	return usrname;
}


