#include "./src/FileUtils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create an instance of UserObject and assign data to it
    UserObject user1 = {.id = 1, .name = "Alice", .age = 30};
    UserObject user2 = {.id = 2, .name = "Bob", .age = 25};

    // // Write objects to a text file
    // write_user_to_file("users.txt", user1);
    // write_user_to_file("users.txt", user2);

    read_users_from_file("users.txt");

    // search_user_by_name("users.txt", "Alice");

    // printf("User objects have been written to the file.\n");

    return 0;
}