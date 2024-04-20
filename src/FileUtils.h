#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "entities/User.entity.h"

void search_user_by_name(const char *filename, const char *searchName);
void read_users_from_file(const char *filename);
void write_user_to_file(const char *filename, UserObject user);
#endif