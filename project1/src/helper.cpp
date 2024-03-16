#include "sorts.cpp"


/******************************************************************************
 * Generate a vector of random integers in a given range. The ends *
 * of this range are inclusive. *
 * size - int - the number of integers in the resulting vector *
 * low, high - int - the range from which to draw random integers (inclusive) *
 * return - vector<int> - a vector of random integers *
 ******************************************************************************/
vector<int> randomVector(int size, int low, int high)
{
    vector<int> v(size, 0);
    for (int i = 0; i < size; i++)
    {
        v[i] = rand() % (high - low + 1) + low;
    }
    return v;
}

vector<int> randomVector()
{
    return randomVector(100, 0, 300);
}
vector<int> randomVector(int size)
{
    return randomVector(size, 0, 15000);
}

vector<int> sortedVector(int size, int low, int high)
{
    vector<int> v(size, 0);
    for (int i = 0; i < size; i++)
    {
        v[i] = rand() % (high - low + 1) + low;
    }
    sort(v.begin(), v.end());
    return v;
}
vector<int> sortedVector(int size)
{
    return sortedVector(size, 0, 15000);
}

vector<int> createReverseSortedVector(int size) {
    vector<int> v(size);
    for (int i = 0; i < size; ++i)
        v[i] = i;

    reverse(v.begin(), v.end());
    return v;
}

/******************************************************************
 * Calculate the sample standard deviation of a vector of doubles *
 * v - const vector<double> - a vector of doubles *
 * return - double - the sample standard deviation of v *
 ******************************************************************/
double sampleSD(const vector<double> v)
{
    double mean = 0;
    for (int i = 0; i < v.size(); i++)
    {
        mean += v[i];
    }
    mean = mean / v.size();
    double sd = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sd += (v[i] - mean) * (v[i] - mean);
    }
    sd = sd / (v.size() - 1);
    return sqrt(sd);
}

void printVector(vector<int> v)
{
    for (auto val : v) {
        cout << val << " ";
    }
}
void printVector(vector<double> v)
{
    for (auto val : v) {
        cout << val << " ";
    }
}

tuple<double, double, double> calculate(vector<double> &v) {
    if (v.empty()) return make_tuple(0.0, 0.0, 0.0);
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
    ofstream outputFile("outputs/stats.txt", ios::app);

    if (!outputFile.is_open()) {
        cerr << "Failed to open the file for writing.\n";
        return;
    }

    outputFile << "\n************************\n";
    outputFile << sortingMethod << " sort on 10 vectors of length " << v.size() << endl;
    outputFile << (isSorted(v) ? "Sorting Successful" : "Sorting Unsuccessful");
    outputFile << "\nTime taken: " << (totalTime / ONEMILLION) << "ms";
    outputFile << "\nMinimum: " << (min / ONEMILLION) << "; Mean: "<< (mean / ONEMILLION) << "; Standard deviation: " << (sampleSD(d) / ONEMILLION) << "; Maximum: "<< (max / ONEMILLION) << endl;
    outputFile << "\n************************\n"; 

    outputFile.close();
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
        case 'm': // Merge Sort
            mergeSort(v);
            break;
        default:
            cout << "Sorting method not specified" << endl;
    }
}


