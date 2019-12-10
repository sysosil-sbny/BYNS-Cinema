#include "SeatINFO.h"
#include "UserINFO.h"
#include <iostream>
#include <list>
#include <ncurses.h>
using namespace std;

string name();
list<Seat> setting();
void seat_print(list<Seat> SL;
void Booking(list<Seat> SL);
void write_usr(string name, string resnum, int seatnum);
string randchar();

list<Seat> setting() // 자리정보 설정
{
    list<Seat> SL;

    for (int i = 0; i < 64; i++) {
        Seat newNode(i, 10000, "", "", 0);
        SL.push_back(newNode);
    }

    return SL;
}

void seat_print(list<Seat> SL) // 좌석상태에 따라 좌석도 출력
{
    list<Seat>::iterator iter;
    iter = SL.begin();

    printw("\n  ======SCREEN======\n");
    for (int i = 1; i < 9; i++) {
        char al = 'a' + i - 1;
        if (i % 5 == 0)
            printw("\t");
        printw(" %s",  al);
    }
    printw("\n");
    for (int i = 1; i < 9; i++) {
        printw("%d",i);

        for (int j = 1; j < 9; j++) {
            if (j % 5 == 0)
                printw("\t");
            if ((*iter).getState() == 0) // 좌석상태 가져오기
                printw(" O");
            else
                printw(" X");

            iter++;
        }
    printw("\n");
    }
    printw("\n");
    return;
}

// 예약 과정
void Booking(list<Seat> SL) {
    list<Seat>::iterator iter; // 좌석정보 가져올 반복자
    iter = SL.begin();

    while (true) {
        seat_print(SL);

        /*int many = 0; // 예매할 좌석 수
        printw("예매할 좌석 수를 입력하세요");
        printw("\n(메뉴로 돌아가고 싶으시면 0를 입력하세요)\n>> ");
        cin >> many;

        if (many == 0)
            return;*/

        string seat = ""; // 예매할 자리
        printw("예매할 좌석을 입력하세요 : ");

        int n =0 ;

        int count1 = 0;
        int count2 = 0;
        int count3 = 0; // 예매 성공한 수

        //for (int i = 0; i < many; i++) {
            cin >> seat; // 문자열로 좌석번호 받아 정수로 변경
            n = (seat[1] - '1') * num + seat[0] - 'a';

            for (iter = SL.begin(); ((*iter).getSeatNum()) != n; iter++)
                ;

            if ((*iter).getState() == 0) // 이미 예약된 경우
            {
                printw("이미 예약된 좌석입니다.\n");
                continue;
            } else {
                (*iter).setState(0);
                if (n < 16)
                    count1++;
                else if (16 <= n < 32)
                    count2++;
                else
                    count3++;
            }
        //}

        char answer = '\0'; // 결제 대답

        if (count1 != 0 || count2 != 0 || count3 != 0) {
            printw("결제할 금액은 %d입니다.\n결제하시겠습니까? (y or n) : "
                 ,count1 * ((*iter).getPrice()) * 0.8 +
                        count2 * ((*iter).getPrice()) * 0.9 +
                        count3 * ((*iter).getPrice())
                 );
            cin >> answer;

            if (answer == 'y') {
                int choice = 0;

                printw("결제할 방법을 선택하세요\n");
        printw("1. 카드  \n");
                printw("2. 무통장 입금  \n");
                printw("3. 휴대폰 결제  \n");
                printw(">> \n");

                cin >> choice;

                switch (choice) {
                case 1:
                        break;
                case 2:
                    int bank; //은행 선택, 계좌번호 랜덤생성
                    printw ("1. 우리은행\n 2. 하나은행\n 3. 국민은행\n 4. 신한은행\n ");
                    printw (">>");
                    cin >> bank;
                    switch (bank) {
                    case 1:
                        printw ("우리은행 12347654333\n "
                            "예금주:(주)빈스");
                        printw ("로 %d원 입금하세요", count1 * ((*iter).getPrice()) * 0.8 +
                            count2 * ((*iter).getPrice()) * 0.9 +
                            count3 * ((*iter).getPrice()));
                        break;

                    case 2:
                        printw ("하나은행 83271616889\n "
                            "예금주:(주)빈스");
                        printw ("로 %d원 입금하세요", count1 * ((*iter).getPrice()) * 0.8 +
                        count2 * ((*iter).getPrice()) * 0.9 +
                        count3 * ((*iter).getPrice()));
                        break;

                    case 3:
                        printw ("국민은행 37289193842\n ")
                            "예금주:(주)빈스";
                        printw ("로 %d원 입금하세요", count1 * ((*iter).getPrice()) * 0.8 +
                        count2 * ((*iter).getPrice()) * 0.9 +
                        count3 * ((*iter).getPrice()));
                        break;

                    case 4:
                        printw ("신한은행 47281048018\n 예금주:(주)빈스");
                        printw("로 %d원 입금하세요", count1 * ((*iter).getPrice()) * 0.8 +
                        count2 * ((*iter).getPrice()) * 0.9 +
                        count3 * ((*iter).getPrice()));
                        break;
                    }
                        break;

                case 3:
                    int phone;
                    printw("1. SKT\n 2. KT\n 3. LG\n 4. 알뜰폰\n ");
                    printw (">>");
                    cin >> phone;

                    switch (phone) {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        
                        break;
                    }
                }
                //여기까지가 choice의 swich문
            printw ("\n");
        string nn = name();

                    string rnum;//resnum

                    rnum = randchar();

                    printw("%s 님의 고유번호는 %d입니다.\n", nn, rnum);

                    write_usr(nn, rnum, n);
                    printw ("예매되었습니다.\n");
                }
            }

            else if (answer == 'n')
                printw ("취소되었습니다.\n");
        }
    }
