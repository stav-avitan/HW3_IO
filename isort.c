//// Created by stavavitan on 1/7/23.//#include<stdio.h>#include<string.h>#define SIZE 50void shift_element(int* arr, int i);void insertion_sort(int* arr, int len);void swap(int* left, int* right, int length);int main(){    int flag = 1;    int arr1[SIZE] = {0};    for (int i=0; i<SIZE; i++)	{        scanf ("%d", arr1+i); //Equivalent to scanf("%d", &arr1[i])    }		insertion_sort (arr1, SIZE);  	    for (int i = 0; i < SIZE ;i++) {        if (i == SIZE-1){            flag =0;        }        printf("%d", *(arr1+i));        if (flag){            printf(",");        }    }					printf("\n");    return 0;}void shift_element(int* arr, int i){    int count = 1;    int flag = 1;    int temp1 = *arr; // == arr[i]    int temp2 =*(arr+count); // == arr[i+1]    while (flag)    {        *(arr+count) = temp1;        if (count <= i)        {            temp1 = temp2;            count++;            temp2 = *(arr + count);        }        else {            flag = 0;        }    }}void insertion_sort(int* arr, int len){    int* currArr = arr+1;	    for (int i = 1; i < len; i++)    {        if (*(currArr-1) > *(currArr))        {            swap(arr, currArr, i+1);        }        currArr++;    }}void swap(int* left, int* right, int length){	    int flag =1;    int temp;    int count = 1;    while (flag)    {		//if(length-count>0)			if (*(right) < *(right - count))			{				count++;			}			else if(*left > *(right))			{				temp=*right;				shift_element(left, length-2);				*(left) = temp;				flag = 0;			}			else			{				count = count-1;				temp=*right;				shift_element(right - count, count-1);				*(right - count) = temp;				flag = 0;			}	}}