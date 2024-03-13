#include <iostream>
#include <memory>
#include <vector>
#include <time.h>
#include <math.h>
#include <chrono>
#include <algorithm>
#include <tuple>
#include <numeric>
using namespace std;

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

void merge(vector<int> &v, int leftIndex, int midIndex, int rightIndex) {
    int leftSize = midIndex - leftIndex + 1;
    int rightSize = rightIndex - midIndex;
    vector<int> leftArray(leftSize);
    vector<int> rightArray(rightSize);

    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = v[leftIndex + i];
    }
    for (int j = 0; j < rightSize; j++)
    {
        rightArray[j] = v[midIndex + 1 + j];
    }

    int index = leftIndex;
    int i = 0;
    int j = 0;
    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            v[index] = leftArray[i];
            index++;
            i++;
        }
        else
        {
            v[index] = rightArray[j];
            index++;
            j++;
        }
    }
    while (i < leftSize)
    {
        v[index] = leftArray[i];
        index++;
        i++;
    }
    while (j < rightSize)
    {
        v[index] = rightArray[j];
        index++;
        j++;
    }
}

void mergeSort(vector<int> &v, int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex)
        return;

    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(v, leftIndex, midIndex);
    mergeSort(v, midIndex + 1, rightIndex);
    merge(v, leftIndex, midIndex, rightIndex);
}

void mergeSort(vector<int> &v) {
    mergeSort(v, 0, v.size() - 1);
}




void bubbleSort(vector<int> &v) {
    for (int i = v.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                // int temp = v[j];
                // v[j] = v[j + 1];
                // v[j + 1] = temp;
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int> &v) {
    for (int i = 1; i < v.size(); i++)
    {
        int temp = v[i];
        int j = i - 1;
        while (j > -1 && temp < v[j])
        {
            v[j + 1] = v[j];
            v[j] = temp;
            j--;
        }
    }
}

void selectionSort(vector<int> &v) {
    for (int i = 0; i < v.size(); i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            // if (v[j] > v[minIndex]) reverse order sorted
            if (v[j] < v[minIndex])
                minIndex = j;
        }
        if (i != minIndex)
            swap(v[i], v[minIndex]);
    }
}

int pivot(vector<int> &v, int pivotIndex, int endIndex) {
    int swapIndex = pivotIndex;
    for (int i = pivotIndex + 1; i <= endIndex; i++)
    {
        if (v[i] < v[pivotIndex])
        {
            swapIndex++;
            swap(v[swapIndex], v[i]);
        }
    }
    swap(v[pivotIndex], v[swapIndex]);
    return swapIndex;
}

void quickSort(vector<int> &v, int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex)
        return;
    int pivotIndex = pivot(v, leftIndex, rightIndex);
    quickSort(v, leftIndex, pivotIndex - 1);
    quickSort(v, pivotIndex + 1, rightIndex);
}

void quickSort(vector<int> &v) {
    quickSort(v, 0, v.size() - 1);
}
