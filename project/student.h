/* student.h */

#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int roll;               // Roll Number
    char name[30];          // Student Name
    float per;              // Percentage
    struct student *next;   // Pointer to next node
} ST;

/* Head pointer (defined in main.c) */
extern ST *head;

/* Function Prototypes */
void stud_add(void);
void stud_del(void);
void stud_show(void);
void stud_mod(void);
void stud_save(void);
void stud_load(void);
void stud_sort(void);

#endif
