#include "helper.cpp"
using namespace std;

bool isSorted(vector<int> v) {
    for (int val = 0; val < v.size() - 1; val++)
    {
        if (v[val] > v[val + 1])
            return false;
    }
    return true;
}
std::tuple<double, double, double> calculate(vector<double> &v) {
    if (v.empty()) {
        return make_tuple(0.0, 0.0, 0.0);
    }
    double min = *min_element(v.begin(), v.end());
    double max = *max_element(v.begin(), v.end());
    double mean = accumulate(v.begin(), v.end(), 0.0) / v.size();

    return make_tuple(min, mean, max);
}

void printStats(vector<int> &v, vector<double> &d, double totalTime, string sortingMethod) {
    tuple<double, double, double> result = calculate(d);
    double min = get<0>(result);
    double mean = get<1>(result);
    double max = get<2>(result);

    cout << "\n************************\n";
    cout << sortingMethod << " sort on 10 vectors of length " << v.size() << endl;
    cout << (isSorted(v) ? "Sorting Successful" : "Sorting Unsuccessful");
    cout << "\nTime taken: " << totalTime;
    cout << "\nMinimum: " << min << "; Mean: "<< mean << "; Standard deviation: " << sampleSD(d) << "; Maximum: "<< max <<endl;
    cout << "\n************************\n"; 
}


void runSpecificSort(vector<int> &v, char sortFunctionOfChoice) {
    switch (sortFunctionOfChoice) {
        case 'i': // insertion sort
            insertionSort(v);
            break;
        case 'b': // bubble sort
            bubbleSort(v);
            break;
        case 's': // selection sort
            selectionSort(v);
            break;
        case 'q': // quicksort
            quickSort(v);
            break;
        default:
            cout << "Sorting method not specified" << endl;
    }
}

int main()
{
    srand(time(NULL));
    vector<int> v;
    vector<double> timesList;
    double total;

    cout << "\n=================== Start of Quick sort ==================\n";
    for (int i = 0; i < 10; i++) {
        v = randomVector(100, 1, 200);
        auto start = chrono::high_resolution_clock::now();
        runSpecificSort(v, 'q');
        auto end = chrono::high_resolution_clock::now();
        total = (end - start).count();
        timesList.push_back(total); 
        printStats(v, timesList, total, "Quick");
    }
    cout << "\n=================== End of Quick sort ==================\n";
    timesList.clear();



    cout << "\n=================== Start of Bubble sort ==================\n";
    for (int i = 0; i < 10; i++) {
        v = randomVector(100, 1, 200);
        auto start = chrono::high_resolution_clock::now();
        runSpecificSort(v, 'b');
        auto end = chrono::high_resolution_clock::now();
        total = (end - start).count();
        timesList.push_back(total); 
        printStats(v, timesList, total, "Bubble");
    }
    cout << "\n=================== End of Bubble Sort ==================\n";
    timesList.clear();

    

    cout << "\n=================== Start of Selection Sort ==================\n";
    for (int i = 0; i < 10; i++) {
        v = randomVector(100, 1, 200);
        auto start = chrono::high_resolution_clock::now();
        runSpecificSort(v, 's');
        auto end = chrono::high_resolution_clock::now();
        total = (end - start).count();
        timesList.push_back(total); 
        printStats(v, timesList, total, "Selection");
    }
    cout << "\n=================== End of Selection Sort ==================\n";
    timesList.clear();



    cout << "\n=================== Start of Insertion Sort ==================\n";
    for (int i = 0; i < 10; i++) {
        v = randomVector(100, 1, 200);
        auto start = chrono::high_resolution_clock::now();
        runSpecificSort(v, 'i');
        auto end = chrono::high_resolution_clock::now();
        total = (end - start).count();
        timesList.push_back(total); 
        printStats(v, timesList, total, "Insertion");
    }
    cout << "\n=================== End of Insertion Sort ==================\n";
    timesList.clear();

    return 0;
}