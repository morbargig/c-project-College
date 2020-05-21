
#define SIZE 20

typedef int id;
typedef char* name;

 struct Student  {
	name name ;
    struct Grade* grade;
	struct Student* next;

}typedef Student_t;

 struct  Grade{
    id id;
    int grade;
    struct Grade* next;

}typedef Grade_t;

 struct  Class{
    id id;
    struct Student* Students;
    struct  Class* next;
}typedef Class_t;




Class_t* add_Class_to_last(Class_t* head, id id);
Student_t* add_Student_to_last(Student_t* head, name name,Grade_t* grade);
Grade_t* add_Grade_to_last(Grade_t* head, id id,int grade);
