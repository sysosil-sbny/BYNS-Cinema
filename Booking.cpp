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



#include "SeatINFO.hpp"

#include "UserINFO.hpp"

#include <iostream>

#include <list>

#include <string>

using namespace std;

string name();

string randchar();

void write_usr(string,string,int);

list<Seat> setting(int abc, int num);

void seat_print(list<Seat> SL, int abc, int num);

void Booking(list<Seat> SL, int abc, int num);



list<Seat> setting(int abc, int num)			// 자리정보 설정

{	

	list<Seat> SL;



	for (int i = 0; i < abc*num; i++)

	{

		Seat newNode(i, 10000, "", "", 0);

		SL.push_back(newNode);

	}



	return SL;

}



void seat_print(list<Seat> SL, int abc, int num)		// 좌석상태에 따라 좌석도 출력

{

	list<Seat>::iterator iter;

	iter = SL.begin();



	cout << "\n  ======SCREEN======\n";

    for(int i=1; i<abc+1; i++)

    {

		char al = 'a'+i-1;

        if(i%5==0)

            cout << "\t";

        cout << " " << al;



    }

    cout << endl;

	for (int i = 1; i < num+1; i++)

	{

		cout << i;



		for (int j = 1; j < abc+1; j++)

		{

			if (j%5 == 0)

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

	return; 

}



// 예약 과정

void Booking(list<Seat> SL, int abc, int num)

{

	list<Seat>::iterator iter;		// 좌석정보 가져올 반복자

	iter = SL.begin();

    

	while (true)

	{

		seat_print(SL, abc, num);
int many = 0; 

cout << "\n예매현황입니다. \n\n메뉴로 돌아가고 싶으시면 0 예매를 계속하시려면 1을 입력하세요.\n>> ";
cin >> many;

		



		if (many == 0)

			return;

		/*      // 예매할 좌석 수

		cout << "예매할 좌석 수를 입력하세요";

		

		*/



		string seat = "";       // 예매할 자리

		cout << "\n예매할 좌석을 입력하세요 : ";



		int count1 = 0;



        int count2 = 0;



        int count3 = 0; // 예매 성공한 수

int count = 0;      // 예매 성공한 수
int n;//좌석번호 받을 변수



		//for (int i = 0; i < many; i++)

		//{

			cin >> seat;		// 문자열로 좌석번호 받아 정수로 변경

			n = (seat[1] - '1') * num + seat[0] - 'a';

			cout << endl;

			for(iter = SL.begin();((*iter).getSeatNum())!=n; iter++);

				

			if ((*iter).getState() == 0)		// 이미 예약된 경우

			{

				cout << "이미 예약된 좌석입니다.\n";

				continue;

			}

			else				

			{

				(*iter).setState(0);

				if (n < abc * (num / 3))



                    count1++;



                else if (abc * (num / 3) <= n < abc * (num / 3) * 2)



                    count2++;



                else



                    count3++;

			}

//		}



		char answer = '\0';         // 결제 대답



		if (count1 != 0 || count2 != 0 || count3 != 0) {



            cout << "결제할 금액은 "



                 << count1 * ((*iter).getPrice()) * 0.8 +



                        count2 * ((*iter).getPrice()) * 0.9 +



                        count3 * ((*iter).getPrice())



                 << "입니다.\n결제하시겠습니까? (y or n) : ";

			cin >> answer;

cout << endl;

			if (answer == 'y')

			{

				int choice=0;



				cout << "결제할 방법을 선택하세요" << endl;

				cout << "1. 카드  \n";

				cout << "2. 무통장 입금  \n";

				cout << "3. 휴대폰 결제  \n";

				cout << ">> ";

				

				cin >> choice;

cout << endl;

				switch (choice) {



				case 1:

break;



				case 2:



					int bank; //은행 선택, 계좌번호 랜덤생성



					cout << "1. 우리은행\n"



						<< "2. 하나은행\n"



						<< "3. 국민은행\n"



						<< "4. 신한은행\n";

					cout<<">> ";



					cin >> bank;

cout << endl;

					switch (bank) {



					case 1:



						cout << "우리은행 12347654333\n "



							"예금주:(주)빈스";



						cout << "로"



							<< count1 * ((*iter).getPrice()) * 0.8 +



							count2 * ((*iter).getPrice()) * 0.9 +



							count3 * ((*iter).getPrice())



							<< "원 입금하세요";



						break;







					case 2:



						cout << "하나은행 83271616889\n "



							"예금주:(주)빈스";



						cout << "로"



							<< count1 * ((*iter).getPrice()) * 0.8 +



							count2 * ((*iter).getPrice()) * 0.9 +



							count3 * ((*iter).getPrice())



							<< "원 입금하세요";



						break;







					case 3:



						cout << "국민은행 37289193842\n "



							"예금주:(주)빈스";



						cout << "로"



							<< count1 * ((*iter).getPrice()) * 0.8 +



							count2 * ((*iter).getPrice()) * 0.9 +



							count3 * ((*iter).getPrice())



							<< "원 입금하세요";



						break;







					case 4:



						cout << "신항은행 47281048018\n "



							"예금주:(주)빈스";



						cout << "로"



							<< count1 * ((*iter).getPrice()) * 0.8 +



							count2 * ((*iter).getPrice()) * 0.9 +



							count3 * ((*iter).getPrice())



							<< "원 입금하세요";



						break;



					}

break;







				case 3:



					int phone;

cout<<endl;



					cout << "1. SKT\n"



						<< "2. KT\n"



						<< "3. LG\n"



						<< "4. 알뜰폰\n";

cout<<">> ";



					cin >> phone;



cout << endl;



					switch (phone) {



					case 1:



					case 2:



					



					case 3:



						

					case 4:



						cout << "휴대폰 번호를 입력하세요 : ";



						string pnum;



						cin >> pnum;



						break;



					}



				}

					//string n="";

cout<<endl;

					string nn = name();

					string rnum;//resnum

					rnum = randchar();

					cout<<nn<<" 님의 고유번호는 "<<rnum<<"입니다."<<endl;

					write_usr(nn, rnum, n);

					cout << "예매되었습니다.\n";

				}

			}

			

			else if (answer == 'n')

				cout << "취소되었습니다.\n";

		}



}

