#include "UserINFO.h"
#include "SeatINFO.h"
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string>
#include <unistd.h>
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

using namespace std;


// 사용함수 선언
void insert();
void seat_print(list<Seat> SL);
void Booking(list<Seat> SL);
list<Seat> setting();
void menu(list<Seat> SL);
void movie();
string randchar();
void read_usr(string resNum);
void write_usr(string name, string resnum, int seatnum);

// 연결리스트 목록
list<User> UL;
list<Seat> winter = setting();
list<Seat> FM = setting();
list<Seat> black = setting();


//예매확인으로 넘어갈 때의 함수 
void Bookingcheck() {
    //(1) 고유번호 입력하기
    printw("					자신의 예매번호를 입력하세요 : ");
 
    string rnum;
 
	scanw("%s",&rnum);
 
    read_usr(rnum);
 
}

int main(void) {
	//print();
int y,x;
	initscr();
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
	//attron(A_BOLD);
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

	int i = 0;
scanw("%d",&i);

	switch(i){
	case 1:

{
printw("\n");
printw("\n");
printw("\n");
	attron(COLOR_PAIR(3));
printw("                              >        Go to menu 1. Wait ...    < \n");
attroff(COLOR_PAIR(3));
sleep(2);
movie();
endwin();
continue;
}
case 2:
{
printw("\n");
printw("\n");
printw("\n");
	attron(COLOR_PAIR(3));
printw("                              >        Go to menu 2. Wait ...    < \n");
printw("\n");
printw("\n");
attroff(COLOR_PAIR(3));
sleep(2);
Bookingcheck();
continue;
}

case 3:
{
printw("\n");
printw("\n");
printw("\n");
attron(COLOR_PAIR(3));

printw("                              >         Go to menu 3. Exit Program.< \n");
attroff(COLOR_PAIR(3));
sleep(2);
return 0;}
}
//	mvprintw(y-1,0,"%s","Enter to go");

	refresh();
}
}
void movie(){
    while(1)
    {
        printw("\n---------------------------------------- MOVIE ------------------------------------------------------------\n");
        printw("				      1. 겨울왕국2\n");
        printw("				      2. 나를 찾아줘\n");
        printw("				      3. 블랙머니\n");
        printw("			  * 메뉴로 돌아가시려면 0번을 누르세요 *\n");

        int movie = 0;
        printw("				      >> ");
        scanw("%d",&movie);

        switch (movie)
        {
        case 0: return;
        case 1: Booking(winter);
                break;
        case 2: Booking(FM);
                break;
        case 3: Booking(black);
                break;
        default: continue;
        }
    }
}

string name()
{
	//예매한 뒤에 이름 입력. 입력받고 고유함수로 저장
	string usrname;
	printw("					이름을 입력하세요: ");
	scanw("%s",&usrname);

	return usrname;
}

