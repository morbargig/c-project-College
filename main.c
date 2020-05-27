#include <stdio.h>
#include <stdlib.h>
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

_menue menuArray[] = {
    {"chose action :", NULL},
    {"1) wirteFile", wirteFile},
    {"2) deleteById", deleteById},
    {"3) printFile", printFile},
    {"-1) exit", NULL},
    {NULL, NULL}};

void main()
{
    Class_t cls = {1,NULL,NULL};
    // Class_t* p ;
    // p*=cls;
    // // menu();
    // // menue();
    // _id id = 1000;
    // Class_t *add_Class_to_last(Class_t p, _id id);
    fuckU();

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
        if ( res > 0 && res < 3)
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
