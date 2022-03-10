#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

const struct headlines {
    const char firstHeadline[8] = "Disease";
    const char secondHeadline[7] = "Doctor";
    const char thirdHeadline[18] = "Surname of doctor";
    const char fourthHeadline[12] = "Name of kid";
    const char fifthHeadline[19] = "Number of hospital";
    const char sixthHeadline[20] = "Address of hospital";

};

union names {
    char* disease;
    char* doctor;
};

struct info {
    char* nameKid;
    char* numberHospital;
    char* addressHospital;
    char* surnameDoctor;
    union names information;
};

struct saveInfo{
    char* disease;
    char* doctor;
};

void show(struct info* kids, saveInfo* information,int amount) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    struct headlines headline;
    SetConsoleTextAttribute(handle, FOREGROUND_RED);
    printf("%-8s\t", headline.firstHeadline);                //
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
    printf("%-7s\t", headline.secondHeadline);                 //
    SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
    printf("%-18s\t", headline.thirdHeadline);                //
    SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("%-12s\t", headline.fourthHeadline);               // 
    SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("%-18s\t", headline.fifthHeadline);                //
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
    printf("%-20s\t\n", headline.sixthHeadline);                 //
    for (int i = 0; i < amount; i++) {
        SetConsoleTextAttribute(handle, FOREGROUND_RED);
        strncpy(kids[i].information.disease, information[i].disease, 100);
        printf("%-8s\t", kids[i].information.disease);
        SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
        strncpy(kids[i].information.doctor, information[i].doctor, 100);
        printf("%-7s\t", kids[i].information.doctor);
        SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
        printf("%-18s\t", kids[i].nameKid);
        SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("%-12s\t", kids[i].numberHospital);               // 
        SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("%-19s\t", kids[i].addressHospital);                //
        SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
        printf("%-20s\t\n", kids[i].surnameDoctor);                 //
    }
}

char* enterStr(char* string)
{
    rewind(stdin);
    if (!string) return NULL;
    int i = 0;
    while ((*(string + i++) = (char)getchar()) != '\n');
    string[--i] = '\0';
    return string;
}

info* giveMemory(int amount) {
    info* kids = (info*)malloc(amount * sizeof(info));
    return kids;
}

saveInfo* giveMemoryInfo(int amount) {
    saveInfo* info = (saveInfo*)malloc(amount * sizeof(saveInfo));
    return info;
}

int str_cmp(const char* st1, const char* st2) { // сравниваем две строки
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

info* sortForNames(info* needKids, int amount) { // сортировка для names по алфавиту
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

void enterInformation(info* kids, saveInfo* information,int amount) {
    for (int i = 0; i < amount; i++) {
        printf("Enter disease of kid %d: \n", i + 1);
        kids[i].information.disease = (char*)malloc(sizeof(char) * 10);
        enterStr(kids[i].information.disease);
        strncpy(information[i].disease, kids[i].information.disease, 100);
        printf("Enter name of doctor %d: \n", i + 1);
        kids[i].information.doctor = (char*)malloc(sizeof(char) * 10);
        enterStr(kids[i].information.doctor);
        strncpy(information[i].doctor, kids[i].information.doctor, 100);
        printf("Enter name of kid %d: \n", i + 1);
        kids[i].nameKid = (char*)malloc(sizeof(char) * 10);
        enterStr(kids[i].nameKid);
        printf("Enter number of hospital %d: \n", i + 1);
        kids[i].numberHospital = (char*)malloc(sizeof(char) * 10);
        enterStr(kids[i].numberHospital);
        printf("Enter address of hospital %d: \n", i + 1);
        kids[i].addressHospital = (char*)malloc(sizeof(char) * 10);
        enterStr(kids[i].addressHospital);
        printf("Enter surname of doctor %d \n", i + 1);
        kids[i].surnameDoctor = (char*)malloc(sizeof(char) * 10);
        enterStr(kids[i].surnameDoctor);
        system("CLS");
    }
}

int strLen(const char* string) { // функция, которая считает длину строки
    int n = 0;
    for (; *(string + n) != '\0'; n++); //считает до нуль-символа
    return n;
}

info* reallocStruct(info* neededStruct, int amount) {
    neededStruct = (info*)realloc(neededStruct, amount * sizeof(info));
    return neededStruct;
}


info* showNewStruct(info* kids, saveInfo* information,char* disease, int amount) {
    info* needKids = giveMemory(amount);
    int score = 0;
    int position = 0;
    for (int i = 0; i < amount; i++) 
        strncpy(kids[i].information.disease, information[i].disease, 100);

    for (int i = 0; i < amount; i++) {
        for (int j = 0; kids[i].information.disease[j] != '\0'; j++) {
            if (kids[i].information.disease[j] == *(disease + j)) score++;
        }
        if (score == strLen(disease)) {
            needKids[position] = kids[i];
            position++;
        }
        score = 0;
    }
    int size = position;
    show(needKids, information,size);
    needKids = reallocStruct(needKids, size);
    show(needKids, information,size);
    /*for (int i = 0; i < amount; i++)
        strncpy(kids[i].information.doctor, information[i].doctor);*/
    needKids = sortForNames(needKids, size);
    show(needKids, information,size);
    return kids;
}