// header.h
// Address Book Project — Header File

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Structure for single contact
struct contact
 {
    char name[50];
    char mobile[11];
    char mail[50];
};

// Structure for address book
typedef struct addressbook {
    struct contact arr[100];
    int contact_count;
} book;

// Function declarations
char *create_contact(book *details);
char *display_contact(book *details);
int search_contact(book *details);
int delete_contact(book *details);
int edit_contact(book *details); 
int save_contact(book *details);
int initialize(book* details);
#endif
