#include <iostream>
#include "myDate.h"
using namespace std;

//empty default constructor
myDate::myDate(){

}
//overriding constructor
myDate::myDate(int M, int D, int Y){
  this -> m = M;
  this -> d = D;
  this -> y = Y;

}
void myDate::display(){
  cout << m << "/" << d << "/" << y;
}
void myDate::increaseDate(){

}
void myDate::decreaseDate(){

}
int myDate::daysBetween(myDate D){

}

int myDate::getMonth(){

}

int myDate::getDay(){

}

int myDate::getYear(){

}

int myDate::dayOfYear(){

}