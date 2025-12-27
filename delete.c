#include <stdio.h>
#include <string.h>
#include <strings.h> // for strcasestr
#include "header.h"

// Function prototypes
void remove_contact(book *details, int index);
void show_matches(book *details, int *match_list, int total);

// Delete a contact by Name / Mobile / Email
int delete_contact(book *details)
{
    while (1)
    {
        printf("\n********************************************************************************************************\n");
        printf("%60s\n", "DELETE CONTACT MENU");
        printf("********************************************************************************************************\n");
        printf("  1) Delete by Name\n");
        printf("  2) Delete by Mobile\n");
        printf("  3) Delete by Email\n");
        printf("  4) Exit Delete Menu\n");
        printf("--------------------------------------------------------------------------------------------------------\n");
        printf("Enter your choice: ");

        int user_choice;
        if (scanf("%d", &user_choice) != 1)
        {
            printf("⚠️  Please enter a valid choice.\n");
            while (getchar() != '\n'); // clear invalid input
            continue;
        }
        getchar(); // clear newline

        if (user_choice == 4)
            return 5;

        char input_data[100];
        int matched_indices[100];
        int match_count = 0;

        switch (user_choice)
        {
        case 1: // Delete by Name
            printf("Enter the name to delete: ");
            fgets(input_data, sizeof(input_data), stdin);
            input_data[strcspn(input_data, "\n")] = '\0';
            for (int i = 0; i < details->contact_count; i++)
            {
                if (strcasestr(details->arr[i].name, input_data))
                    matched_indices[match_count++] = i;
            }
            break;

        case 2: // Delete by Mobile
            printf("Enter the mobile number to delete: ");
            fgets(input_data, sizeof(input_data), stdin);
            input_data[strcspn(input_data, "\n")] = '\0';
            for (int i = 0; i < details->contact_count; i++)
            {
                if (strcmp(details->arr[i].mobile, input_data) == 0)
                    matched_indices[match_count++] = i;
            }
            break;

        case 3: // Delete by Email
            printf("Enter the email to delete: ");
            fgets(input_data, sizeof(input_data), stdin);
            input_data[strcspn(input_data, "\n")] = '\0';
            for (int i = 0; i < details->contact_count; i++)
            {
                if (strcmp(details->arr[i].mail, input_data) == 0)
                    matched_indices[match_count++] = i;
            }
            break;

        default:
            printf("\n❌ Invalid choice! Please try again.\n");
            continue;
        }

        if (match_count == 0)
        {
            printf("\n⚠️ No matching contact found.\n\n");
            continue;
        }

        // Show all matches
        printf("\n✅ Matching contacts found:\n");
        show_matches(details, matched_indices, match_count);

        int del_choice;
        printf("Enter the serial number of the contact to delete (or 0 to cancel): ");
        if (scanf("%d", &del_choice) != 1)
        {
            printf("❌ Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar(); // clear newline

        if (del_choice == 0)
        {
            printf("Deletion cancelled.\n");
            continue;
        }

        if (del_choice < 1 || del_choice > match_count)
        {
            printf("❌ Invalid selection.\n");
            continue;
        }

        // Delete selected contact
        int delete_index = matched_indices[del_choice - 1];
        remove_contact(details, delete_index);
        printf("\n✅ Contact deleted successfully!\n\n");
    }
    return 0;
}

// Shift contacts after deletion
void remove_contact(book *details, int index)
{
    for (int i = index; i < details->contact_count - 1; i++)
    {
        details->arr[i] = details->arr[i + 1];
    }
    details->contact_count--;
}

// Function to display only matched contacts
void show_matches(book *details, int *match_list, int total)
{
    printf("\n********************************************************************************************************\n");
    printf("S.No %-35s %-15s %-38s\n", "Name", "Mobile", "Email");
    printf("********************************************************************************************************\n");

    for (int i = 0; i < total; i++)
    {
        int pos = match_list[i];
        printf("%-4d %-35s %-15s %-38s\n",
               i + 1,
               details->arr[pos].name,
               details->arr[pos].mobile,
               details->arr[pos].mail);
    }

    printf("--------------------------------------------------------------------------------------------------------\n\n");
}
