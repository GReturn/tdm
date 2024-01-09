#include "todome.h"

FILE* create_list(void)
{
    return fopen(FILENAME, "w");
}
FILE* get_list_editable(void)
{
    return fopen(FILENAME, "a");
}
FILE* get_list_readonly(void)
{
    return fopen(FILENAME, "r");
}
bool check_file_exist(void)
{
    printf("\nChecking if list exists...\n");

    FILE *file = fopen(FILENAME, "r");
    if(file == NULL)
    {
        printf("\nList does not exist!");
        fclose(file);
        return false;
    } 
    else 
    {
        printf("\nList exists!");
        fclose(file);
        return true;
    }
}
int get_recent_id(void)
{
    FILE *file = get_list_readonly();
    int ch;
    
    for(int i = 0; ch != '{'; i--)
    {
        fseek(file, i, SEEK_END);
        ch = fgetc(file);    
    }
    fseek(file, 0, SEEK_CUR);
    ch = getc(file);
    
    fclose(file);
    return ch;
}
int get_item_count(void)
{
    FILE *file = get_list_readonly();

    // TODO: read item count
    for(int i = 1; !feof(file); i++)
    {
        fseek(file, 0, SEEK_SET);
    }

    return;
}
void add_item(FILE *file, TodoItem item)
{
    fprintf(file, LIST_FORMAT, item.id, item.description);
    return;
}
void exit_program(void)
{
    exit(EXIT_SUCCESS);   
}