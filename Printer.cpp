#include "Printer.h"
#include <iostream>

using namespace std;

Printer::Printer(string model, string manufacturer, int paper)
    : model(model), manufacturer(manufacturer), paper(paper) {}

void Printer::show() const {
    cout << model << ", " << manufacturer << ", 남은 종이 " << paper << "장" << endl;
}

bool Printer::canPrint(int pages) {
    if (paper < pages) {
        cout << "종이가 부족합니다." << endl;
        return false;
    }
    return true;
}

InkJetPrinter::InkJetPrinter(string model, string manufacturer, int paper, int availableInk)
    : Printer(model, manufacturer, paper), availableInk(availableInk) {}

void InkJetPrinter::print(int pages) {
    if (!canPrint(pages)) return;
    if (availableInk < pages) {
        cout << "잉크가 부족합니다." << endl;
        return;
    }
    paper -= pages;
    availableInk -= pages;
}

LaserPrinter::LaserPrinter(string model, string manufacturer, int paper, int availableToner)
    : Printer(model, manufacturer, paper), availableToner(availableToner) {}

LaserPrinter::~LaserPrinter() {
    cout << "LaserPrinter 소멸자 호출됨\n";
}

void LaserPrinter::print(int pages) {
    if (!canPrint(pages)) return;
    if (availableToner < pages) {
        cout << "토너가 부족합니다." << endl;
        return;
    }
    paper -= pages;
    availableToner -= pages;
}
