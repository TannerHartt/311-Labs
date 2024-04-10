#include <iostream>
#include "Plane.h"

Plane::Plane() {}

Plane::Plane(int id, int arr, int deprt, int p) : id(id), arrivalTime(arr), departTime(deprt), priority(p) {}

bool Plane::compare(Plane other) {
    return priority < other.priority;
}

// Prefferred over the compare fnuction.
bool Plane::operator<(Plane& other) {
    return priority < other.priority;
}

int Plane::getP() {
    return priority;
}

