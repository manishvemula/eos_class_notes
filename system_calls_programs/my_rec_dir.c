// Input dir path from command line and display dir contents. terminal> ./assign01.out /home
//
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

void recursive_dir_list(const char *dir_name) {
    DIR *dp;
    struct dirent *ent;
    char path[1024];

    dp = opendir(dir_name);
    if (dp == NULL) {
        perror("opendir failed");
        exit(1);
    }

    while ((ent = readdir(dp)) != NULL) {
        // Skip the "." and ".." entries
       // if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) continue;

        // Form the full path
        //snprintf(path, sizeof(path), "%s/%s", dir_name, ent->d_name);

        // Check the type of the directory entry
        if (ent->d_type == DT_DIR) {
            printf("Directory: %s\n", path);
            recursive_dir_list(path);  // Recursive call
        } else if (ent->d_type == DT_REG) {
            printf("File: %s\n", path);
        }
    }

    if (closedir(dp) != 0) {
        perror("closedir failed");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory path>\n", argv[0]);
        exit(1);
    }

    recursive_dir_list(argv[1]);

    return 0;
}

