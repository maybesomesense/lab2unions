struct saveInfo {
    char* disease2;
    char* doctor2;
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

char* enterStr(char*);
void show(info*, saveInfo*, int);
info* giveMemory(int);
saveInfo* giveMemoryInfo(int);
int str_cmp(const char*, const char*);
info* sortForNames(info*, int);
void enterInformation(info*, saveInfo*,int);
int strLen(const char*);
info* reallocStruct(info*, int);
info* showNewStruct(info*, saveInfo*, char*, int);