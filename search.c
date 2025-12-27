#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

// Function prototype for displaying search results
void show_results(book *data, int *index_list, int match_count);

int search_contact(book *data)
{
    while (1)
    {
        printf("\n---------------------------------------------------------------------------------------------------------\n");
        printf("%60s\n", "SEARCH CONTACT MENU");
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("  1) Search by Name\n");
        printf("  2) Search by Mobile\n");
        printf("  3) Search by Email\n");
        printf("  4) Exit Search\n");
        printf("_________________________________________________________________________________________________________\n");
        printf("Enter your option: ");

        int opt;
        scanf("%d", &opt);
        while (getchar() != '\n'); // clear input buffer

        int matched_indices[100]; // to store matched contact indices
        int total_found = 0;

        if(opt == 4)
         return 5; // Exit search

        switch(opt)
        {
            case 1: // Search by Name
            {
                char search_name[50];
                printf("Enter the name to search: ");
                fgets(search_name, sizeof(search_name), stdin);
                search_name[strcspn(search_name, "\n")] = '\0';
                printf("\n");

                if(strlen(search_name) == 0) 
                {
                     printf("⚠️ Please enter a valid name.\n\n"); 
                     continue; 
                }

                for(int i = 0; i < data->contact_count; i++)
                {
                    if(strcasestr(data->arr[i].name, search_name))
                        matched_indices[total_found++] = i;
                }

                if(total_found > 0) show_results(data, matched_indices, total_found);
                else printf("\n⚠️ No matching contact found.\n\n");
                break;
            }

            case 2: // Search by Mobile
            {
                char search_mobile[15];
                printf("Enter the mobile number: ");
                fgets(search_mobile, sizeof(search_mobile), stdin);
                search_mobile[strcspn(search_mobile, "\n")] = '\0';

                if(strlen(search_mobile) == 0)
                 {
                     printf("⚠️ Please enter a valid mobile number.\n\n"); 
                     continue; 
                }

                for(int i = 0; i < data->contact_count; i++)
                {
                    if(strcmp(data->arr[i].mobile, search_mobile) == 0)
                        matched_indices[total_found++] = i;
                }

                if(total_found > 0)
                show_results(data, matched_indices, total_found);
                else
                printf("\n⚠️ No matching contact found.\n\n");
                break;
            }

            case 3: // Search by Email
            {
                char search_email[50];
                printf("Enter the email ID: ");
                fgets(search_email, sizeof(search_email), stdin);
                search_email[strcspn(search_email, "\n")] = '\0';

                if(strlen(search_email) == 0)
                 {
                     printf("⚠️ Please enter a valid email.\n\n");
                      continue; 
                }

                for(int i = 0; i < data->contact_count; i++)
                {
                    if(strcmp(data->arr[i].mail, search_email) == 0)
                        matched_indices[total_found++] = i;
                }

                if(total_found > 0) 
                show_results(data, matched_indices, total_found);
                else printf("\n⚠️ No matching contact found.\n\n");
                break;
            }

            default:
                printf("\n❌ Invalid option. Please try again.\n\n");
                break;
        }
    }
}
//////////////////////////////////// Display Function ////////////////////////////////////

void show_results(book *data, int *index_list, int match_count)
{
    // ===== Print Table Header =====
    for (int i = 0; i < 105; i++) 
    printf("*");   // Top border line
    printf("\n%55s\n", "SEARCH RESULTS");         // Title centered
    for (int i = 0; i < 105; i++)
    printf("*");   // Bottom border line
    printf("\n");

    // ===== Print Column Headings =====
   printf("%-4s %-35s %-14s %-35s\n", "S.No", "Name", "Mobile", "Email");

    // Print separator line
    for (int i = 0; i < 105; i++) 
    printf("-");
    printf("\n");

    // ===== Loop through each found contact and display details =====
    for (int j = 0; j < match_count; j++)
    {
        int idx = index_list[j]; // Get the index of the found contact

        // Print contact details in formatted columns
        printf("%-4d %-35s %-14s %-35s\n",j + 1,data->arr[idx].name,data->arr[idx].mobile,data->arr[idx].mail);           
    }

    // ===== Print Footer Line =====
    for (int i = 0; i < 105; i++)
    printf("-");
    printf("\n\n");
}
