#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

// Function prototypes
void show_edit_results(book *details, int *match_indices, int match_count);
void modify_contact_data(book *details, int pos);

// Main edit function
int edit_contact(book *details)
{
    while (1)
    {
        printf("\n=========================================================================================================\n");
        printf("%60s\n", "EDIT CONTACT MENU");
        printf("=========================================================================================================\n");
        printf("  1) Search by Name\n");
        printf("  2) Search by Mobile\n");
        printf("  3) Search by Email\n");
        printf("  4) Exit Edit Menu\n");
        printf("=========================================================================================================\n");
        printf("Enter your choice: ");

        int user_option;
        scanf("%d", &user_option);
        while (getchar() != '\n'); // clear input buffer

        if(user_option == 4)
        return 5;

        int matches = 0;
        int matched_positions[100];

        switch(user_option)
        {
            case 1: // Search by Name
            {
                char name_input[50];
                printf("Enter name to search: ");
                fgets(name_input, sizeof(name_input), stdin);
                name_input[strcspn(name_input, "\n")] = '\0';

                for(int i = 0; i < details->contact_count; i++)
                {
                    if(strcasestr(details->arr[i].name, name_input))
                        matched_positions[matches++] = i;
                }

                if(matches == 0)
                {
                    printf("\n⚠️ No matching contact found.\n\n");
                    continue;
                }

                printf("\n✅ Matching contacts found:\n");
                show_edit_results(details, matched_positions, matches);

                int selected;
                printf("Enter the serial number to edit: ");
                scanf("%d", &selected);
                getchar();

                if(selected < 1 || selected > matches)
                {
                    printf("\n❌ Invalid selection.\n\n");
                    continue;
                }

                modify_contact_data(details, matched_positions[selected - 1]);
                break;
            }

            case 2: // Search by Mobile
            {
                char phone_input[20];
                printf("Enter mobile number to search: ");
                fgets(phone_input, sizeof(phone_input), stdin);
                phone_input[strcspn(phone_input, "\n")] = '\0';

                for(int i = 0; i < details->contact_count; i++)
                {
                    if(strcmp(details->arr[i].mobile, phone_input) == 0)
                        matched_positions[matches++] = i;
                }

                if(matches == 0)
                {
                    printf("\n⚠️ No matching contact found.\n\n");
                    continue;
                }

                printf("\n✅ Matching contacts found:\n");
                show_edit_results(details, matched_positions, matches);

                int selected;
                printf("Enter the serial number to edit: ");
                scanf("%d", &selected);
                getchar();

                if(selected < 1 || selected > matches)
                {
                    printf("\n❌ Invalid selection.\n\n");
                    continue;
                }

                modify_contact_data(details, matched_positions[selected - 1]);
                break;
            }

            case 3: // Search by Email
            {
                char mail_input[50];
                printf("Enter email ID to search: ");
                fgets(mail_input, sizeof(mail_input), stdin);
                mail_input[strcspn(mail_input, "\n")] = '\0';

                for(int i = 0; i < details->contact_count; i++)
                {
                    if(strcmp(details->arr[i].mail, mail_input) == 0)
                        matched_positions[matches++] = i;
                }

                if(matches == 0)
                {
                    printf("\n⚠️ No matching contact found.\n\n");
                    continue;
                }

                printf("\n✅ Matching contacts found:\n");
                show_edit_results(details, matched_positions, matches);

                int selected;
                printf("Enter the serial number to edit: ");
                scanf("%d", &selected);
                getchar();

                if(selected < 1 || selected > matches)
                {
                    printf("\n❌ Invalid selection.\n\n");
                    continue;
                }

                modify_contact_data(details, matched_positions[selected - 1]);
                break;
            }

            default:
                printf("\n❌ Invalid input, please try again.\n\n");
        }
    }
}