void runAllSorts(vector<int> &v, vector<double> &timesList) {

    // cout << "\n========================= Start of Quick sort =========================\n";
    double total;

    for (int i = 0; i < 10; i++) {
        v = randomVector();
        auto start = chrono::high_resolution_clock::now();
        runSpecificSort(v, 'q');
        auto end = chrono::high_resolution_clock::now();
        total = (end - start).count();
        timesList.push_back(total); 
    }
    printStats(v, timesList, total, "Quick");
    timesList.clear();
    v.clear();
    total = 0.0;
    // cout << "\n========================= End of Quick sort =========================\n";



    // cout << "\n========================= Start of Bubble sort =========================\n";
    for (int i = 0; i < 10; i++) {
        v = randomVector();
        auto start = chrono::high_resolution_clock::now();
        runSpecificSort(v, 'b');
        auto end = chrono::high_resolution_clock::now();
        total = (end - start).count();
        timesList.push_back(total); 
    }
    printStats(v, timesList, total, "Bubble");
    timesList.clear();
    v.clear();
    total = 0.0;
    // cout << "\n========================= End of Bubble Sort =========================\n";

    

    // cout << "\n========================= Start of Selection Sort =========================\n";
    for (int i = 0; i < 10; i++) {
        v = randomVector();
        auto start = chrono::high_resolution_clock::now();
        runSpecificSort(v, 's');
        auto end = chrono::high_resolution_clock::now();
        total = (end - start).count();
        timesList.push_back(total); 
    }
    printStats(v, timesList, total, "Selection");
    timesList.clear();
    v.clear();
    total = 0.0;
    // cout << "\n========================= End of Selection Sort =========================\n";



    // cout << "\n========================= Start of Insertion Sort =========================\n";
    for (int i = 0; i < 10; i++) {
        v = randomVector();
        auto start = chrono::high_resolution_clock::now();
        runSpecificSort(v, 'i');
        auto end = chrono::high_resolution_clock::now();
        total = (end - start).count();
        timesList.push_back(total); 
    }
    printStats(v, timesList, total, "Insertion");
    timesList.clear();
    v.clear();
    total = 0.0;
    // cout << "\n========================= End of Insertion Sort =========================\n";


    // cout << "\n========================= Start of Merge Sort =========================\n";
    for (int i = 0; i < 10; i++) {
        v = randomVector();
        auto start = chrono::high_resolution_clock::now();
        runSpecificSort(v, 'm');
        auto end = chrono::high_resolution_clock::now();
        total = (end - start).count();
        timesList.push_back(total); 
    }
    printStats(v, timesList, total, "Merge");
    timesList.clear();
    v.clear();
    total = 0.0;
    // cout << "\n========================= End of Merge Sort =========================\n"; 
}


void runWorstCases(vector<int> &v, vector<double> &timesList) {
    ofstream outputFile("outputs/worstcases.csv", ios::app);

    if (!outputFile.is_open()) {
        cerr << "Failed to open the file for writing.\n";
        return;
    }

    for (size_t size : sizes) { // Bubble sort
        for (int i = 0; i < 50; i++) {
            v = createReverseSortedVector(size);
            auto start = chrono::high_resolution_clock::now();
            runSpecificSort(v, 'b');
            auto end = chrono::high_resolution_clock::now();
            auto total = ((end - start).count()) / ONEMILLION; // convert nanoseconds to seconds
            timesList.push_back(total);
            outputFile << "bubble" << "," << size << "," << total << "\n";
        }
        timesList.clear();
        v.clear();
    }

    for (size_t size : sizes) { // Insertion sort
        for (int i = 0; i < 50; i++) {
            v = createReverseSortedVector(size);
            auto start = chrono::high_resolution_clock::now();
            runSpecificSort(v, 'i');
            auto end = chrono::high_resolution_clock::now();
            auto total = ((end - start).count()) / ONEMILLION; // convert nanoseconds to seconds
            timesList.push_back(total);
            outputFile << "insertion" << "," << size << "," << total << "\n";
        }
        timesList.clear();
        v.clear();
    }

    for (size_t size : sizes) { // Selection sort
        for (int i = 0; i < 50; i++) {
            v = randomVector(size);
            auto start = chrono::high_resolution_clock::now();
            runSpecificSort(v, 's');
            auto end = chrono::high_resolution_clock::now();
            auto total = ((end - start).count()) / ONEMILLION; // convert nanoseconds to seconds
            timesList.push_back(total);
            outputFile << "selection" << "," << size << "," << total << "\n";
        }
        timesList.clear();
        v.clear();
    }

    for (size_t size : sizes) { // Quick sort
        for (int i = 0; i < 50; i++) {
            v = randomVector(size);
            auto start = chrono::high_resolution_clock::now();
            runSpecificSort(v, 'q');
            auto end = chrono::high_resolution_clock::now();
            auto total = ((end - start).count()) / ONEMILLION; // convert nanoseconds to seconds
            timesList.push_back(total);
            outputFile << "quick" << "," << size << "," << total << "\n";
        }
        timesList.clear();
        v.clear();
    }
    outputFile.close();
}


