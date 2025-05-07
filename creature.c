/**********
 * creature
 *
 * The creature can do these things:
 *     - Read/write health from a file
 *     - Output health to console
 *
 */
#include "stdio.h"

void displayWelcomeMessage() {
    printf("Hello! I am your pet creature.\n"
           "What would you like to do with me?\n\n"
           "1. Add health\n"
           "2. Reduce health\n"
           "3. View health\n\n");
}

int main() {


    displayWelcomeMessage();

    int userResponse = 0;
    int quit = 0; // 0 if you don't want to quit, 1 if you do
    int creature_health = 0;

    while (quit == 0) {
        printf("> ");
        scanf("%d", &userResponse);

        switch(userResponse) {
            case 1:
                printf("Health added!\n");
                break;
            case 2:
                printf("Health reduced!\n");
                break;
            case 3:
                printf("Heath is: %d\n", creature_health);
                break;
            default:
                printf("Command not recognized. Exiting.\n");
                quit = 1;
                break;
        }
    }

    return 0;
}
