union names {
    char* disease;          // �������
    char* doctor;           // ��� �������
};

struct info {
    char* nameKid;          // ��� ������
    char* numberHospital;   // ����� ��������
    char* addressHospital;  // ����� ��������
    char* surnameDoctor;    // ������� �������
    names information[2];   // ������ �����������
};

const struct headlines {    // ��������� ��� show
    const char firstHeadline[8] = "Disease";
    const char secondHeadline[7] = "Doctor";
    const char thirdHeadline[18] = "Surname of doctor";
    const char fourthHeadline[12] = "Name of kid";
    const char fifthHeadline[19] = "Number of hospital";
    const char sixthHeadline[20] = "Address of hospital";

};

char* menu(int*);                                               // ������������� ����
info* universalFinder(info*, info*, int, char*, int*, int);     // �������, ������� ������� ���������� �� ��������� ���� ������������� � ���������� ��� ���������� � advancedStruct 
void show(info*, int);                                          // ����� ������ �� �����
info* sortForNames(info*, int);                                 // ���������� ��� ���� names ��������� info �� ��������
info* enterInformation(info*,int);                              // ���� ���� ������ � ���������
info* reallocStruct(info*, int);                                // ������������� ������ � ���������
info* finder(info*, info*, int, char*, int*);                   // ����� �� ������� � ����
info* showNewStruct(info*, char*, int, int*);                   // ����� �� ������� ����� � ����� �� �� �����
info* advancedStruct(info*, info*,int);                         // ����� � ����������� ����