//
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

void setting();
void seat_print();
void Booking();
void write_usr(string name, int resnum, int seatnum); //고유번호 받은 후 사용자 파일에 저장하는 함수
void read_usr(int resNum); //예매 확인 할 때 입력된 고유번호가 사용자 파일에 있는지 확인하는 함수

Node *head = NULL;
Node *tail = NULL;
Node *cur = NULL;

typedef struct Node {
    Seat data; // 데이터 저장 공간
    struct Node *next; // 다음 노드의 연결을 위한 포인터
}Node;

void setting()
{
    list<Node> SL;
    Node *newNode = NULL;
    
    for(int i=1; i<65; i++)
    {
        newNode = new Node(); // 노드의 생성
        
        newNode->data.setSeatNum(i); // 노드에 데이터 저장
        newNode->data.setPrice(10000); // 노드에 데이터 저장
        newNode->data.setResNum(0); // 노드에 데이터 저장
        
        newNode->next = NULL; // 노드의 next변수를 초기화
        if (head == NULL) // 추가 된 노드가 첫 번째 노드일 경우
            head = newNode; // 첫 번째 노드를 head가 가리키게 함
        else // 첫 번째 노드가 아니라면
            tail->next = newNode;
        tail = newNode; // 노드의 끝을 tail이 가리키게 함
        SL.push_back(newNode);
    }
}

void seat_print()
{
    Node *cur = head;

    cout << "\n  ======SCREEN======\n";
    cout << "  a b c d\t e f g h\n";
    for(int i=0; i<8; i++)
    {
        cout << i;
        
        for(int j=1; j<9; j++)
        {
            if(j==5)
                cout << "\t";
            if(cur->data.getResNum()==0)
                cout << " O";
            else
                cout << " X";
            cur = cur->next;
        }
        cout << endl;
    }
    
    cout << endl;
}

void Booking() {
    Node *cur = head;
    //setting();
    
    while(true)
    {
        seat_print();
        
        int many= 0;       // 예매할 좌석 수
        cout << "예매할 좌석 수를 입력하세요";
        cout << "\n(메뉴로 돌아가고 싶으시면 0를 입력하세요)\n>> ";
        cin >> many;
        
        if(many==0)
            break;
    
        string seat = "";       // 예매할 자리
        cout << "예매할 좌석을 입력하세요 : ";
        
        int count = 0;      // 예매 성공한 수
        
        for(int i=0; i<many; i++)
        {
            cin >> seat;
            cur->data.setSeatNum((seat[0]-'a')*8 + seat[1]-'0');
            if(cur->data.getResNum()==1)
            {
                cout << "이미 예약된 좌석입니다.\n";
                break;
            }
            else
            {
                cur->data.setResNum(1);
                count++;
            }
        }
    
        char answer = '\0';         // 결제 대답

        if(count!=0)
        {
            cout << "결제할 금액은 " << count*(cur->data.getPrice()) << "입니다.\n결제하시겠습니까? (y or n) : ";
            cin >> answer;
    
            if(answer=='y')
                cout << "예매되었습니다.\n";
            else if(answer == 'n')
                cout << "취소되었습니다.\n";
        }
    }
}
