#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#define SIZE 100

typedef unsigned char BYTE;

char** getStringArr(int* size);
int comperString(void* elem1, void* elem2);
int comperInt(void* elem1, void* elem2);
int binSearch(void* Arr, int Size, int ElemSize, void* Item, int (*compare)(void*, void*));
