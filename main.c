#include "linkedlist.c"
#define SIZE 20

struct Person
{
    char name[SIZE];
    long id;
    float age;
} typedef person_t;

void readFile(person_t **p);
void printFile(person_t *p);
void wirteFile(person_t *p);
int getFileSize();
void deleteById(person_t *p);
void menu();

void main()
{
    menu();
}

void menu(){
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
    // size=1;
    // printf("%d", size);
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
