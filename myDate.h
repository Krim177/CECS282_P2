#include <iostream>


class myDate{

  private:
    int m;
    int d;
    int y;

  public:
    myDate();
    myDate(int M, int D, int Y);
    void display();
    void increaseDate();
    void decreaseDate();
    int daysBetween(myDate D);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
};