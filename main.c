#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

int main()
{
    // ----------------------- INITIALIZATION -----------------------
    book details;
    details.contact_count = 0;
    initialize(&details);

    int choice;

    // ------------------------- MAIN MENU LOOP -------------------------
    while (1)
    {
        printf("\n********************************************************************************************************\n");
        printf("%60s\n", "ADDRESS BOOK MAIN MENU");
        printf("********************************************************************************************************\n");
        printf("  1) Create Contact\n");
        printf("  2) Display Contacts\n");
        printf("  3) Search Contact\n");
        printf("  4) Delete Contact\n");
        printf("  5) Edit Contact\n");
        printf("  6) Save Contact\n");
        printf("  7) Exit\n");
        printf("-------------------------------------------------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // clear input buffer

        if(choice == 7) 
        break;

        switch (choice)
        {
            case 1:
            {
                char *str1 = create_contact(&details);
                if (str1 == NULL) 
                printf("\n>>>>✅ Contact Created Successfully >>>>\n");
                else 
                printf("\n>>>>❌ Failed to create contact >>>>\n\n");
                break;
            }
            case 2:
            {
                char *str2 = display_contact(&details);
                if (str2 == NULL) 
                printf("\n>>>>✅ Contacts Displayed Successfully >>>>\n\n");
                break;
            }
            case 3:
            {
                int str3 = search_contact(&details);
                if (str3 == 0) 
                printf("\n>>>>✅ Contact Found Successfully >>>>\n\n");
                else if(str3<0)
                printf("\n>>>>❌ Contact Not Found!>>>>\n");
                break;
            }
            case 4:
            {
                int str4 = delete_contact(&details);
                if (str4 == 0) 
                printf("\n>>>>✅ Contact Deleted Successfully >>>>\n\n");
                else if(str4<0) 
                printf("\n>>>>❌ Failed to Delete Contact.>>>>\n\n");
                break;
            }
            case 5:
            {
                int str5 = edit_contact(&details);
                if (str5 == 0) 
                printf("\n>>>>✅ Contact Edited Successfully >>>>\n\n");
                else if(str5<0) 
                printf("\n>>>>❌ Failed to Edit Contact.>>>>\n\n");
                break;
            }
            case 6:
            {
                int str6 = save_contact(&details);
                if(str6 == 0) 
                printf("\n>>>>✅ Saved Successfully >>>>\n\n");
                else if(str6<0)
                printf("\n>>>>❌ Failed to Save >>>>\n\n");
                break;
            }
            default:
                printf("\n⚠️ Invalid Choice! Please try again.\n\n");
                break;
        }
    }

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%70s\n", "😊 THANK YOU FOR USING ADDRESS BOOK");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;
}

