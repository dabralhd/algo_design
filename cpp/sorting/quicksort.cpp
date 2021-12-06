#include <iostream>

/**
 * Find pivot element using median of left, right, and middle element.
 * Put pivot at index (right-1)
 * @param v the vector containing input keys
 * @param left index of leftmost element
 * @param right index of rightmost element
 * @return: the pivot element 
 */
int median3(vector<int>& v, int left, int right) {
    int mid = (left + right) / 2;
}


void quicksort(vector<int>& v, int left, int right) {
    if (left + 10 < right) {
        int pivot = median3(v, left, right);
        int i = left;
        int j = right - 1;
        while(true) {
            while(v[++i] < pivot) 
                ;
            while(pivot < v[--j])
                ;
            if(i < j)
                swap(v[j], v[i]);
            else
                break;
        }
        swap(v[i], v[right-1]);
        quicksort(v, left, i-1);
        quicksort(v, i+1, right);
    } else {
        insertion_sort(v, left, right);
    }
}