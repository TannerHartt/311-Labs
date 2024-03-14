#include <iostream>
#include <memory>
#include <vector>
#include <time.h>
#include <math.h>
#include <chrono>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <fstream>
using namespace std;

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
    if (leftIndex >= rightIndex) return;
    int pivotIndex = pivot(v, leftIndex, rightIndex);
    quickSort(v, leftIndex, pivotIndex - 1);
    quickSort(v, pivotIndex + 1, rightIndex);
}

void quickSort(vector<int> &v) {
    quickSort(v, 0, v.size() - 1);
}


bool isSorted(vector<int> v) {
    for (int val = 0; val < v.size() - 1; val++)
    {
        if (v[val] > v[val + 1])
            return false;
    }
    return true;
}