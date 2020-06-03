#include "linkedlist.h"

Student_t *add_Student_to_last(Student_t *head, name name, Grade_t *grade)
{
    Student_t *new = (Student_t *)malloc(sizeof(Student_t));
    new->name = name;
    new->grade = grade;
    new->next = NULL;
    if (!head)
    {
        head->next = new;
        return head;
    }
    Student_t *pos = head;
    while (pos->next)
    {
        pos = pos->next;
    }
    head->next = new;
    return head;
}

Class_t *add_Class_to_last(Class_t *head, _id id)
{
    Class_t *new = (Class_t *)malloc(sizeof(Class_t));
    new->id = id;
    new->next = NULL;
    if (!head)
    {
        head->next = new;
        return head;
    }
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
    Grade_t *pos = head;
    Grade_t new = (Grade_t *)malloc(sizeof(Grade_t));
    new->id = id;
    new->grade = grade;
    new->next = NULL;
    if (!pos)
    {
        pos->next = new;
        return head;
    }
    while (pos->next)
    {
        pos = pos->next;
    }
    pos->next = new;
    return head;
}
