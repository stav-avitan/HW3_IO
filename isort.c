//
// Created by stavavitan on 1/7/23.
//
#include<stdio.h>


void shift_element(int* arr, int i);
void insertion_sort(int* arr, int len, int arr1[]);
void swap(int* left, int* right, int length);


int main()
{
#define size 50
    int flag = 1;
    int arr1[size];
    for (int i=0; i<size; i++){
        scanf ("%d", arr1 + i); //Equivalent to scanf("%d", &arr1[i])
    }
    insertion_sort ( &arr1, size, arr1);
    for (int i = 0; i < size ;i++) {
        if (i == size-1){
            flag =0;
        }
        printf("%d", *(arr1+i));

        if (flag){
            printf(",");
        }
    }
    return 0;
}

void shift_element(int* arr, int i)
{
    int count = 1;
    int flag = 1;
    int temp1 = *arr; // == arr[i]
    int temp2 =*(arr+count); // == arr[i+1]

    while (flag)
    {
        *(arr+count) = temp1;
        if (count <= i)
        {
            temp1 = temp2;
            count++;
            temp2 = *(arr + count);
        }
        else {

            flag = 0;

        }
    }
}

void insertion_sort(int* arr, int len, int arr1 [])
{
    int* currArr = arr+1;

    for (int i = 1; i < len; i++)
    {
        if (*(currArr - 1) > *currArr)
        {
            swap(arr, currArr, i+1);
        }
        currArr++;
    }

}


void swap(int* left, int* right, int length)
{
    int flag =1;
    int temp;
    int count = 1;
    while (flag)
    {
        if (*(right) < *(right - count))
        {
            count++;
        }
        else
        {
            count = count-1;
            temp=*right;
            shift_element(right - count, count-1);
            *(right - count) = temp;
            flag = 0;
        }
    }
}