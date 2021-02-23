#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class myDate{

  private:
    int m;
    int d;
    int y;

  public:
    myDate();
    myDate(int M, int D, int Y);
    void display();
    void increaseDate(int N);
    void decreaseDate(int N);
    int daysBetween(myDate D);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
};