#include "todome.h"

int main(int argc, char const *argv[])
{
    screen_welcome();
    while(1)
    {
        screen_main();
    }
    exit(EXIT_FAILURE);
    return 0;
}
