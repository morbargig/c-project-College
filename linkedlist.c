#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Student_t *add_Student_to_last(Student_t *head, name name, Grade_t *grade)
{
    Student_t *pos = head;

    if (!pos)
    {
        pos = (Student_t *)malloc(sizeof(Student_t));
        pos->name = name;
        pos->grade = grade;
        pos->next = NULL;
        return pos;
    }
    else
    {
        while (pos->next)
        {
            pos = pos->next;
        }
        pos->next = (Student_t *)malloc(sizeof(Student_t));
        pos->next->name = name;
        pos->next->grade = grade;
        pos->next->next = NULL;
    }
    return head;
}

Class_t *add_Class_to_last(Class_t *head, id id)
{
    Class_t *pos = head;

    if (!pos)
    {
        pos = (Class_t *)malloc(sizeof(Class_t));
        pos->id = id;
        pos->next = NULL;
        return pos;
    }
    else
    {
        while (pos->next)
        {
            pos = pos->next;
        }
        pos->next = (Class_t *)malloc(sizeof(Class_t));
        pos->next->id = id;
        pos->next->next = NULL;
    }
    return head;
}

Grade_t *add_Grade_to_last(Grade_t *head, id id, int grade)
{
    Grade_t *pos = head;

    if (!pos)
    {
        pos = (Grade_t *)malloc(sizeof(Grade_t));
        pos->id = id;
        pos->grade = grade;
        pos->next = NULL;
        return pos;
    }
    else
    {
        while (pos->next)
        {
            pos = pos->next;
        }
        pos->next = (Grade_t *)malloc(sizeof(Grade_t));
        pos->next->id = id;
        pos->next->grade = grade;
        pos->next->next = NULL;
    }
    return head;
}
