#ifndef PLANE_H
#define PLANE_H

#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;


class Plane {
  private:
    int id;
    int arrivalTime;
    int priority;
    string state; // Arriving or departing?
  
  public:
    Plane();
    Plane(int, int, string, int);
    bool compare(Plane);
    int getID();
    void setID(int);
    int getAT();
    void setAT(int);
    int getP();
    void setP(int);
    void setState(string);
    string getState();

    bool operator<(Plane& other);
    bool operator>(Plane& other);
};

#endif
