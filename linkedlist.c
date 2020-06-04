#include "linkedlist.h"

void print_class(Class_t *head)
{
    while (head)
    {
        printf("%d->", head->id);
        head = head->next;
    }
    printf("NULL\n");
}

void print_students(Student_t *head)
{
    while (head)
    {
        printf("%s->", head->name);
        head = head->next;
    }
    printf("NULL\n");
}

void print_grades(Grade_t *head)
{
    while (head)
    {
        printf("id %d grade %d->", head->id, head->grade);
        head = head->next;
    }
    printf("NULL\n");
}

Student_t *add_Student_to_last(Student_t *head, name name, Grade_t *grade)
{
    Student_t *new = (Student_t *)malloc(sizeof(Student_t));
    strcpy(new->name, name);
    new->grade = grade;
    new->next = NULL;
    // printf("3");
    if (!head)
        // printf("1");
        return new;
    Student_t *pos = head;
    while (pos->next)
    {
        // printf("2");
        pos = pos->next;
    }
    pos->next = new;
    return head;
}

Class_t *add_Class_to_last(Class_t *head, _id id)
{
    Class_t *new = (Class_t *)malloc(sizeof(Class_t));
    new->id = id;
    new->next = NULL;
    new->Students = NULL;
    if (!head)
        return new;
    Class_t *pos = head;
    while (pos->next)
    {
        pos = pos->next;
    }
    pos->next = new;
    return head;
}

Grade_t *add_Grade_to_last(Grade_t *head, _id id, int grade)
{
    Grade_t *new = (Grade_t *)malloc(sizeof(Grade_t));
    new->id = id;
    new->grade = grade;
    new->next = NULL;
    if (head == NULL)
        return new;
    Grade_t *pos = head;
    while (pos->next)
    {
        pos = pos->next;
    }
    pos->next = new;
    return head;
}

Student_t *find_student_by_name(Student_t *head, name name){
	while (head && head->name != name)
		head = head->next;
	return head;
}

Class_t *find_class_by_name(Class_t *head, _id id){
	while (head && head->id != id)
		head = head->next;
	return head;
}

Grade_t *find_grade_by_name(Grade_t *head, _id id){
	while (head && head->id != id)
		head = head->next;
	return head;
}