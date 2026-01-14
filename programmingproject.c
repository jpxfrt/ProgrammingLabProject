//Tiffany Njonjo - SCS3/150340/2025


    
#include <stdio.h>

void savePatientData();
void viewPatientData();

void savePatientData()
{
    char name[50];
    int age;
    char specialCondition[100];

    FILE* fptr;
    fptr = fopen("PatientData.txt", "a");

     if (fptr == NULL)
    {
        printf("Cannot Create File.");
        return;
    }

    printf("\nEnter patient's name: ");
    getchar();
    fgets(name, sizeof(name), stdin);

    printf("Enter patient's age: ");
    scanf("%d", &age);

    printf("Enter patient's special condition, if any:");
    getchar();
    fgets(specialCondition, sizeof(specialCondition), stdin);



     fprintf(fptr, "-----PATIENT'S DETAILS-----");
     fprintf(fptr, "\nName: %s", name);
     fprintf(fptr, "Age: %d", age);
     fprintf(fptr, "\nSpecial Condition: %s", specialCondition);



    fclose(fptr);
}

void viewPatientData()
{
    char name[50];



    FILE* fptr;
    fptr = fopen("PatientData.txt", "r");

    printf("\nEnter the patient's name to view their details: ");
    getchar();
    fgets(name, sizeof(name), stdin);

    char str[1000];

    if (fptr != NULL)
    {
         while (fgets(str, 100, fptr))
       {
        printf("%s", str);
       }
    }
    else
    {
        printf("Cannot Open File.");
    }

   fclose(fptr);
}

int main()
{
    int choice, symptoms;

    printf("-----General symptoms-----\n");
    printf("\n1. Headache, Coughing, Sneezing, Fever.");
    printf("\n2. Fatigue, Joint Pain, Feeling Cold, Fever.");
    printf("\n3. Stomachache, Vomiting, Nausea, Headache.");
    printf("\n4. Other Symptoms.\n");

    printf("\nEnter a number depending on your symptoms: ", symptoms);
    scanf("%d", &symptoms);

    switch(symptoms)
    {
         case 1:
       printf("See Dr Muendo.");
       break;

         case 2:
       printf("Please See Dr Chege.");
       break;

         case 3:
       printf("Please See Dr Njonjo.");
       break;

         case 4:
       printf("Please See Any Available General Doctor.");
       break;

         default:
       printf("Invalid Choice. Please Try Again.");

    }

    do
    {
        printf("\n\n-----HOSPITAL MENU-----");
        printf("\n1. Save Patient's Data.");
        printf("\n2. View Patient's Data.");
        printf("\n3. Exit.");

        printf("\nEnter your choice: ", choice);
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            savePatientData();
            break;

        case 2:
            viewPatientData();
            break;

        case 3:
            printf("Exiting Program.");
            break;

        default:
        printf("Invalid Choice. Please Try Again.");
        }
    } while (choice != 3);


    return 0;
}
