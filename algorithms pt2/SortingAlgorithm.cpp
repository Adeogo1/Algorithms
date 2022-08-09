//
// Created by adeog on 28/07/2022.
//
#include "SortingAlgorithm.h"



namespace SortingAlgorithms{

    namespace {
        void Swap(int &a, int &b){
            int temp;
            temp = a;
            a = b;
            b = temp;
        }

        int QuickSortPartition(int *arr, int left, int pivot){
            int low = left -1;
            int high = pivot -1;

            for (int i = left; i <= high; ++i) {
                if (arr[i] <= arr[pivot]){
                    low++;
                    Swap(arr[low], arr[i]);
                }
            }
            Swap(arr[low + 1], arr[pivot]);
            return low + 1;
        }
        void QuickSortRecursive(int *arr, int left, int pivot){
            if (left < pivot){
                int newPivot = QuickSortPartition(arr, left, pivot);
                QuickSortRecursive(arr, left, newPivot - 1);
                QuickSortRecursive(arr,newPivot +1, pivot);
            }
        }

        void Merge(int *arr, int low, int high, int mid){
            int i, j, k, c[50];
            i = low;
            k = low;
            j = mid + 1;
            while (i <= mid && j <= high)
            {
                if (arr[i] < arr[j])
                {
                    c[k] = arr[i];
                    k++;
                    i++;
                }
                else
                {
                    c[k] = arr[j];
                    k++;
                    j++;
                }
            }
            while (i <= mid)
            {
                c[k] = arr[i];
                k++;
                i++;
            }
            while (j <= high)
            {
                c[k] = arr[j];
                k++;
                j++;
            }
            for (i = low; i < k; i++)
            {
                arr[i] = c[i];
            }
        }

        void MergeSortRecursive(int *arr,int low,int high){
            if (low < high){
                int mid = (low + high) /2;
                MergeSortRecursive(arr,low, mid);
                MergeSortRecursive(arr,mid + 1, high);
                Merge(arr,low,high, mid);
            }
        }


    }



    void SelectionSort(int *arr, int size){
        int i,j,IndexOfSmallest;

        for ( i = 0; i < size - 1; i++) {
            IndexOfSmallest = i;
            for ( j = i+1; j < size ; j++) {
                if (arr[j] < arr[IndexOfSmallest]){
                    IndexOfSmallest = j;
                }
            }
            Swap(arr[i], arr[IndexOfSmallest]);
        }
    }

    void InsertionSort(int *arr, int size)
    {
        int value, index;
        for (int i = 0; i < size; ++i) {
            value = arr[i];
            index = i;
            while (index > 0 && arr[index-1] > value){
                arr[index] = arr[index-1];
                index = index-1;
            }
            arr[index] = value;
        }
    }

    void QuickSort(int *arr, int size){
        QuickSortRecursive(arr, 0 , size-1);
    }
    void MergeSort(int* arr, int size){
        MergeSortRecursive(arr,0, size-1);
    }
    void HeapSort(int *arr, int size){

    }
    void RadixSort(int *arr, int size){

    }
    void BubbleSort(int *arr, int size){

        int flag;//flag is to check if the array is sorted
        for (int k = 1; k < size; k++) {
            flag = 0;
            for (int i = 0; i < size-k; i++) {
                if (arr[i]>arr[i+1]){
                    Swap(arr[i], arr[i+1]);
                    flag = 1;
                }
            }
            if (flag == 0 ){//this means there was no swap operation performed so the array is sorted
                break;
            }
        }
    }


};