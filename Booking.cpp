#include "SeatINFO.h"
#include "UserINFO.h"
#include <iostream>
#include <list>

using namespace std;

list<Seat> setting(int abc, int num);
void seat_print(list<Seat> SL, int abc, int num);
void Booking(list<Seat> SL, int abc, int num);

list<Seat> setting(int abc, int num) // 자리정보 설정
{
    list<Seat> SL;

    for (int i = 0; i < abc * num; i++) {
        Seat newNode(i, 10000, "", "", 0);
        SL.push_back(newNode);
    }

    return SL;
}

void seat_print(list<Seat> SL, int abc, int num) // 좌석상태에 따라 좌석도 출력
{
    list<Seat>::iterator iter;
    iter = SL.begin();

    cout << "\n  ======SCREEN======\n";
    for (int i = 1; i < abc + 1; i++) {
        char al = 'a' + i - 1;
        if (i % 5 == 0)
            cout << "\t";
        cout << " " << al;
    }
    cout << endl;
    for (int i = 1; i < num + 1; i++) {
        cout << i;

        for (int j = 1; j < abc + 1; j++) {
            if (j % 5 == 0)
                cout << "\t";
            if ((*iter).getState() == 0) // 좌석상태 가져오기
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
void Booking(list<Seat> SL, int abc, int num) {
    list<Seat>::iterator iter; // 좌석정보 가져올 반복자
    iter = SL.begin();

    while (true) {
        seat_print(SL, abc, num);

        int many = 0; // 예매할 좌석 수
        cout << "예매할 좌석 수를 입력하세요";
        cout << "\n(메뉴로 돌아가고 싶으시면 0를 입력하세요)\n>> ";
        cin >> many;

        if (many == 0)
            return;

        string seat = ""; // 예매할 자리
        cout << "예매할 좌석을 입력하세요 : ";

        int count1 = 0;
        int count2 = 0;
        int count3 = 0; // 예매 성공한 수

        for (int i = 0; i < many; i++) {
            cin >> seat; // 문자열로 좌석번호 받아 정수로 변경
            int n = (seat[1] - '1') * num + seat[0] - 'a';

            for (iter = SL.begin(); ((*iter).getSeatNum()) != n; iter++)
                ;

            if ((*iter).getState() == 0) // 이미 예약된 경우
            {
                cout << "이미 예약된 좌석입니다.\n";
                continue;
            } else {
                (*iter).setState(0);
                if (n < abc * (num / 3))
                    count1++;
                else if (abc * (num / 3) <= n < abc * (num / 3) * 2)
                    count2++;
                else
                    count3++;
            }
        }

        char answer = '\0'; // 결제 대답

        if (count1 != 0 || count2 != 0 || count3 != 0) {
            cout << "결제할 금액은 "
                 << count1 * ((*iter).getPrice()) * 0.8 +
                        count2 * ((*iter).getPrice()) * 0.9 +
                        count3 * ((*iter).getPrice())
                 << "입니다.\n결제하시겠습니까? (y or n) : ";
            cin >> answer;

            if (answer == 'y') {
                int choice = 0;

                cout << "결제할 방법을 선택하세요" << endl;
                cout << "1. 카드  ";
                cout << "2. 무통장 입금  ";
                cout << "3. 휴대폰 결제  ";
                cout << endl<<">> ";

                cin >> choice;

				switch (choice) {
				case 1:
						break;
				case 2:
					int bank; //은행 선택, 계좌번호 랜덤생성
					cout << "1. 우리은행\n"
						<< "2. 하나은행\n"
						<< "3. 국민은행\n"
						<< "4. 신한은행\n ";
					cout<<">>";
					cin >> bank;
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
					cout << "1. SKT\n"
						<< "2. KT\n"
						<< "3. LG\n"
						<< "4. 알뜰폰\n ";
					cout<<">>";
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
}
