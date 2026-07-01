/* stud_add.c */

#include "student.h"

/* Find the smallest available roll number */
static int get_roll_no(void)
{
    int roll = 1;
    ST *temp;

    while(1)
    {
        int found = 0;
        temp = head;

        while(temp)
        {
            if(temp->roll == roll)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if(found == 0)
            return roll;

        roll++;
    }
}

void stud_add(void)
{
    ST *new, *temp;

    new = (ST *)malloc(sizeof(ST));

    if(new == NULL)
    {
        printf("\nMemory Allocation Failed...\n");
        return;
    }

    /* Auto Roll Number */
    new->roll = get_roll_no();

    printf("\nEnter Student Name : ");
    scanf(" %[^\n]", new->name);

    printf("Enter Percentage : ");
    scanf("%f", &new->per);

    new->next = NULL;

    /* First Node */
    if(head == NULL)
    {
        head = new;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new;
    }

    printf("\n----------------------------------\n");
    printf("Student Record Added Successfully\n");
    printf("Roll Number : %d\n", new->roll);
    printf("----------------------------------\n");
}
