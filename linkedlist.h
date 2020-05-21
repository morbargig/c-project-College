
#define SIZE 20

typedef int id;
typedef char name;
typedef struct Student  {
	name name[SIZE];
    struct Grade* grade;
	struct Student* next;
}Student_t;

typedef struct  Grade{
    id id;
    int grade;
    struct Grade* next;
}Grade_t;

typedef struct  Class{
    id id;
    struct Student* Students;
}Class_t;




// Class_t* add_to_last(Class_t* head, id id);
Student_t* add_to_last(Student_t* head, name name,Grade_t* grade);
// Grade_t* add_to_last(Grade_t* head, id id,int grade);
