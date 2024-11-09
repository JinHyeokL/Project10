#include <iostream>
#include "Printer.h"

using namespace std;

int main() {
    InkJetPrinter inkjet("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "�Ｚ����", 3, 20);

    cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����" << endl;
    inkjet.show();
    laser.show();

    char aw;
    do {
        int num, pages;
        cout << "\n������(1: ��ũ��, 2: ������)�� �ż� �Է�> ";
        cin >> num >> pages;

        if (num == 1) {
            inkjet.print(pages);
            if (pages <= inkjet.paper) {
                cout << "����Ʈ �Ͽ����ϴ�." << endl;
            }
        }
        else if (num == 2) {
            laser.print(pages);
            if (pages <= laser.paper) {
                cout << "����Ʈ �Ͽ����ϴ�." << endl;
            }
        }
        else {
            cout << "�߸��� �Է��Դϴ�." << endl;
            continue;
        }

        cout << "\n���� ������ ����:" << endl;
        inkjet.show();
        laser.show();

        cout << "��� ����Ʈ�Ͻðڽ��ϱ�?(y/n) ";
        cin >> aw;
    } while (aw == 'y');

    return 0;
}
