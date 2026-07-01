/* stud_save.c */

#include "student.h"

/* Save all records to file */
void stud_save(void)
{
    FILE *fp;
    ST *temp;

    if(head == NULL)
    {
        printf("\nNo Records to Save...\n");
        return;
    }

    fp = fopen("student.dat", "wb");

    if(fp == NULL)
    {
        printf("\nFile Cannot be Opened...\n");
        return;
    }

    temp = head;

    while(temp)
    {
        fwrite(temp, sizeof(ST), 1, fp);
        temp = temp->next;
    }

    fclose(fp);

    printf("\nRecords Saved Successfully...\n");
}

/* Load records from file at startup */
void stud_load(void)
{
    FILE *fp;
    ST *new, *last = NULL;

    fp = fopen("student.dat", "rb");

    if(fp == NULL)
    {
        return; // No file yet (first run)
    }

    while(1)
    {
        new = (ST *)malloc(sizeof(ST));

        if(fread(new, sizeof(ST), 1, fp) != 1)
        {
            free(new);
            break;
        }

        new->next = NULL;

        if(head == NULL)
        {
            head = new;
        }
        else
        {
            last->next = new;
        }

        last = new;
    }

    fclose(fp);
}
