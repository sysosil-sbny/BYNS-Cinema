#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "SeatINFO.h"
#include "UserINFO.h"
#include <fcntl.h>
#include <list>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LENGTH 8

using namespace std;

void write_usr(string name, string resnum, int seatnum) {
	User usr(name, resnum, seatnum);
	string filepath = "./UserList.dat";
	int fd = open(filepath.c_str(), O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fd == -1) {
		perror("open() error");
		//return 1;
	}
	if (write(fd, &usr, sizeof(User)) == -1) {
		perror("write() error");
		// return 2;
	}

	close(fd);
}

void read_usr(string resNum) {
	string filepath = "./UserList.dat";
	int fd = open(filepath.c_str(), O_RDONLY);
	if (fd == -1) {
		perror("open() error");
		// return 1;
	}
	ssize_t rSize = 0;
	User usr = User();
	list<User> usrList;
	do {
		rSize = read(fd, &usr, sizeof(User));

		if (rSize == -1) {
			perror("read() error!");
			// return 2;
		}

		if (rSize == 0) {
			/// break;
		}

		usrList.push_back(usr);
	} while (rSize > 0);

	close(fd);

	list<User>::iterator iter;
  int count = 0;
	for (iter = usrList.begin(); iter != usrList.end(); ++iter) {
		int  same = strcmp(iter->getResNum().c_str(), resNum.c_str());
        if (same == 0) {
            cout << "예매하신 좌석은 " << iter->getSeatNum() << "입니다."
                 << iter->getResNum() << " " << iter->getName() << endl;
            count++;
            break;
        }
else {
continue;
}
}
    if (count == 0)
        cout << "예매하신 내역이 없습니다." << endl;
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

	
