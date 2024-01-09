#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILENAME "mylist.txt"
#define LIST_FORMAT "{%d, %s}\n"
#define LIST_FORMAT_READ "{%d, %s}\n"
#define MAX_CHAR_TODO_ITEM_DESCRIPTION 500

// Data structure for a single todo item
typedef struct TodoItem {
    int id;
    char description[MAX_CHAR_TODO_ITEM_DESCRIPTION];
} TodoItem;

// === Functions for user interface === //

void screen_welcome(void);
void screen_main(void);
void screen_goodbye(void);

// MAIN SCREENS

void screen_add_items(void);
void screen_read_list(void);
void screen_edit_item(void);
void screen_delete_item(void);

// AUXILIARY SCREENS

void screen_create_list(void);


// Functions for core logic - CRUD

FILE* create_list(void); // adds a file; the file will be the list.
void add_item(FILE*, TodoItem);
void read_list(void);
TodoItem read_item(int id);
void edit_item(TodoItem);
void delete_item(TodoItem);
void exit_program(void);

// Functions for file management and utility
FILE* get_list_editable(void);
FILE* get_list_readonly(void);
int get_item_count(void);
int get_recent_id(void);
bool check_file_exist(void);