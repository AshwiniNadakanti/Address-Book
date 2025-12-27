#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "header.h"
// ========================== SAVE CONTACTS TO CSV FILE ==========================
int save_contact(book *details)
{
    FILE *fp;

    fp = fopen("backup.csv", "w");  // Open file in write mode
    if (fp == NULL)
     return -1;      
    fprintf(fp, "#%d\n", details->contact_count); // Write total contacts at top

    for (int i = 0; i < details->contact_count; i++)  // Loop through contacts
    {
        fprintf(fp, "%s,%s,%s\n", details->arr[i].name, details->arr[i].mobile, details->arr[i].mail); // Write each contact
    }

    fclose(fp);  
    return 0;
}

int initialize(book *details)
{
    FILE *fp;

    fp = fopen("backup.csv", "r");  // Open file in read mode
    if (fp == NULL) 
    return -1;

    fscanf(fp, "#%d\n", &details->contact_count); 

    for (int i = 0; i < details->contact_count; i++)  
    {
        fscanf(fp, "%[^,],%[^,],%[^\n]\n", details->arr[i].name, details->arr[i].mobile, details->arr[i].mail); // Read CSV data
    }

    fclose(fp);  
    return 0;
}

