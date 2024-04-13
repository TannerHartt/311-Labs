#include "Plane.h"

Plane::Plane() {}

Plane::Plane(int id, int arr, string s, int p) : id(id), arrivalTime(arr), state(s), priority(p) {}

// Extra function
bool Plane::compare(Plane other) {
    return priority < other.priority;
}

// Prefferred over the compare fnuction.
bool Plane::operator<(Plane& other) {
    return priority < other.priority;
}

bool Plane::operator>(Plane& other) {
        return priority > other.priority ||
               (priority == other.priority && 
               arrivalTime < other.arrivalTime);
}

int Plane::getP() {
    return priority;
}
void Plane::setP(int p) {
    priority = p;
}
int Plane::getAT() {
    return arrivalTime;
}
void Plane::setAT(int at) {
    arrivalTime = at;
}

void Plane::setState(string s) {
    state = s;
}
string Plane::getState() {
    return state;
}
int Plane::getID() {
    return id;
}
void Plane::setID(int i) {
    id = i;
}
