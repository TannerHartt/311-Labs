#ifndef PLANE_H
#define PLANE_H

#include <vector>
#include <list>
#include <string>
using namespace std;


class Plane {
  private:
    int id;
    int arrivalTime;
    int departTime;
    string state;
    int priority;
  
  public:
    Plane();
    Plane(int, int, int, int);
    bool compare(Plane);
    int getP();

    bool operator<(Plane& other);
};

#endif
