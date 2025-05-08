/**********
 * creature
 *
 * The creature can do these things:
 *     - Read/write health from a file
 *     - Output health to console
 *
 */
#include "stdio.h"
#include "string.h"

void displayWelcomeMessage() {
    printf("Hello! I am your pet creature.\n"
           "What would you like to do with me?\n\n"
           "1. Add health\n"
           "2. Reduce health\n"
           "3. View health\n\n");
}

int getCurrentHealth(FILE *healthFile) {
    fseek(healthFile, 0, SEEK_SET);
    int currentHealth = 0;
    fread(&currentHealth, sizeof(currentHealth), 1, healthFile);

    return currentHealth;
}

void addHealth(FILE *healthFile, const int currentHealth) {
    fseek(healthFile, 0, SEEK_SET);
    int newHealth = currentHealth + 2;
    fwrite(&newHealth, sizeof(newHealth), 1, healthFile);

    return;
}

int main() {
    int userResponse = 0;
    int quit = 0; // 0 if you don't want to quit, 1 if you do
    int creatureHealth = 0;

    // get file descriptor
    const char *filename = "health.txt";
    FILE *healthFile = fopen(filename, "rb+");

    if (healthFile == NULL) {
        printf("Error opening health file");
        return 1;
    }

    displayWelcomeMessage();

    while (quit == 0) {
        creatureHealth = getCurrentHealth(healthFile);
        printf("> ");
        scanf("%d",
              &userResponse); // TODO: this breaks if you use a character lol

        switch (userResponse) {
        case 1:
            addHealth(healthFile, creatureHealth);
            printf("Health added!\n");
            break;
        case 2:
            printf("Health reduced!\n");
            break;
        case 3:
            printf("Current creature health: %d\n", creatureHealth);
            break;
        default:
            printf("Command not recognized. Exiting.\n");
            quit = 1;
            break;
        }
    }

    fclose(healthFile);

    return 0;
}
