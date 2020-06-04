#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.c"

void readFile(person_t **p);
void printFile(person_t *p);
void wirteFile(person_t *p);
int getFileSize();
void deleteById(person_t *p);
void menu();
void menue();
void static printMenue();
void exitProgram(person_t *p);
Class_t *createClass();
int classNum(Class_t *head);
void fillClasswithStudents(Class_t *head);

_menue menuArray[] = {
    {"chose action :", NULL},
    {"1) wirteFile", wirteFile},
    {"2) deleteById", deleteById},
    {"3) printFile", printFile},
    {"-1) exit", NULL},
    {NULL, NULL}};

void main()
{
    // menu();
    menue();
    // Class_t *cls = createClass();
    // print_class(cls);
    // printf("%d\n", classNum(cls));
    // fillClasswithStudents(cls);
}

void fillClasswithStudents(Class_t *head)
{
    Student_t *stu = head->Students;
    char name[SIZE];
    while (1)
    {
        printf("what is the student first name\ne to exit\n");
        scanf("%s", &name);
        if (strcmp(name, "e") == 0)
            break;
        // prev = stu;
        stu = add_Student_to_last(stu, name, NULL);
        // printf("%s\n",prev->name);
    }
}

int classNum(Class_t *head)
{
    int length = 1;
    while (head = head->next)
    {
        length += 1;
    }
    return length;
}

Class_t *createClass()
{
    Class_t *cls = NULL;
    printf("what is the number of classs?");
    int classsNum;
    scanf("%d", &classsNum);
    for (int i = 1; i <= classsNum; i++)
    {
        cls = add_Class_to_last(cls, i);
    }
    return cls;
}

void static printMenue()
{
    _menue *pMenue = menuArray;
    while (pMenue->description)
    {
        printf("%s\n", pMenue->description);
        pMenue++;
    }
}

void menue()
{
    _menue *pMenue = menuArray;
    person_t *p;
    int res = 0;
    while (1)
    {
        printMenue();
        scanf("%d", &res);
        if (res > 0 && res <= 3)
        {
            (pMenue + res)->pfunch(p);
            res = 0;
            continue;
        }
        printf("end menue");
        break;
    }
}

void menu()
{
    person_t *p;
    int action;
    while (1)
    {
        printf("chose action :\n1) wirteFile\n2) deleteById\n3) printFile\n-1) exit\n");
        scanf("%d", &action);
        switch (action)
        {
        case 1:
            wirteFile(p);
            break;
        case 2:
            deleteById(p);
            break;
        case 3:
            printFile(p);
            break;
        case -1:
            printf("end program");
            return;
            break;
        default:
            printf("end program");
            return;
            break;
        }
    }
}

void deleteById(person_t *p)
{
    long id;
    printf("give me an id");
    scanf("%li", &id);
    readFile(&p);
    FILE *f;
    int size = getFileSize();
    size -= 1;
    printf("%d", size);
    f = fopen("persons.bin", "wb");
    fwrite(&size, sizeof(int), 1, f);
    for (int i = 0; i < size; i++)
    {
        printf("%d", i);
        if ((p + i)->id == id)
        {
            continue;
        }
        else
        {
            fwrite(p + i, sizeof(person_t), 1, f);
        }
    }
    fclose(f);
}

int getFileSize()
{
    FILE *f;
    int size;
    f = fopen("persons.bin", "rb");
    fread(&size, sizeof(int), 1, f);
    fclose(f);
    return size;
}

void wirteFile(person_t *p)
{
    readFile(&p);
    person_t newP = {"mor bargig", 315999508, 22.50};
    FILE *f;
    int size = getFileSize();
    f = fopen("persons.bin", "wb");
    size += 1;
    fwrite(&size, sizeof(int), 1, f);
    for (int i = 0; i < size - 1; i++)
    {
        fwrite(p + i, sizeof(person_t), 1, f);
    }
    fwrite(&newP, sizeof(person_t), 1, f);
    fclose(f);
}

void printFile(person_t *p)
{
    readFile(&p);
    int size = getFileSize();
    for (int i = 0; i < size; i++)
    {
        printf("p%d: name: %s\t id: %ld\t age: %.2f\n", i + 1, (p + i)->name, (p + i)->id, (p + i)->age);
    }
}

void readFile(person_t **p)
{
    FILE *f;
    int size;
    f = fopen("persons.bin", "rb");
    fread(&size, sizeof(int), 1, f);
    *p = (person_t *)malloc(sizeof(person_t) * size);
    for (int i = 0; i < size; i++)
    {
        fread(*p + i, sizeof(person_t), 1, f);
    }
    fclose(f);
}
