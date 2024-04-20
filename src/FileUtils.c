#include "entities/User.entity.h"
#include "./FileUtils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to search UserObjects by name from a file
void search_user_by_name(const char *filename, const char *searchName)
{
    FILE *file = fopen(filename, "r"); // Open the file in read mode
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    UserObject user;
    int found = 0;

    // Read and parse the file
    while (fscanf(file, "ID: %d\nName: %99[^\n]\nAge: %d\n\n", &user.id, user.name, &user.age) == 3)
    {
        if (strcmp(user.name, searchName) == 0)
        {
            // Matching name found, print the details
            printf("Found User:\nID: %d\nName: %s\nAge: %d\n\n", user.id, user.name, user.age);
            found = 1;
            break; // Stop searching after finding the user
        }
    }

    if (!found)
    {
        printf("No user with the name '%s' found.\n", searchName);
    }

    // Close the file
    fclose(file);
}

// Function to read UserObjects from a file
void read_users_from_file(const char *filename)
{
    FILE *file = fopen(filename, "r"); // Open the file in read mode
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    UserObject user;
    // Prepare to read the file line by line
    while (fscanf(file, "ID: %d\nName: %99[^\n]\nAge: %d\n\n", &user.id, user.name, &user.age) == 3)
    {
        // For each user object found, print out the details
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
    }

    // Close the file
    fclose(file);
}

// Function to write a UserObject to a file
void write_user_to_file(const char *filename, UserObject user)
{
    FILE *file = fopen(filename, "a"); // Open the file in append mode
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write user object to the file
    fprintf(file, "ID: %d\nName: %s\nAge: %d\n\n", user.id, user.name, user.age);

    // Close the file
    fclose(file);
}
