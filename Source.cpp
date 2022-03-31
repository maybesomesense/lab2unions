#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Header.h"  // новые функции и структуры
#include "Header2.h" // старые функции

int checkerForChar() { // функция, проверки на тип "char"
    int check;
    int flg = 0;
    int number;
    do {
        rewind(stdin);
        if (flg > 0) {
            printf("Enter correct value, not type 'char'\n");
        }
        check = scanf_s("%d", &number);
        flg++;
    } while (!check);
    return number;
}

char* giveMemoryDisease(int amount) {  // выделение памяти для строк,  в данном случае Disease
    char* disease = (char*)malloc(sizeof(char) * amount);
    return disease;
}

void show(struct info* kids, int amount) {                    // вывод данных на экран
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    struct headlines headline;
    SetConsoleTextAttribute(handle, FOREGROUND_RED);
    printf("%-10s\t", headline.firstHeadline);                // болезнь
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
    printf("%-10s\t", headline.secondHeadline);               // имя доктора
    SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
    printf("%-18s\t", headline.thirdHeadline);                // фамилия доктора
    SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("%-12s\t", headline.fourthHeadline);               // имя ребёнка
    SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("%-18s\t", headline.fifthHeadline);                // номер больницы
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
    printf("%-20s\t\n", headline.sixthHeadline);              // адрес больницы
    for (int i = 0; i < amount; i++) {
        SetConsoleTextAttribute(handle, FOREGROUND_RED);
        printf("%-10s\t", kids[i].information[0].disease);     // болезнь
        SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
        printf("%-10s\t", kids[i].information[1].doctor);      // имя доктора
        SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
        printf("%-18s\t", kids[i].surnameDoctor);              // фамилия доктора
        SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("%-12s\t", kids[i].nameKid);                    // имя ребёнка
        SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("%-19s\t", kids[i].numberHospital);             // номер больницы
        SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
        printf("%-20s\t\n", kids[i].addressHospital);          // адрес больницы
    }
}

char* enterStr(char* string)                          // ввод строки
{
    rewind(stdin);
    if (!string) return NULL;
    int i = 0;
    while ((*(string + i++) = (char)getchar()) != '\n');
    string[--i] = '\0';
    return string;
}

info* giveMemory(int amount) {                          // функция выделения памяти для структуры info*
    info* kids = (info*)malloc(amount * sizeof(info));
    for (int i = 0; i < amount; i++) {
        kids[i].nameKid = (char*) malloc(18);
        kids[i].numberHospital = (char*)malloc(20);
        kids[i].addressHospital = (char*)malloc(20);
        kids[i].surnameDoctor = (char*)malloc(20);
        kids[i].information[0].disease = (char*)malloc(20);
        kids[i].information[1].doctor = (char*) malloc(20);
    }
    return kids;
}

int str_cmp(const char* st1, const char* st2) { // функция сранивания двух строк для сортировки
    int i = 0;
    int j = 0;
    while (*st1) {     // истина пока не достигнут конец ('\0') строки s1
        if (*(st1 + i) == ' ' || *(st1 + i) == '\0') return 1;
        if (*(st2 + j) == ' ' || *(st2 + j) == '\0') return -1;
        if (*(st1 + i) - *(st2 + j)) return *(st1 + i) - *(st2 + j);  // >0 если ASCII-код  *s1 > *s2
            // иначе <0
        else                                  // при совпадении символов переход
        {
            i++;                            // к анализу следующей пары символов
            j++;
        }
    }
    return *(st1 + i) - *(st2 + j);  // строки либо полностью совпали либо одна окончилась
}

info* sortForNames(info* needKids, int amount) { // сортировка для поля names структуры info по алфавиту
    int i, j;
    info temp;
    for (i = 0; i < amount; i++) {
        for (j = 0; j < amount - i - 1; j++) {
            if (str_cmp(needKids[j].nameKid, needKids[j + 1].nameKid) > 0) {
                temp = needKids[j];
                needKids[j] = needKids[j + 1];
                needKids[j + 1] = temp;
            }
        }
    }
    return needKids;
}

info* enterInformation(info* kids, int amount) { // ввод всех данных в структуру
    for (int i = 0; i < amount; i++) {
        printf("Enter disease of kid %d: \n", i + 1);
        enterStr(kids[i].information[0].disease);
        printf("Enter name of doctor %d: \n", i + 1);
        enterStr(kids[i].information[1].doctor);
        printf("Enter name of kid %d: \n", i + 1);
        enterStr(kids[i].nameKid);
        printf("Enter number of hospital %d: \n", i + 1);
        enterStr(kids[i].numberHospital);
        printf("Enter address of hospital %d: \n", i + 1);
        enterStr(kids[i].addressHospital);
        printf("Enter surname of doctor %d \n", i + 1);
        enterStr(kids[i].surnameDoctor);
        system("CLS");
    }
    return kids;
}

info* reallocStruct(info* neededStruct, int amount) {   // перевыделение памяти в структуре
    neededStruct = (info*)realloc(neededStruct, amount * sizeof(info));
    return neededStruct;
}

