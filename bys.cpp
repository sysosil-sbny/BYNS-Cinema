#include "UserINFO.h"
#include "SeatINFO.h"
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>
#define MAX_LENGTH 8
#include <ncurses.h>

#define COLOR_RED 1
#define COLOR_BLACK 0
#define COLOR_GREEN 2
#define COLOR_YELLOW 3
#define COLOR_BLUE 4
#define COLOR_MAGENTA 5
#define COLOR_CYAN 6
#define COLOR_WHITE 7
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

	string rnum;

	cin >> rnum;



	read_usr(rnum);

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




int main(void) {
	//print();
int y,x;
	initscr();
	noecho();
	raw();
//01
	if(has_colors() ==FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
//02
	if(init_color(COLOR_BLUE,0,0,300)==ERR)
	{
		printw("do not accept");
		printw("continue\n");
		getch();
		move(0,0);
	}
//03
	init_pair(1,COLOR_RED,0);

	init_pair(2,COLOR_GREEN,COLOR_BLACK);
	init_pair(3,COLOR_YELLOW,COLOR_BLACK);
	init_pair(3,COLOR_BLUE,COLOR_BLACK);
	init_pair(4,COLOR_MAGENTA,COLOR_BLACK);
	init_pair(5,COLOR_CYAN,COLOR_BLACK);
	init_pair(6,COLOR_WHITE,COLOR_BLACK);
	init_pair(7,COLOR_CYAN,COLOR_MAGENTA);

//04
	attron(A_BOLD);
//05
attron(COLOR_PAIR(8));
printw("----------------------------------------------------------------------------------------------------\n");
	attron(COLOR_PAIR(1));

	//printw("RED");

	attron(COLOR_PAIR(2));

	attron(COLOR_PAIR(3));

	attron(COLOR_PAIR(4));


	attron(COLOR_PAIR(5));

printw("	 ______ __   __ _   _  _____                _                                \n" ); 
printw("	 | ___ \\\\ \\ / /| \\ | |/  ___|              (_)\n" );                                
printw("	 | |_/ / \\ V / |  \\| |\\ `--.  ______   ___  _  _ __    ___  _ __ ___    __ _ \n" ); 
printw("	 | ___ \\  \\ /  | . ` | `--. \\|______| / __|| || '_ \\  / _ \\| '_ ` _ \\  / _` |\n" ); 
printw("	 | |_/ /  | |  | |\\  |/\\__/ /        | (__ | || | | ||  __/| | | | | || (_| |\n" ); 
printw("	 \\____/   \\_/  \\_| \\_/\\____/          \\___||_||_| |_| \\___||_| |_| |_| \\__,_|\n" ); 

attron(COLOR_PAIR(8));
printw("---------------------------------------------------------------------------------------------------\n");

	attron(COLOR_PAIR(5));
printw("\n");
printw("\n");
printw("\n");
while(1){
	attron(COLOR_PAIR(5));
printw("\n");
printw("\n");
printw("\n");
printw("                              >        1.   Booking movie         < \n");
printw("                              >        2.   Booking confirm       < \n");
printw("                              >        3.   Exit program          < \n");
	attron(COLOR_PAIR(6));
	attron(COLOR_PAIR(7));

	
	attrset(A_BOLD);
	getmaxyx(stdscr,y,x);
	
	keypad(stdscr, TRUE);
	int i = getch();
//	if (i == 224){
//	i=getch();
//	case 72: printw("NO");
	if(i==KEY_UP)
{
printw("                              >        Go to memu 1. Wait ...  < \n");
sleep(2);
movie();
continue;
}
if(i==KEY_DOWN)
{
printw("                              >        Go to memu 2. Wait ...  < \n");
sleep(2);
Bookingcheck();
continue;
}

if(i==KEY_RIGHT)
{
printw("                              >        Go to memu 3. Exit Program.  < \n");
sleep(2);
return 0;
}
//	mvprintw(y-1,0,"%s","Enter to go");

	refresh();
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



