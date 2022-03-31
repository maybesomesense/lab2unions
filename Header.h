union names {
    char* disease;          // болезнь
    char* doctor;           // имя доктора
};

struct info {
    char* nameKid;          // имя ребёнка
    char* numberHospital;   // номер больницы
    char* addressHospital;  // адрес больницы
    char* surnameDoctor;    // фамилия доктора
    names information[2];   // массив объединений
};

const struct headlines {    // заголовки для show
    const char firstHeadline[8] = "Disease";
    const char secondHeadline[7] = "Doctor";
    const char thirdHeadline[18] = "Surname of doctor";
    const char fourthHeadline[12] = "Name of kid";
    const char fifthHeadline[19] = "Number of hospital";
    const char sixthHeadline[20] = "Address of hospital";

};

char* menu(int*);                                               // интерактивное меню
info* universalFinder(info*, info*, int, char*, int*, int);     // функция, которая находит информацию по заданному полю пользователем и возвращает всю информацию в advancedStruct 
void show(info*, int);                                          // вывод данных на экран
info* sortForNames(info*, int);                                 // сортировка для поля names структуры info по алфавиту
info* enterInformation(info*,int);                              // ввод всех данных в структуру
info* reallocStruct(info*, int);                                // перевыделение памяти в структуре
info* finder(info*, info*, int, char*, int*);                   // поиск по болезни в поле
info* showNewStruct(info*, char*, int, int*);                   // поиск по болезни детей и вывод их на экран
info* advancedStruct(info*, info*,int);                         // поиск в определённом поле