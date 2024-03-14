#include "helper.cpp"
using namespace std;



int main()
{
    srand(time(NULL));
    vector<int> v;
    vector<double> timesList;
    vector<size_t> sizes = {10, 100, 1000, 5000, 10000};
    
    //runAllSorts(v, timesList); // Part 2 Question 1


    cout << "\n\n\n\n========================= Start of part 2 =========================\n";

    // ofstream outputFile("outputs/output.txt", ios::app);
    // ofstream outputFile("outputs/output.txt");

    runAverageCases(v, timesList, sizes);

    cout << "\n========================= End of part 2 =========================\n";


    return 0;
}