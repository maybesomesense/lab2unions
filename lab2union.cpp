#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Header.h"

int main()
{
    int amount;
    char* disease;
    printf("How many children?\n");
    scanf_s("%d", &amount);
    info* kids = giveMemory(amount);
    saveInfo* information = giveMemoryInfo(amount);
    enterInformation(kids, information,amount);
    show(kids, information,amount);
    printf("Enter disease, which you want to find");
    disease = (char*)malloc(sizeof(char) * 10);
    enterStr(disease);
    info* needKids = showNewStruct(kids, information,disease,amount);
    
    free(kids);
    free(needKids);
}

