#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

char *create_contact(book *details)
{
    if (details->contact_count >= 100) {
        printf("Address Book is full! Cannot add more contacts.\n");
        return "Full";
    }

    // --------------------------- NAME ---------------------------
    char name_str[50];
    while(1)
     {
        printf("Enter the name: ");
        fgets(name_str, sizeof(name_str), stdin);
        name_str[strcspn(name_str, "\n")] = '\0';

        int space_count = 0;
        int is_valid = 0;

        for(int i = 0; name_str[i] != '\0'; i++) {
            if(isalpha(name_str[i]))
             continue;

            else if(isspace(name_str[i])) {
                space_count++;
                if(i == 0 || name_str[i + 1] == '\0' || (name_str[i] == ' ' && name_str[i + 1] == ' ') || space_count > 2)
                {
                    is_valid = 1;
                    printf("❌ Invalid name. Please try again!\n\n");
                    break;
                }
            }
            else {
                is_valid = 1;
                printf("❌ Invalid name. Please try again!\n\n");
                break;
            }
        }

        if(is_valid == 0) 
        {
            strcpy(details->arr[details->contact_count].name, name_str);
            break;
        }
    }

    // --------------------------- MOBILE ---------------------------
    char mobile_str[15];
    while(1) 
    {
        printf("Enter the mobile number: ");
        fgets(mobile_str, sizeof(mobile_str), stdin);
        mobile_str[strcspn(mobile_str, "\n")] = '\0';

        int len = strlen(mobile_str);
        int invalid = 0;

        if(len != 10) {
            printf("⚠️ Mobile number must be 10 digits.\n\n");
            continue;
        }

        for(int i = 0; i < len; i++)
         {
            if(!isdigit(mobile_str[i])) 
            { 
                invalid = 1; 
                break;
            }
        }
        if(invalid) 
        { 
            printf("⚠️ Mobile number must contain digits only!\n\n");
             continue; 
        }

        int duplicate = 0;
        for(int i = 0; i < details->contact_count; i++)
         {
            if(strcmp(details->arr[i].mobile, mobile_str) == 0)
             {
                 duplicate = 1; 
                 break;
             }
        }
        if(duplicate)
         {
             printf("Mobile number already exists!\n\n");
              continue;
         }

        strcpy(details->arr[details->contact_count].mobile, mobile_str);
        break;
    }

    // --------------------------- EMAIL ---------------------------
    char mail_str[50];
    while(1)
     {
        printf("Enter the email ID: ");
        fgets(mail_str, sizeof(mail_str), stdin);
        mail_str[strcspn(mail_str, "\n")] = '\0';

        int len = strlen(mail_str);
        if(len < 6) 
        {
             printf("⚠️ Email must be at least 6 characters.\n\n");
              continue;
        }

        char *at_ptr = strchr(mail_str, '@');
        if(!at_ptr) 
        {
             printf("⚠️ Email must contain '@'.\n"); 
             continue;
        }

        int has_alpha_before = 0;
        for(char *p = mail_str; p < at_ptr; p++) 
        { 
            if(isalpha(*p))
             { 
                has_alpha_before = 1;
                 break;
             } 
        }
        if(!has_alpha_before) 
        { 
            printf("⚠️ Email must contain a letter before '@'.\n\n");
             continue;
        }

        char *dot_ptr = strstr(mail_str, ".com");
        if(dot_ptr == NULL || dot_ptr != mail_str + len - 4) 
        { 
            printf("⚠️ Email must end with '.com'.\n\n"); 
            continue;
        }

        int valid = 1, invalid_after = 0, has_alpha_after = 0;
        for(char *p = at_ptr + 1; p < dot_ptr; p++) 
        { 
            if(!islower(*p)) 
            { 
                invalid_after = 1; 
                break;
            } has_alpha_after = 1;
        }
        if(!has_alpha_after || invalid_after) 
        {
             printf("❌ Invalid characters after '@'.\n\n");
              continue;
        }

        int duplicate = 0;
        for(int i = 0; i < details->contact_count; i++) 
        { 
            if(strcmp(details->arr[i].mail, mail_str) == 0) 
            { 
                duplicate = 1;
                 break; 
            } 
        }
        if(duplicate)
         { 
            printf("Email already exists!\n\n");
             continue; 
        }

        strcpy(details->arr[details->contact_count].mail, mail_str);
        break;
    }

    details->contact_count++;
    return NULL;
}

