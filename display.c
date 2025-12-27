#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "header.h"

/* ==========================================================
   FUNCTION: display_contact()
   PURPOSE : Displays all saved contacts in a clean tabular format.
             Columns are widened to handle long names and emails.
   ========================================================== */
char *display_contact(book *details)
{
    // Check if the address book is empty
    if (details->contact_count == 0)
    {
        printf("\n>>>>>>>>>>>>>>>>>⚠️ No Contacts Found >>>>>>>>>>>>>>>>>\n\n");
        return NULL;
    }

    printf("=========================================================================================================\n");
    printf("%55s\n", "CONTACT DETAILS");
    printf("=========================================================================================================\n");
    printf("S.No %-35s %-15s %-38s\n", "Name", "Mobile", "Email");
    printf("---------------------------------------------------------------------------------------------------------\n");
 
    for (int i = 0; i < details->contact_count; i++)
    {
        printf("%-4d %-35s %-15s %-38s\n",i + 1,details->arr[i].name,details->arr[i].mobile,details->arr[i].mail);
    }

    printf("---------------------------------------------------------------------------------------------------------\n\n");
    return NULL; 
}

