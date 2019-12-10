#include "SeatINFO.hpp"

#include "UserINFO.hpp"

#include <fcntl.h>

#include <iostream>

#include <list>

#include <vector>

#include <string.h>

#include <string>

#include <sys/stat.h>

#include <sys/types.h>

#include <unistd.h>

#define MAX_LENGTH 8

#define BUFSIZE 1024

using namespace std;



vector<string> split(string data, char dot){

    vector<string> result;



    string one = "";



    for (int i = 0; i < data.size(); i++){

        if (data[i] == dot){

            result.push_back(one);

            one = "";

        } else {

            one += data[i];

        }

    }

    result.push_back(one);



    return result;

}





list<User> ul;



void write_usr(string name, string resnum, int seatnum) {

    User usr(name, resnum, seatnum);



    ul.push_back(usr);

    string filepath = "./UserList.dat";

    int fd = open(filepath.c_str(),  O_APPEND | O_CREAT  | O_WRONLY, 0644);

    if (fd == -1) {

        perror("open() error");

    }

    list<User>::iterator iter;

    for (iter = ul.begin();iter!=ul.end() ; ++iter) {

        string all = iter->getName() + "," + iter->getResNum() + "," + to_string(iter->getSeatNum()) + "\n";



        if (write(fd, all.c_str(), all.size()) == -1) {

            perror("write() error");

            exit(-2);

        }

    }

    close(fd);

}



void print_user(User test){

    cout << "Name \t" << test.getName() << endl;

    cout << "ResN \t" << test.getResNum() << endl;

    cout << "Seat \t" << test.getSeatNum() << endl;

}



void read_usr(string resNum) {

    string filepath = "./UserList.dat";

    int fd = open(filepath.c_str(), O_RDONLY);

    if (fd == -1) {

        perror("open() error");

    }



    ssize_t rSize = 0;

    vector<User> usrList;

    vector<int> seatData;



    char data[BUFSIZE];

    int size = read(fd, data, BUFSIZE);





    string stringData = string(data);

    vector<string> cutString = split(stringData, '\n');

    cutString.pop_back();



    for (auto i: cutString){

        vector<string> entry = split(i, ',');

        string name = entry[0];

        string res = entry[1];

        string numy = entry[2];



	int n = atoi(numy.c_str());



     if (name == "") break;







        User usr = User(name, res, n);



        seatData.push_back(atoi(entry[2].c_str()));



        usrList.push_back(usr);



    }


    close(fd);



    cout<<"========="<<endl;

    int same=1;


    int idx = -1;



    for (auto user_data: usrList) {



        idx ++;



        same = strcmp(user_data.getResNum().c_str(), resNum.c_str());



        string str = "";
        
	str.push_back(   'a' + seatData[idx]%8-(seatData[idx]/8));
	str.push_back('1' + seatData[idx]/8);
        if (same == 0) {
           // printf("%s님이 예매하신 좌석은 %s입니다.\n", user_data.getName(), str);
            //cout << user_data.getResNum() << " " << endl;
            cout<<user_data.getName()<<"님이 예매하신 좌석은 "<<str<<"입니다."<<endl;
            return;

        }

        else {

            continue;

        }

    }


    cout << "예매하신 좌석이 없습니다." << endl;

}


string randchar() {

	string resnum;

	int i;



	rand();

	for (i = 0; i < MAX_LENGTH / 2; i++) {

		char n = rand() % 26 + 'A';

		resnum += n;

	}

	for (i = MAX_LENGTH / 2; i < MAX_LENGTH; i++) {

		char n = rand() % 10 + '0';

		resnum += n;

	}

	return resnum;

}



	
