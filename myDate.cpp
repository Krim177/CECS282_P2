#include <iostream>
#include <string>
#include <cstring>
#include "myDate.h"
using namespace std;

int G2J(int month,int day, int year){
  int jd;
  int i=year;
  int j=month;
  int k=day;

  jd= k-32075 +1461*(i+4800+(j-14)/12)/4+367*(j-2-(j-14)/12*12)/12-3*((i+4900+(j-14)/12)/100)/4;
   
  //cout<<jd<<endl;
  return jd;
}

void J2G(int jd, int &month, int &day, int &year){
  int l,n,i,j,k;

  l=jd+68569;   
  n= 4*l/146097;
  l=l-(146097*n+3)/4;    
  i=4000*(l+1)/1461001;
  l=l-1461*i/4+31;
  j=80*l/2447;
  k=l-2447*j/80;
  l=j/11;
  j=j+2-12*l;
  i=100*(n-49)+i+l;

  year=i;
  month=j;
  day=k;

  //cout << month << "/" << day << "/" << year << endl;

}

//empty default constructor
myDate::myDate(){
  m = 5; //
  d = 11;
  y = 1959;

}
//overriding constructor
myDate::myDate(int M, int D, int Y){
  
  int jd = G2J(1, 1, Y); //#jd of the leap year
  int newJd = G2J(1, 1, Y+1); //This calc the #jd after the leap yr

  if(M > 12 || M < 1 || D > 31 || D < 1){
    m = 3; d = 11; y = 1959;
  }
  else if(D > 28){
    if(D == 29 && M == 2 && (newJd - jd == 366)){
      m = M;  
      d = D;
      y = Y;
    }
    else if (D == 29 && M == 2 && (newJd - jd != 366)){
      m = 3; d = 11; y = 1959;
    }
    //months where the date is NOT 31: 
    else if(D == 31 && ((m < 7 && m % 2 == 0) || (m > 8 && m % 2 != 0))){
      m = 3; d = 11; y = 1959;
    }
    else{
    //cout << "I ran!" << endl;
    m = M;
    d = D;
    y = Y;
    }
  }
  else{
    //cout << "I ran!" << endl;
    m = M;
    d = D;
    y = Y;

  }
  
}

void myDate::display(){
  string YR;
  string MONTH;
  if(m == 1){
    MONTH = "January";
  }
  else if(m == 2){
    MONTH = "Febuary";
  }
  else if(m == 3){
    MONTH = "March";
  }
  else if(m == 4){
    MONTH = "April";
  }
  else if(m == 5){
    MONTH = "May";
  }
  else if(m == 6){
    MONTH = "June";
  }
  else if(m == 7){
    MONTH = "July";
  }
  else if(m == 8){
    MONTH = "August";
  }
  else if(m == 9){
    MONTH = "September";
  }
  else if(m == 10){
    MONTH = "October";
  }
  else if(m == 11){
    MONTH = "November";
  }
  else{
    MONTH = "December";
  }
  cout << MONTH << " " << d << ", " << y;
}

void myDate::increaseDate(int N){
  int jd = G2J(m, d, y);
  int newJd = jd + N;
  J2G(newJd, m, d, y);

}
void myDate::decreaseDate(int N){
  int jd = G2J(m, d, y);
  int newJd = jd - N;
  J2G(newJd, m, d, y);

}

int myDate::daysBetween(myDate D){

  int obj1Jd = G2J(m,d,y);
  int obj2Jd = G2J(D.m, D.d, D.y); //accesing the priv. data mem of the obj.
  int diff = obj2Jd - obj1Jd;

  return diff; 

}

int myDate::getMonth(){
  return m;
}

int myDate::getDay(){
  return d;
}

int myDate::getYear(){
  return y;
}

int myDate::dayOfYear(){
  int firstJDOfGivenYr = G2J(1, 1, y);
  int enteredJd = G2J(m, d, y);
  int totalDaysOfYr = (enteredJd - firstJDOfGivenYr) + 1;
   
  return totalDaysOfYr;
}

string myDate::dayName(){

  int day;
  int jd = G2J(m, d, y);
  day = jd % 7;
  string dayName;
  switch(day){
    case 0:
      dayName = "Monday";
      break;
    case 1:
       dayName = "Tuesday";
      break;
    case 2:
       dayName = "Wednesday";
      break;
    case 3:
       dayName = "Thursday";
      break;
    case 4:
       dayName = "Friday";
      break;
    case 5:
       dayName = "Saturday";
      break;
    case 6:
       dayName = "Sunday";
      break;
  }
return dayName;
}