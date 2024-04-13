/***********************************************
************CSCI-311-PROJECT-2-V-2071***********
************************************************
*******CODE-CHECKER-STARTING-ALIGNMENT**********
************************************************
*************CONTROL-NUMBER-XA-72***************
************************************************
**REPORT-GENERATION-MODE-AUTO_SYNC-EXCEPTION-2**
************************************************
*****************DATETIME-SYS*******************
************************************************/


//G1_EXCEPTION: Only produce your code as directed in Section A, B, C, and D1_EXCEPTION.
//G2_EXCEPTION: Do not write anything at the other places in this file.
//D1_EXCEPTION: Put you name here (on this line): Tanner Hart
/***********************************************
*************SECTION-A-HEADERS******************
************************************************/
//SECTION_A_START: put your header files here using the include directive.
//G3_EXCEPTION: You can also declare using standard namespace if you like, but do not use any global variable or method.
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
    Plane() {}

    Plane(int id, int arr, string s, int p) : id(id), arrivalTime(arr), state(s), priority(p) {}

    // Extra function
    bool compare(Plane other) {
        return priority < other.priority;
    }

    // Preferred over the compare fnuction for compating two plane objects
    bool operator<(Plane& other) {
        return priority < other.priority;
    }

    bool operator>(Plane& other) {
        return priority > other.priority ||
            (priority == other.priority && 
            arrivalTime < other.arrivalTime);
    }

    int getP() {
        return priority;
    }
    void setP(int p) {
        priority = p;
    }
    int getAT() {
        return arrivalTime;
    }
    void setAT(int at) {
        arrivalTime = at;
    }

    void setState(string s) {
        state = s;
    }
    string getState() {
        return state;
    }
    int getID() {
        return id;
    }
    void setID(int i) {
        id = i;
    }

};




//SECTION_A_END: Section A ends here. 
/***********************************************
*************SECTION-A-HEADERS-END**************
************************************************/

/***********************************************
*************SECTION-B-CLASSES******************
************************************************/
//SECTION_B_START: put all your classes definitions here.



class PQueue {
    private:
        vector<Plane> heap;
        int size;

        void uwheapify(int index) {
            while (index > 0) {
                int parent = (index - 1) / 2;
                if (heap[index] < heap[parent]) {
                    swap(heap[index], heap[parent]);
                    index = parent;
                }
                else break;
            }
        }

        void dwheapify(int index) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }
            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                dwheapify(smallest);
            }
        }



    public:

        PQueue() {}
        PQueue(int s) : size(s) {}

        void push(Plane &plane) {
            heap.push_back(plane);
            size++;
            uwheapify(heap.size() - 1);
        }

        void insert(Plane &plane) {
            heap.push_back(plane);
            size++;
            uwheapify(heap.size() - 1);
            dwheapify(size - 1);
        }

        void pop() {
            if (!heap.empty()) {
                heap[0] = heap.back();
                heap.pop_back();
                size--;
                dwheapify(0);
            }
        }

        Plane peek() {
            return heap[0];
        }

        bool isEmpty() {
            return size == 0;
        }
        bool empty() {
            return size == 0;
        }

        void clear() {
            heap.clear();
            size = 0;
        }

        int getSize() {
            return size;
        }
};


//SECTION_B_END: Section B ends here. 
/***********************************************
*************SECTION-B-CLASSES-END**************
************************************************/


/***********************************************
*************SECTION-C-MAIN-FUNCTION************
************************************************/
//SECTION_C_START: write your main function here.


int main() {
    // I looked back at how you were handling the input reading in previous Driver files in other labs
    int in;
    cin >> in;

    vector<Plane> planes;
    PQueue runway;


    // Read file inputs
    for (int i=0; i<in; i++) {
        int ID, arrival, priority;
        string state;
        cin >> arrival >> ID >> state >> priority;
        Plane p = Plane(ID, arrival, state, priority);
        planes.push_back(p);
    }

    int currentTime;


    while (!runway.empty() || !planes.empty()) {
        cout << "Time step " << currentTime << endl;
        cout << "\tEntering simulation" << endl;
        
        // Add aircraft to the queue based on the current time
        while (!planes.empty() && planes.front().getAT() <= currentTime) {
            Plane p = planes.front();
            planes.erase(planes.begin());
            runway.push(p);
            cout << "\t" << p.getAT() << " " << p.getID() << " " << p.getState() << " " << p.getP() << endl;
        }

        // If the runway A and B are being used
        if (!runway.empty()) {
            Plane p = runway.peek();
            runway.pop();
            cout << "Runway A" << endl;
            cout << "\t" << p.getAT() << " " << p.getID() << " " << p.getState() << " " << p.getP() << endl;
        }

        if (!runway.empty()) {
            Plane p = runway.peek();
            runway.pop();
            cout << "\t" << p.getAT() << " " << p.getID() << " " << p.getState() << " " << p.getP() << endl;
        }

        currentTime++;
    }

    return 0;
}


//SECTION_C_END: Section C ends here. 
/***********************************************
************SECTION-C-MAIN-FUNCTION-END*********
************************************************/

/***********************************************
**************PLAGIARISM-RTNG-PRTCL-C***********
****************GEN-AI-RTNG-PRTCL-K*************
*********LOOP-CS_SEC-CS_CHR-STU_R_R_RFR*********
*****************DICT-A-ENTRY-2071**************
***************ORI-KTIAN@CSUCHICO.EDU***********
************************************************/

/***********************************************
*********CODE-CHECKER-ENDING-ALIGNMENT**********
************************************************/