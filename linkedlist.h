
#define SIZE 20

typedef int _id;
typedef char *name;

struct Student
{
    name name;
    struct Grade *grade;
    struct Student *next;

} typedef Student_t;

struct Grade
{
    _id id;
    int grade;
    struct Grade *next;

} typedef Grade_t;

struct Class
{
    _id id;
    struct Student *Students;
    struct Class *next;
} typedef Class_t;

struct Person
{
    char name[SIZE];
    long id;
    float age;
} typedef person_t;

struct menue
{
    char *description;
    void (*pfunch)(person_t *);
} typedef _menue;


Class_t *add_Class_to_last(Class_t *head, _id id);
Student_t *add_Student_to_last(Student_t *head, name name, Grade_t *grade);
Grade_t *add_Grade_to_last(Grade_t *head, _id id, int grade);
