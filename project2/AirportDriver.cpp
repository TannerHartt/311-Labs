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
#include "Plane.h"
#include "Queue.cpp"
using namespace std;




//SECTION_A_END: Section A ends here. 
/***********************************************
*************SECTION-A-HEADERS-END**************
************************************************/

/***********************************************
*************SECTION-B-CLASSES******************
************************************************/
//SECTION_B_START: put all your classes definitions here.


int main() {
    int in;
    cin >> in;

    vector<Plane> planes;
    Queue runway;


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


//SECTION_B_END: Section B ends here. 
/***********************************************
*************SECTION-B-CLASSES-END**************
************************************************/


/***********************************************
*************SECTION-C-MAIN-FUNCTION************
************************************************/
//SECTION_C_START: write your main function here.





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