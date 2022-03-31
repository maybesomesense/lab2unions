#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Header.h"  // ����� ������� � ���������
#include "Header2.h" // ������ �������

int checkerForChar() { // �������, �������� �� ��� "char"
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

char* giveMemoryDisease(int amount) {  // ��������� ������ ��� �����,  � ������ ������ Disease
    char* disease = (char*)malloc(sizeof(char) * amount);
    return disease;
}

void show(struct info* kids, int amount) {                    // ����� ������ �� �����
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    struct headlines headline;
    SetConsoleTextAttribute(handle, FOREGROUND_RED);
    printf("%-10s\t", headline.firstHeadline);                // �������
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
    printf("%-10s\t", headline.secondHeadline);               // ��� �������
    SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
    printf("%-18s\t", headline.thirdHeadline);                // ������� �������
    SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("%-12s\t", headline.fourthHeadline);               // ��� ������
    SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("%-18s\t", headline.fifthHeadline);                // ����� ��������
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
    printf("%-20s\t\n", headline.sixthHeadline);              // ����� ��������
    for (int i = 0; i < amount; i++) {
        SetConsoleTextAttribute(handle, FOREGROUND_RED);
        printf("%-10s\t", kids[i].information[0].disease);     // �������
        SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
        printf("%-10s\t", kids[i].information[1].doctor);      // ��� �������
        SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
        printf("%-18s\t", kids[i].surnameDoctor);              // ������� �������
        SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("%-12s\t", kids[i].nameKid);                    // ��� ������
        SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("%-19s\t", kids[i].numberHospital);             // ����� ��������
        SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
        printf("%-20s\t\n", kids[i].addressHospital);          // ����� ��������
    }
}

char* enterStr(char* string)                          // ���� ������
{
    rewind(stdin);
    if (!string) return NULL;
    int i = 0;
    while ((*(string + i++) = (char)getchar()) != '\n');
    string[--i] = '\0';
    return string;
}

info* giveMemory(int amount) {                          // ������� ��������� ������ ��� ��������� info*
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

int str_cmp(const char* st1, const char* st2) { // ������� ���������� ���� ����� ��� ����������
    int i = 0;
    int j = 0;
    while (*st1) {     // ������ ���� �� ��������� ����� ('\0') ������ s1
        if (*(st1 + i) == ' ' || *(st1 + i) == '\0') return 1;
        if (*(st2 + j) == ' ' || *(st2 + j) == '\0') return -1;
        if (*(st1 + i) - *(st2 + j)) return *(st1 + i) - *(st2 + j);  // >0 ���� ASCII-���  *s1 > *s2
            // ����� <0
        else                                  // ��� ���������� �������� �������
        {
            i++;                            // � ������� ��������� ���� ��������
            j++;
        }
    }
    return *(st1 + i) - *(st2 + j);  // ������ ���� ��������� ������� ���� ���� ����������
}

info* sortForNames(info* needKids, int amount) { // ���������� ��� ���� names ��������� info �� ��������
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

info* enterInformation(info* kids, int amount) { // ���� ���� ������ � ���������
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

info* reallocStruct(info* neededStruct, int amount) {   // ������������� ������ � ���������
    neededStruct = (info*)realloc(neededStruct, amount * sizeof(info));
    return neededStruct;
}

info* finder(info* needKids, info* kids, int amount, char* disease, int* size) { // ����� �� ������� � ����
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

char* menu(int* choice) {   // ������� �������������� ���� � ������� ������������ ����� �������, ��� �� ����� ������ � ����������
    int flag = 0;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);         // ���������� ��� �����
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
    enterStr(request); // ���� ������� ������������ 
    
    return request;
}

info* universalFinder(info* needKids, info* kids, int amount, char* request, int* size, int choice) { // �������, ������� ������� ���������� �� ��������� ���� ������������� � ���������� ��� ���������� � advancedStruct
    int score = 0;
    int position = 0;
    switch (choice) {
    case 1: // ����� ��� ���� nameKid
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

    case 2: // ����� ��� ���� numberHospital
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

    case 3: // ����� ��� ���� addressHospital
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

    case 4: // ����� ��� ���� information.doctor
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

    case 5: // ����� ��� ���� surnameDoctor
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
    needKids = reallocStruct(needKids, *size); // ������������� ������ ��� ����� ���������
    return needKids;
}

info* advancedStruct(info* newNeedKids, info* needKids,int size) { // ����� � ����������� ����
    do {
        printf("Do you want to continue find information? Enter 1, if you want exit or other symbols to continue find information.\n");
        int repeat;                     // ���������� ��� �������
        repeat = checkerForChar();
        int choice;                     // ����������, ��� ����������� ����� ���� ���������� ������
        int newSize;                    // ����� ������ ��������� 
        if (repeat == 1) break;
        char* request = menu(&choice);  // ������������� ���� ��� ������������
        newNeedKids = universalFinder(newNeedKids, needKids, size, request, &newSize, choice);     
        if (newSize == size) printf("We cannot found something new!\n");
        else if (newSize == 0) printf("We found nothing according to your request\n");
        else show(newNeedKids, newSize);
    } while (1);
    return newNeedKids;
}


info* showNewStruct(info* kids, char* disease, int amount, int* size) {     // ����� �� ������� ����� � ����� �� �� �����
    info* needKids = giveMemory(amount);                        // ��������� ������ ��� ���������
    int repeat = 0;
    needKids = finder(needKids, kids, amount, disease, size);   // ������� ������ �����
    printf("System found this kids:\n");
    show(needKids, *size);                                      // ����� ��������� �� �����
    printf("\n");
    needKids = reallocStruct(needKids, *size);                  // ������������� ������ ����� ������
    printf("The system sorted them by name: \n");
    needKids = sortForNames(needKids, *size);                   // ��������� �� ������ �����
    show(needKids, *size);

    return needKids;
}