void runAverageCases(vector<int> &v, vector<double> &timesList) {
    ofstream outputFile("outputs/averagecases.csv", ios::app);

    if (!outputFile.is_open()) {
        cerr << "Failed to open the file for writing.\n";
        return;
    }

    for (size_t size : sizes) { // Bubble sort
        for (int i = 0; i < 50; i++) {
            v = randomVector(size);
            auto start = chrono::high_resolution_clock::now();
            runSpecificSort(v, 'b');
            auto end = chrono::high_resolution_clock::now();
            auto total = ((end - start).count()) / ONEMILLION;
            timesList.push_back(total);
            outputFile << "Bubble" << "," << size << "," << total << "\n";
        }
        timesList.clear();
        v.clear();
    }

    for (size_t size : sizes) { // Insertion sort
        for (int i = 0; i < 50; i++) {
            v = randomVector(size);
            auto start = chrono::high_resolution_clock::now();
            runSpecificSort(v, 'i');
            auto end = chrono::high_resolution_clock::now();
            auto total = ((end - start).count()) / ONEMILLION;
            timesList.push_back(total);
            outputFile << "Insertion" << "," << size << "," << total << "\n";
        }
        timesList.clear();
        v.clear();
    }


    for (size_t size : sizes) { // Selection sort
        for (int i = 0; i < 50; i++) {
            v = randomVector(size);
            auto start = chrono::high_resolution_clock::now();
            runSpecificSort(v, 's');
            auto end = chrono::high_resolution_clock::now();
            auto total = ((end - start).count()) / ONEMILLION;
            timesList.push_back(total);
            outputFile << "Selection" << "," << size << "," << total << "\n";
        }
        timesList.clear();
        v.clear();
    }

    for (size_t size : sizes) { // Quick sort
        for (int i = 0; i < 50; i++) {
            v = randomVector(size);
            auto start = chrono::high_resolution_clock::now();
            runSpecificSort(v, 'q');
            auto end = chrono::high_resolution_clock::now();
            auto total = ((end - start).count()) / ONEMILLION;
            timesList.push_back(total);
            outputFile << "Quick" << "," << size << "," << total << "\n";
        }
        timesList.clear();
        v.clear();
    }       
    
    outputFile.close();
}

void runBestCases(vector<int> &v, vector<double> &timesList) {
    ofstream outputFile("outputs/bestcases.csv", ios::app);

    if (!outputFile.is_open()) {
        cerr << "Failed to open the file for writing.\n";
        return;
    }

    for (size_t size : sizes) { // Bubble sort
        for (int i = 0; i < 50; i++) {
            v = sortedVector(size);
            auto start = chrono::high_resolution_clock::now();
            runSpecificSort(v, 'b');
            auto end = chrono::high_resolution_clock::now();
            auto total = ((end - start).count()) / ONEMILLION;
            timesList.push_back(total);
            outputFile << "Bubble" << "," << size << "," << total << "\n";
        }
        timesList.clear();
        v.clear();
    }

    for (size_t size : sizes) { // Insertion sort
        for (int i = 0; i < 50; i++) {
            v = sortedVector(size);
            auto start = chrono::high_resolution_clock::now();
            runSpecificSort(v, 'i');
            auto end = chrono::high_resolution_clock::now();
            auto total = ((end - start).count()) / ONEMILLION;
            timesList.push_back(total);
            outputFile << "Insertion" << "," << size << "," << total << "\n";
        }
        timesList.clear();
        v.clear();
    }

    
    for (size_t size : sizes) { // Selection sort
        for (int i = 0; i < 50; i++) {
            v = sortedVector(size);
            auto start = chrono::high_resolution_clock::now();
            runSpecificSort(v, 's');
            auto end = chrono::high_resolution_clock::now();
            auto total = ((end - start).count()) / ONEMILLION;
            timesList.push_back(total);
            outputFile << "Selection" << "," << size << "," << total << "\n";
        }
        timesList.clear();
        v.clear();
    }


    for (size_t size : sizes) { // Quick sort
        for (int i = 0; i < 50; i++) {
            v = randomVector(size);
            auto start = chrono::high_resolution_clock::now();
            runSpecificSort(v, 'q');
            auto end = chrono::high_resolution_clock::now();
            auto total = ((end - start).count()) / ONEMILLION;
            timesList.push_back(total);
            outputFile << "Quick" << "," << size << "," << total << "\n";
        }
        timesList.clear();
        v.clear();
    }
    outputFile.close();
}