info* finder(info* needKids, info* kids, int amount, char* disease, int* size) { // поиск по болезни в поле
    int score = 0;
    int position = 0;

    for (int i = 0; i < amount; i++) {
        for (int j = 0; kids[i].information[0].disease[j] != '\0'; j++) {
            if (kids[i].information[0].disease[j] == *(disease + j)) score++;
        }
        if (score == strlen(disease)) {
            needKids[position] = kids[i];
            position++;
        }
        score = 0;
    }
    *size = position;
    return needKids;
}

char* menu(int* choice) {   // функция интерактивного меню в которым пользователь может выбрать, что он хочет искать в дальнейшем
    int flag = 0;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);         // переменная для цвета
    char* request = (char*)malloc(30);
    do {
        if (flag > 0) printf("You entered an invalid value");
        printf("What you want to find? Enter one of the characters:\n");
        SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("1 - Name of kid\n");
        SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("2 - Number of hospital\n");
        SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
        printf("3 - Address of hospital\n");
        SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
        printf("4 - Name of doctor\n");
        SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
        printf("5 - Surname of doctor\n");

        *choice = checkerForChar();
        flag++;
    } while (*choice < 1 || *choice > 5);

    printf("And enter what you want to find\n");
    enterStr(request); // ввод запроса пользователя 
    
    return request;
}

info* universalFinder(info* needKids, info* kids, int amount, char* request, int* size, int choice) { // функция, которая находит информацию по заданному полю пользователем и возвращает всю информацию в advancedStruct
    int score = 0;
    int position = 0;
    switch (choice) {
    case 1: // поиск для поля nameKid
        for (int i = 0; i < amount; i++) {
            for (int j = 0; kids[i].nameKid[j] != '\0'; j++) {
                if (kids[i].nameKid[j] == *(request + j)) score++;
            }
            if (score == strlen(request)) {
                needKids[position] = kids[i];
                position++;
            }
            score = 0;
        }
        *size = position;
        break;

    case 2: // поиск для поля numberHospital
        for (int i = 0; i < amount; i++) {
            for (int j = 0; kids[i].numberHospital[j] != '\0'; j++) {
                if (kids[i].numberHospital[j] == *(request + j)) score++;
            }
            if (score == strlen(request)) {
                needKids[position] = kids[i];
                position++;
            }
            score = 0;
        }
        *size = position;
        break;

    case 3: // поиск для поля addressHospital
        for (int i = 0; i < amount; i++) {
            for (int j = 0; kids[i].addressHospital[j] != '\0'; j++) {
                if (kids[i].addressHospital[j] == *(request + j)) score++;
            }
            if (score == strlen(request)) {
                needKids[position] = kids[i];
                position++;
            }
            score = 0;
        }
        *size = position;
        break;

    case 4: // поиск для поля information.doctor
        for (int i = 0; i < amount; i++) {
            for (int j = 0; kids[i].information[1].doctor[j] != '\0'; j++) {
                if (kids[i].information[1].doctor[j] == *(request + j)) score++;
            }
            if (score == strlen(request)) {
                needKids[position] = kids[i];
                position++;
            }
            score = 0;
        }
        *size = position;
        break;

    case 5: // поиск для поля surnameDoctor
        for (int i = 0; i < amount; i++) {
            for (int j = 0; kids[i].surnameDoctor[j] != '\0'; j++) {
                if (kids[i].surnameDoctor[j] == *(request + j)) score++;
            }
            if (score == strlen(request)) {
                needKids[position] = kids[i];
                position++;
            }
            score = 0;
        }
        *size = position;
        break;
    }
    needKids = reallocStruct(needKids, *size); // перевыделение памяти для новой структуры
    return needKids;
}

info* advancedStruct(info* newNeedKids, info* needKids,int size) { // поиск в определённом поле
    do {
        printf("Do you want to continue find information? Enter 1, if you want exit or other symbols to continue find information.\n");
        int repeat;                     // переменная для повтора
        repeat = checkerForChar();
        int choice;                     // переменная, для определения какое поле необходимо искать
        int newSize;                    // новый размер структуры 
        if (repeat == 1) break;
        char* request = menu(&choice);  // интерактивное меню для пользователя
        newNeedKids = universalFinder(newNeedKids, needKids, size, request, &newSize, choice);     
        if (newSize == size) printf("We cannot found something new!\n");
        else if (newSize == 0) printf("We found nothing according to your request\n");
        else show(newNeedKids, newSize);
    } while (1);
    return newNeedKids;
}


info* showNewStruct(info* kids, char* disease, int amount, int* size) {     // поиск по болезни детей и вывод их на экран
    info* needKids = giveMemory(amount);                        // Выделение памяти для структуры
    int repeat = 0;
    needKids = finder(needKids, kids, amount, disease, size);   // функция поиска детей
    printf("System found this kids:\n");
    show(needKids, *size);                                      // вывод найденных на экран
    printf("\n");
    needKids = reallocStruct(needKids, *size);                  // перевыделение памяти после поиска
    printf("The system sorted them by name: \n");
    needKids = sortForNames(needKids, *size);                   // сортируем по именам детей
    show(needKids, *size);

    return needKids;
}
