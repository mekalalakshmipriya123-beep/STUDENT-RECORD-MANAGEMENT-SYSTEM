/* stud_show.c */

#include "student.h"

void stud_show(void)
{
    ST *temp;

    if(head == NULL)
    {
        printf("\nNo Student Records Found...\n");
        return;
    }

    temp = head;

    printf("\n=====================================================\n");
    printf("%-10s %-20s %-10s\n", "Roll No", "Name", "Percentage");
    printf("=====================================================\n");

    while(temp)
    {
        printf("%-10d %-20s %-10.2f\n",
               temp->roll,
               temp->name,
               temp->per);

        temp = temp->next;
    }

    printf("=====================================================\n");
}
