
#include <string>
using namespace std;

class Printer {
public:
    string model;
    string manufacturer;
    int paper;

public:
    Printer(string model, string manufacturer, int paper);

    void show() const;

    bool canPrint(int pages);
};

class InkJetPrinter : public Printer {
    int availableInk;

public:
    InkJetPrinter(string model, string manufacturer, int paper, int availableInk);

    void print(int pages);
};

class LaserPrinter : public Printer {
    int availableToner;

public:
    LaserPrinter(string model, string manufacturer, int paper, int availableToner);

    ~LaserPrinter();

    void print(int pages);
};
