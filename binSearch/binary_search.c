
#include"binary_search.h"

char** getStringArr(int* size)
{
    int i;
    scanf("%d", size);
    char c = getchar();
    char** stringArr = (char**)malloc(sizeof(char*) * (*size));

    for (i = 0; i < *size; i++)
    {
        stringArr[i] = (char*)malloc(sizeof(char) * SIZE);
        gets(stringArr[i]);
    }
    return stringArr;
}

int comperString(void* elem1, void* elem2)
{
    return strcmp(*(char**)elem1, *(char**)elem2);
}

int comperInt(void* elem1, void* elem2)
{
    return *(int*)elem1 - *(int*)elem2;
}

int binSearch(void* Arr, int Size, int ElemSize, void* Item, int (*compare)(void*, void*))
{
    int right = Size - 1, left = 0, plase;
    bool found = false;

    while (!found && (left <= right))
    {
        plase = (right + left) / 2;

        if (compare((BYTE*)Arr + plase * ElemSize, Item) == 0)
            found = true;
        else if (compare(Item, (BYTE*)Arr + plase * ElemSize) > 0)
            left = plase + 1;
        else
            right = plase - 1;
    }
    return found ? 1 : 0;
}
