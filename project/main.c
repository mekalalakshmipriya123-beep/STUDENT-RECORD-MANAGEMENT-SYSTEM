

#include "student.h"

ST *head = NULL;

int main()
{
    char choice, exit_choice;

    /* Load records from file when program starts */
    stud_load();

    //while(1)
    //{
        printf("\t+----------------------------------+\n");
        printf("\t|*****STUDENT RECORD MANAGEMENT*****|\n");
        printf("\t|-----------------------------------|\n");
        printf("\t|A/a : Add New Record               |\n");
        printf("\t|D/d : Delete a Record              |\n");
        printf("\t|S/s : Show the List                |\n");
        printf("\t|M/m : Modify a Record              |\n");
        printf("\t|V/v : Save                         |\n");
        printf("\t|T/t : Sort the List                |\n");
        printf("\t|E/e : Exit                         |\n");
	printf("\t|-----------------------------------|\n");

       while(1)
       { 
        printf("\nEnter Your Choice : ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case 'A':
            case 'a':
                    stud_add();
                    break;

            case 'D':
	    case 'd':
                    stud_del();
                    break;

            case 'S':
            case 's':
                    stud_show();
                    break;

            case 'M':
            case 'm':
                    stud_mod();
                    break;

            case 'V':
            case 'v':
                    stud_save();
                    break;

            case 'T':
            case 't':
                    stud_sort();
                    break;

            case 'E':
            case 'e':

                printf("\nS/s : Save and Exit\n");
                printf("E/e : Exit Without Saving\n");

                printf("Enter Your Choice : ");
                scanf(" %c", &exit_choice);

                if(exit_choice=='S' || exit_choice=='s')
                {
                    stud_save();
                    printf("\nRecords Saved Successfully.\n");
                }

                printf("\nThank You...\n");
                exit(0);

            default:
                printf("\nInvalid Choice...\n");
        }
    }

    return 0;
}
