#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

void createFile();
void displayContents();
void search();
void append();
void delete ();

enum
{
    MAXS = 30,
    MAXN = 20,
    MAXC = 1024
};

FILE *fptr;

struct Student
{
    char firstName[MAXN];
    int id;
    char lastName[MAXN];
    char email[MAXN];
    char course[MAXN];
    int grade;
};

int main()
{
    // variable for reposnse for the main menu
    int response;
    // main screen
    printf("            M A I N  M E N U            \n");
    printf("1. ");
    printf("Create the binary file\n");
    printf("2. ");
    printf("Display the contents of the file\n");
    printf("3. ");
    printf("Seek a specific record\n");
    printf("4. ");
    printf("Update the contents of a record\n");
    printf("5. ");
    printf("Delete a record for the specific name\n");
    printf("6. ");
    printf("Exit\n");
    printf("\n");
    printf("      Please enter your choice.....\n");
    scanf("%d", &response);

    while (response != 6)
    {
        if (response == 1)
        {
            // go to function createFile
            createFile();
        }
        else if (response == 2)
        {
            // go to function display contents of file
            displayContents();
        }
        else if (response == 3)
        {
            // go to function search
            search();
        }
        else if (response == 5)
        {
            // go to function append
            printf("You are going to function delete");
        }
        else
        {
            printf("Your entry was not valid.");
        }
    }
    printf("Thank-you. Closing.");

    return 0;
}

void createFile()
{
    size_t n = 0;                                       /* counter */
    char buf[MAXC];                                     /* array to hold each line from file (stdin here) */
    struct Student Students[MAXS] = {{.lastName = ""}}; /* array of struct */
    char responseStudent;
    responseStudent = ' ';

    // Create student file to store Struct arrays for each
    // Open file
    if ((fptr = fopen("student1.txt", "ab")) == NULL)
    {
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    printf("\nWould you enter a student? ('Y' for yes, 'N' for no)\n");
    scanf("%s", &responseStudent);
    responseStudent = toupper(responseStudent); // change to upper case incase the user puts lowercase
    while (responseStudent == 'Y')
    {
        struct Student tmp; /* temporary struct */
        int i = 0;          /* general loop counter to use */
        size_t len;         /* length for string length */

        printf("Enter lasttname: "); /* prompt for name */
        scanf("%s", tmp.lastName);   /* copy buf to tmp.name */

        printf("Enter firstname: ", stdout); /* prompt for name */
        scanf("%s", tmp.firstName);          /* copy buf to tmp.name */

        printf("Enter id: "); /* prompt id */
        scanf("%d", &tmp.id);

        printf("Enter email: "); /* prompt for name */
        scanf("%s", tmp.email);

        printf("Enter course: "); /* prompt for name */
        scanf("%s", tmp.course);  /* copy buf to tmp.name */

        printf("Enter grade: "); /* prompt id */
        scanf("%d", &tmp.grade);

        fwrite(&tmp, sizeof(struct Student), 1, fptr);
        //  when student file is created print confirmation
        printf("Created file.\n");
        Students[n++] = tmp; /* add tmp to Students array */

        printf("\nWould you enter a student? ('Y' for yes, 'N' for no)\n");
        scanf("%s", &responseStudent);
        responseStudent = toupper(responseStudent); // change to upper case incase the user puts lowercase
    }

    fputs("\nstored values", stdout); /* output stored values */
    for (size_t i = 0; i < n; i++)
        printf("\nid: %d\t  firstname: %s\t  lastname: %s\t  course: %s\t  email: %s\t grade: %d",
               Students[i].id, Students[i].firstName, Students[i].lastName,
               Students[i].course, Students[i].email, Students[i].grade);

    fclose(fptr);
    printf("\nFile Closed.\n");

    main();
}

void displayContents()
{

    int c;
    struct Student Students;
    // Read File
    if ((fptr = fopen("student1.txt", "rb")) == NULL)
    {
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    /*
        // print my one array
        while (1)
        {
            if (feof(fptr))
            {
                break;
            }
            for (size_t i = 0; i < n; i++)
                printf("\nid: %d\t  firstname: %s\t  lastname: %s\t  course: %s\t  email: %s\t grade: %d",
                       Students[i].id, Students[i].firstName, Students[i].lastName,
                       Students[i].course, Students[i].email, Students[i].grade);
        }*/

    main();
}

void search()
{
}
void append()
{
}
void delete ()
{
}
