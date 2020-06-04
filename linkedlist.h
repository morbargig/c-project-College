
#define SIZE 20

typedef int _id;
typedef char name[SIZE];

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
// print struct
void print_class(Class_t *head);
void print_students(Student_t *head);
void print_grades(Grade_t *head);
// add item to last struct
Class_t *add_Class_to_last(Class_t *head, _id id);
Student_t *add_Student_to_last(Student_t *head, name name, Grade_t *grade);
Grade_t *add_Grade_to_last(Grade_t *head, _id id, int grade);
// find item in struct
Student_t *find_student_by_name(Student_t *head, name name);
Class_t *find_class_by_name(Class_t *head, _id id);
Grade_t *find_grade_by_name(Grade_t *head, _id id);