// Modify selected contact fields
void modify_contact_data(book *details, int pos)
{
    while(1)
    {
        printf("\nSelect field to modify:\n");
        printf("  1) Name\n");
        printf("  2) Mobile\n");
        printf("  3) Email\n");
        printf("  4) Exit editing\n");
        printf("Enter your choice: ");

        int option;
        scanf("%d", &option);
        getchar();

        if(option == 4)
        {
            printf("\nExiting edit menu.\n");
            break;
        }

        if(option == 1) // Edit Name
        {
            char new_name[50];
            while(1)
            {
                printf("Enter new name: ");
                fgets(new_name, sizeof(new_name), stdin);
                new_name[strcspn(new_name, "\n")] = '\0';

                int valid = 1, space_count = 0;
                if(strlen(new_name) == 0) 
                { 
                    printf("⚠️ Name cannot be empty.\n\n"); 
                    continue; 
                }

                for(int i = 0; new_name[i] != '\0'; i++)
                {
                    if(isalpha(new_name[i])) 
                    continue;
                    else if(isspace(new_name[i]))
                    space_count++;
                    else 
                    {
                         valid = 0;
                        break; 
                    }
                }

                if(valid && space_count <= 2)
                {
                    strcpy(details->arr[pos].name, new_name);
                    printf("\n✅ Name updated successfully!\n\n");
                    break;
                }
                else printf("❌ Invalid name. Try again.\n\n");
            }
        }

        else if(option == 2) // Edit Mobile
        {
            char new_mobile[20];
            while(1)
            {
                printf("Enter new mobile number: ");
                fgets(new_mobile, sizeof(new_mobile), stdin);
                new_mobile[strcspn(new_mobile, "\n")] = '\0';

                int len = strlen(new_mobile), invalid = 0;
                if(len != 10)
                 {
                    printf("⚠️ Mobile number must have exactly 10 digits.\n\n"); 
                    continue; 
                 }
                for(int i = 0; i < len; i++) 
                if(!isdigit(new_mobile[i]))
                invalid = 1;

                if(invalid)
                { 
                    printf("⚠️ Mobile number should contain digits only.\n\n"); 
                    continue; 
                }

                int duplicate = 0;
                for(int i = 0; i < details->contact_count; i++)
                {
                    if(i != pos && strcmp(details->arr[i].mobile, new_mobile) == 0) duplicate = 1;
                }

                if(duplicate) 
                { 
                    printf("This mobile number already exists.\n\n"); 
                    continue; 
                }

                strcpy(details->arr[pos].mobile, new_mobile);
                printf("\n✅ Mobile number updated successfully!\n\n");
                break;
            }
        }

        else if(option == 3) // Edit Email
        {
            char new_email[50];
            while(1)
            {
                printf("Enter new email ID: ");
                fgets(new_email, sizeof(new_email), stdin);
                new_email[strcspn(new_email, "\n")] = '\0';

                int len = strlen(new_email);
                if(len < 6) 
                { 
                    printf("⚠️ Email too short. Must be at least 6 characters.\n\n"); 
                    continue; 
                }

                char *at_ptr = strchr(new_email, '@');
                if(!at_ptr) 
                { 
                    printf("❌ Invalid email: missing '@'.\n");
                    continue; 
                }

                int has_alpha = 0;
                for(char *p = new_email; p < at_ptr; p++) if(isalpha(*p)) 
                { 
                    has_alpha = 1; 
                    break; 
                }
                if(!has_alpha) 
                { 
                    printf("⚠️ Email must have at least one letter before '@'.\n\n"); 
                    continue; 
                }

                char *dot_ptr = strstr(new_email, ".com");
                if(!dot_ptr || dot_ptr != new_email + len - 4) 
                { 
                    printf("⚠️ Email must end with '.com'.\n\n"); 
                    continue; 
                }

                int valid = 1;
                for(int i = 0; i < len; i++)
                {
                    if(!(islower(new_email[i]) || isdigit(new_email[i]) || new_email[i] == '.' || new_email[i] == '@'))
                        valid = 0;
                }
                if(!valid) 
                { 
                    printf("❌ Invalid email format. Try again.\n\n"); 
                    continue; 
                }

                int duplicate = 0;
                for(int i = 0; i < details->contact_count; i++)
                {
                    if(i != pos && strcmp(details->arr[i].mail, new_email) == 0) duplicate = 1;
                }
                if(duplicate) 
                { 
                    printf("Email already exists.\n\n"); 
                    continue; 
                }

                strcpy(details->arr[pos].mail, new_email);
                printf("\n✅ Email updated successfully!\n\n");
                break;
            }
        }

        else printf("❌ Invalid input, please try again.\n\n");
    }
}
// ========================== DISPLAY SEARCH RESULTS ==========================
void show_edit_results(book *details, int *match_indices, int match_count)
{
    // Header format for display
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("S.No %-35s %-15s %-38s\n", "Name", "Mobile", "Email");
    printf("---------------------------------------------------------------------------------------------------------\n");

    // Loop through matched contacts and display details
    for (int i = 0; i < match_count; i++)
    {
        int idx = match_indices[i];
        printf("%-4d %-35s %-15s %-38s\n",i + 1,details->arr[idx].name,details->arr[idx].mobile,details->arr[idx].mail);
    }
    printf("---------------------------------------------------------------------------------------------------------\n");
}