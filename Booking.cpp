//  main.cpp
//  byns'
//
//  Created by 안유림 on 2019/11/14.
//  Copyright © 2019 안유림. All rights reserved.
//

/* SeatINFO의 rnum = 0으로 초기화
 * SeatINFO의 snum 설정
 * snum에 맞춰서 출력하는 함수 새로 작성
 * SeatINFO의 price 설정
 */

#include "SeatINFO.h"
#include "UserINFO.h"
#include <iostream>
#include <list>

using namespace std;

list<Seat> setting();
void seat_print(list<Seat> SL);
void Booking(list<Seat> SL);
void write_usr(string name, int resnum, int seatnum); //고유번호 받은 후 사용자 파일에 저장하는 함수
void read_usr(int resNum); //예매 확인 할 때 입력된 고유번호가 사용자 파일에 있는지 확인하는 함수

list<Seat> setting()			// 자리정보 설정
{	
	list<Seat> SL;

	for (int i = 0; i < 64; i++)
	{
		Seat newNode(i, 10000, "", "", 0);
		SL.push_back(newNode);
	}

	return SL;
}

void seat_print(list<Seat> SL)		// 좌석상태에 따라 좌석도 출력
{
	list<Seat>::iterator iter;
	iter = SL.begin();

	cout << "\n  ======SCREEN======\n";
	cout << "  a b c d\t e f g h\n";
	for (int i = 1; i < 9; i++)
	{
		cout << i;

		for (int j = 1; j < 9; j++)
		{
			if (j == 5)
				cout << "\t";
			if ((*iter).getState() == 0)		// 좌석상태 가져오기
				cout << " O";
			else
				cout << " X";

			iter++;
		}
		cout << endl;
	}

	cout << endl;
}

// 예약 과정
void Booking(list<Seat> SL) 
{
	list<Seat>::iterator iter;		// 좌석정보 가져올 반복자
	iter = SL.begin();

	while (true)
	{
		seat_print(SL);

		int many = 0;       // 예매할 좌석 수
		cout << "예매할 좌석 수를 입력하세요";
		cout << "\n(메뉴로 돌아가고 싶으시면 0를 입력하세요)\n>> ";
		cin >> many;

		if (many == 0)
			break;

		string seat = "";       // 예매할 자리
		cout << "예매할 좌석을 입력하세요 : ";

		int count = 0;      // 예매 성공한 수

		for (int i = 0; i < many; i++)
		{
			cin >> seat;		// 문자열로 좌석번호 받아 정수로 변경
			int num = (seat[1] - '1') * 8 + seat[0] - 'a';
			
			for(iter = SL.begin();((*iter).getSeatNum())!=num; iter++);
				
			if ((*iter).getState() == 0)		// 이미 예약된 경우
			{
				cout << "이미 예약된 좌석입니다.\n";
				break;
			}
			else				
			{
				(*iter).setState(0);
				count++;
			}
		}

		char answer = '\0';         // 결제 대답

		if (count != 0)
		{
			cout << "결제할 금액은 " << count * ((*iter).getPrice()) << "입니다.\n결제하시겠습니까? (y or n) : ";
			cin >> answer;

			if (answer == 'y')
			{
				int choice=0;

				cout << "결제할 방법을 선택하세요" << endl;
				cout << "1. 카드  ";
				cout << "2. 무통장 입금  ";
				cout << "3. 휴대폰 결제  ";
				
				cin >> choice;

				switch (choice)
				{
				case 1: 
				case 2:
				case 3: 
					cout << "예매되었습니다.\n";
				}
			}
			
			else if (answer == 'n')
				cout << "취소되었습니다.\n";
		}
	}
}
