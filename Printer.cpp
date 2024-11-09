#include "Printer.h"
#include <iostream>

using namespace std;

Printer::Printer(string model, string manufacturer, int paper)
    : model(model), manufacturer(manufacturer), paper(paper) {}

void Printer::show() const {
    cout << model << ", " << manufacturer << ", ���� ���� " << paper << "��" << endl;
}

bool Printer::canPrint(int pages) {
    if (paper < pages) {
        cout << "���̰� �����մϴ�." << endl;
        return false;
    }
    return true;
}

InkJetPrinter::InkJetPrinter(string model, string manufacturer, int paper, int availableInk)
    : Printer(model, manufacturer, paper), availableInk(availableInk) {}

void InkJetPrinter::print(int pages) {
    if (!canPrint(pages)) return;
    if (availableInk < pages) {
        cout << "��ũ�� �����մϴ�." << endl;
        return;
    }
    paper -= pages;
    availableInk -= pages;
}

LaserPrinter::LaserPrinter(string model, string manufacturer, int paper, int availableToner)
    : Printer(model, manufacturer, paper), availableToner(availableToner) {}

LaserPrinter::~LaserPrinter() {
    cout << "LaserPrinter �Ҹ��� ȣ���\n";
}

void LaserPrinter::print(int pages) {
    if (!canPrint(pages)) return;
    if (availableToner < pages) {
        cout << "��ʰ� �����մϴ�." << endl;
        return;
    }
    paper -= pages;
    availableToner -= pages;
}
