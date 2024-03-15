#include "helper.cpp"



int main()
{
    srand(time(NULL));
    vector<int> v;
    vector<double> timesList;
    
    //cout << "\n\n\n\n========================= Start of part 1 =========================\n";
    //runAllSorts(v, timesList); // Part 2 Question 1
    //cout << "\n========================= End of part 1 =========================\n";


    //cout << "\n\n\n\n========================= Start of part 2 =========================\n";
    // ofstream outputFile("outputs/output.txt", ios::app);
    // ofstream outputFile("outputs/output.txt");

    //runAverageCases(v, timesList);
    runBestCases(v, timesList);
    //cout << "\n========================= End of part 2 =========================\n";

    return 0;
}