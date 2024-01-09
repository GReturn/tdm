#include "todome.h"

void screen_welcome(void)
{
    printf("Welcome to ToDoMe!\n");
}

void screen_main(void)
{
    printf("\n=========== TODOME MAIN MENU ===========\n");
    if(!check_file_exist())
    {
        screen_create_list();
    }

    int choice;
    printf("\n[1] Add Items\n[2] Read List\n[3] Edit List\n[4] Delete Item\n[5] Exit Program.");
    printf("\nSelect choice: ");
    scanf("%d", &choice);

retry:
    switch (choice)
    {
        case 1:
            screen_add_items();
            break;
        case 2:
            screen_read_list();
            break;
        case 3:
            // screen_edit_item();
            break;
        case 4:
            // screen_delete_item();
            break;
        case 5:
            screen_goodbye();
        default:
            printf("Invalid input. Please try again.");
            goto retry;
            break;
    }
}
void screen_add_items(void)
{
    int numberOfItems;
    printf("\nHow many items? ");
    scanf("%d", &numberOfItems);

    if(!check_file_exist())
    {
        FILE *file = create_list();

        for(int i = 0; i < numberOfItems; i++)
        {
            TodoItem item = { .id = i };
            printf("\nType item %d description: ", i+1);
            scanf(" %[^\n]", item.description);
            add_item(file, item);
        }
        fclose(file);
    }
    else
    {
        FILE *file = get_list_editable();

        int recentID = get_recent_id();
        for(int i = recentID + 1; i <= numberOfItems; i++)
        {
            TodoItem item = { .id = i };
            printf("\nType item %d description: ", i+1);
            scanf(" %[^\n]", item.description);
            add_item(file, item);
        }
        fclose(file);
    }

    printf("\nItems added! The file name is \"%s\"\n", FILENAME);
    return;
}
void screen_read_list(void)
{
    FILE *file = get_list_readonly();

    for(int i = 0; !feof(file); i++)
    {
        TodoItem item;
        fscanf(file, LIST_FORMAT_READ, &item.id, item.description);
        printf("Item ID#%d: %s", item.id, item.description);
    }
    fclose(file);
}

void screen_create_list(void)
{
    char choice;
    printf("\nIt seems that you do not have a list file! Create list? [y/n] ");
    scanf(" %c", &choice);

    if(choice == 'y')
    {
        printf("Creating list...\n");
        screen_add_items();
        return;
    }
    else
    {
        printf("[ERROR] List not created...");
        return;
    }
}
void screen_goodbye(void)
{
    printf("Thank you for using ToDoMe! Goodbye.");
    exit_program();
}