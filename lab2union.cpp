#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Header.h"  // новые функции
#include "Header2.h" // старые функции

int main()
{
    int end;
    do {
        int amount;                                                          // кол-во детей
        int newSize;                                                         // кол-во новых найденных детей для дальнейшего поиска
        char* disease;                                                       // болезнь, которую необходимо найти
        printf("How many children?\n");
        amount = checkerForChar();                                           // ввод кол-во детей
        info* kids = giveMemory(amount);                                     // выделение памяти для структуры kids, где будут храниться данные о детях
        kids = enterInformation(kids, amount);                               // ввод всех данных в структуру
        show(kids, amount);                                                  // вывод введённой информации
        printf("Enter disease, which you want to find\n");                   // вводим болезнь, которую необходимо найти
        disease = giveMemoryDisease(15);                                     // выделяем память для болезни, которую будем искать
        enterStr(disease);                                                   // вводим болезнь
        info* needKids = showNewStruct(kids, disease, amount, &newSize);     // функция, которая выполняет поиск детей по болезни и выводит всех найденных на экран
        info* newNeedKids = giveMemory(newSize);                             // функция выделения памяти для структуры, в которую мы будем записывать других найденных детей
        newNeedKids = advancedStruct(newNeedKids, needKids,newSize);         // функция поиска по любому критерию от пользователя
        free(kids);                                                          // очищаем память всех структур
        free(needKids);
        free(newNeedKids);
        printf("If you want repeat the program - enter 1.\n");
        scanf_s("%d", &end);
    } while (end == 1);
}

