


#include "SeatINFO.h"
#include "UserINFO.h"
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LENGTH 8
#include <ncurses.h>
using namespace std;
#define COLOR_RED 1
#define COLOR_BLACK 0
#define COLOR_GREEN 2
#define COLOR_YELLOW 3
#define COLOR_BLUE 4
#define COLOR_MAGENTA 5
#define COLOR_CYAN 6
#define COLOR_WHITE 7
int print(void)
{
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
//printw("          ______ __   __ _   _  _____                _           \n" );                     
//printw("          | ___ || | / /| | | |/  ___|              (_)                \n" );               
//printw("          | |_/ / | V / | |_| || `--.  ______   ___  _  _ __    ___  _ __ ___    __ _ \n" );
//printw("| ___ |  | /  | . ` | `--. ||______| / __|| || '_  | / _ || '_ ` _ '  / _` |\n" );
//printw("| |_/ /  | |  | |-  |/|__/ /        | (__ | || | | ||  __/| | | | | || (_| |\n" );
//printw("|____/   |_/  |_| |_||____/          .___||_||_| |_| |___||_| |_| |_| '__,_|\n" );


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

printw("\n");
printw("\n");
printw("\n");

printw("                              >        1.                         < \n");
printw("                              >        2.                         < \n");
printw("                              >        3.                         < \n");
	attron(COLOR_PAIR(6));
	attron(COLOR_PAIR(7));

	attron(COLOR_PAIR(8));
printw("---------------------------------------------------------------------------------------------------\n");

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
}
if(i==KEY_DOWN)
{
printw("                              >        Go to memu 1. Wait ...  < \n");
sleep(2);
}
if(i==KEY_UP)
{
printw("                              >        Go to memu 2. Wait ...  < \n");
sleep(2);
}

if(i==KEY_RIGHT)
{
printw("                              >        Go to memu 3. Exit Program.  < \n");
sleep(2);

}
//	mvprintw(y-1,0,"%s","Enter to go");

	refresh();
return 0;
	//getch();
	//endwin();


	
}



void write_usr(list<User> ul,string name, string resnum, int seatnum) {
    User usr(name, resnum, seatnum);
//list<User>::iterator iter;      // 좌석정보 가져올 반복자
   //iter = ul.begin();
   // list<User> usrList;
    ul.push_back(usr);
    string filepath = "./UserList.dat";
    int fd = open(filepath.c_str(),  O_APPEND | O_CREAT  | O_WRONLY, 0644);
    if (fd == -1) {
        perror("open() error");
        // return 1;
        exit(-1);
    }
    list<User>::iterator iter;
    for (iter = ul.begin(); iter != ul.end(); ++iter) {
        if (write(fd, &(*iter), sizeof(User)) == -1) {
            perror("write() error");
            // return 2;
            exit(-2);
        }
    }

    close(fd);
    // return usr;
}

void read_usr(string resNum) {
    string filepath = "./UserList.dat";
    int fd = open(filepath.c_str(), O_RDONLY);
    if (fd == -1) {
        perror("open() error");
        // return 1;
exit(-1);
    }
    ssize_t rSize = 0;
    User usr = User();
    list<User> usrList;
    do {
        rSize = read(fd, &usr, sizeof(User));

        if (rSize == -1) {
            perror("read() error!");
            // return 2;
exit(-2);
        }

        if (rSize == 0) {
            /// break;
        }

        usrList.push_back(usr);
    } while (rSize > 0);

    close(fd);

    list<User>::iterator iter;
    int count = 0;
int same=1;
    for (iter = usrList.begin(); iter != usrList.end(); ++iter) {
        same = strcmp(iter->getResNum().c_str(), resNum.c_str());
        if (same == 0) {
            cout << "예매하신 좌석은 " << iter->getSeatNum() << "입니다."
                 << iter->getResNum() << " " << iter->getName() << endl;
            count++;
            break;
        }
else {
continue;
}
        // else
        //   cout << "예매하신 내역이 없습니다." << endl;
    }
    if (count == 0)
        cout << "예매하신 내역이 없습니다." << endl;
}

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
//printw("          ______ __   __ _   _  _____                _           \n" );                     
//printw("          | ___ || | / /| | | |/  ___|              (_)                \n" );               
//printw("          | |_/ / | V / | |_| || `--.  ______   ___  _  _ __    ___  _ __ ___    __ _ \n" );
//printw("| ___ |  | /  | . ` | `--. ||______| / __|| || '_  | / _ || '_ ` _ '  / _` |\n" );
//printw("| |_/ /  | |  | |-  |/|__/ /        | (__ | || | | ||  __/| | | | | || (_| |\n" );
//printw("|____/   |_/  |_| |_||____/          .___||_||_| |_| |___||_| |_| |_| '__,_|\n" );


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

printw("\n");
printw("\n");
printw("\n");
while(1){
	attron(COLOR_PAIR(5));
printw("                              >        1.   Booking movie         < \n");
printw("                              >        2.   Booking confirm       < \n");
printw("                              >        3.   Exit program          < \n");
	attron(COLOR_PAIR(6));
	attron(COLOR_PAIR(7));

	attron(COLOR_PAIR(8));
printw("---------------------------------------------------------------------------------------------------\n");

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
continue;
}
if(i==KEY_DOWN)
{
printw("                              >        Go to memu 2. Wait ...  < \n");
sleep(2);
}

if(i==KEY_RIGHT)
{
printw("                              >        Go to memu 3. Exit Program.  < \n");
sleep(2);
return 0;
}
//	mvprintw(y-1,0,"%s","Enter to go");

	refresh();}
//scanw

     list<User> usrList;
    string name;
    string resnum;
    string rresnum;
    int seatnum;
    cout << "name: ";
    cin >> name;
    cout << "resnum: ";
    cin >> resnum;
    cout << "seatnum: ";
    cin >> seatnum;
    // usrList.push_back(
    write_usr(usrList,name, resnum, seatnum);
    cout << "rrsnum: ";
    cin >> rresnum;
    read_usr(rresnum);
    return 0;
} 









