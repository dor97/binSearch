#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#define SIZE 100
#include"binary_search.h"

/*
The program commit a binary search on a void* array
*/

void freeMemory(int* intArr, int intSize, char** stringArr, int stringSize);
typedef unsigned char BYTE;


void main()

{

    int* intArr;

    int intSize, intToFind;

    char** stringArr, stringToFind[SIZE];

    int stringSize;

    int res;
    int i;



    // The user will enter the number of integers followed by the integers.


    scanf("%d", &intSize);
    intArr = (int*)malloc(sizeof(int) * intSize);

    for (i = 0; i < intSize; i++)
        scanf("%d", &(intArr[i]));


    // The user will enter the integer to find

    scanf("%d", &intToFind);



    //The function searches the array using binSearch()


    res = binSearch(intArr, intSize, sizeof(int), &intToFind, comperInt);

    if (res == 1)

        printf("The number %d was found\n", intToFind);

    else

        printf("The number %d was not found\n", intToFind);



    // The user will enter the number of strings (lines) followed by the strings.


    stringArr = getStringArr(&stringSize);



    // The user will enter the string to find

    gets(stringToFind);

    char* st = stringToFind;

    //The function searches the array using binSearch()

    res = binSearch(stringArr, stringSize, sizeof(char*), &st, comperString);



    if (res == 1)

        printf("The string %s was found\n", stringToFind);

    else

        printf("The string %s was not found\n", stringToFind);

    freeMemory(intArr, intSize, stringArr, stringSize);


}

void freeMemory(int* intArr, int intSize, char** stringArr, int stringSize)
{
    int i;
    free(intArr);
    for (i = 0; i < stringSize; ++i)
        free(stringArr[i]);
    free(stringArr);
}