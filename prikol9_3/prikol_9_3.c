#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void str_number(int num_of_str, const char *line) {
    printf("%d: %s", num_of_str, line);
}

void page_number(int num_of_page) {
    printf(" - Page %d -\n", num_of_page);
}

void work(const char *name_file, int str_on_page, int max_length) {
    FILE *file = fopen(name_file, "r");
    if (file == NULL) {
        printf("Error.\n");
        return;
    }
    char line[MAX];
    int num_of_str = 0, line_count = 0, curr_page = 1;
    while (fgets(line, sizeof(line), file) != NULL) {
        line_count++;
        num_of_str = (line_count - 1) % str_on_page + 1;
        str_number(num_of_str, line);
        if (num_of_str == str_on_page) {
            page_number(curr_page);
            curr_page++;
        }
    }
    fclose(file);
}


int main() {
    int str_on_page, max_length;
    char name_file[MAX];
    printf("Write name of file: ");
    scanf("%1023s", name_file);    
    printf("Write number of string: ");
    scanf("%d", &str_on_page);
    printf("Write max length: ");
    scanf("%d", &max_length);


    work(name_file, str_on_page, max_length);

    return 0;
}