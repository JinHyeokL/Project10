#include <iostream>
#include "Printer.h"

using namespace std;

int main() {
    InkJetPrinter inkjet("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);

    cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
    inkjet.show();
    laser.show();

    char aw;
    do {
        int num, pages;
        cout << "\n프린터(1: 잉크젯, 2: 레이저)와 매수 입력> ";
        cin >> num >> pages;

        if (num == 1) {
            inkjet.print(pages);
            if (pages <= inkjet.paper) {
                cout << "프린트 하였습니다." << endl;
            }
        }
        else if (num == 2) {
            laser.print(pages);
            if (pages <= laser.paper) {
                cout << "프린트 하였습니다." << endl;
            }
        }
        else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        cout << "\n현재 프린터 상태:" << endl;
        inkjet.show();
        laser.show();

        cout << "계속 프린트하시겠습니까?(y/n) ";
        cin >> aw;
    } while (aw == 'y');

    return 0;
}
