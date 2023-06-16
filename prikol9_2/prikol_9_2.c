#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
//читаем файлы 
void peremeshka(const char *name_file_1, const char *name_file_2) {
    FILE *file1 = fopen(name_file_1, "r");
    FILE *file2 = fopen(name_file_2, "r");
    if (file1 == NULL || file2 == NULL) {
        printf("Error.\n");
        return;
    }// 2 массива для двух файлов и затем поочередно добалвяем элементы файлов, пока содержимое одного из файлов не закончится, потом просто оставшиеся элементы другого файла юзаем
    char line1[MAX];
    char line2[MAX];
    int end1 = 0, end2 = 0;
    while (!end1 || !end2) {
        if (fgets(line1, sizeof(line1), file1) != NULL && !end1) {
            printf("%s", line1);
        } else {
            end1 = 1;
            }

        if (fgets(line2, sizeof(line2), file2) != NULL && !end2) {
            printf("%s", line2);
        } else {
            end2 = 1;
            }
    }
    fclose(file1);
    fclose(file2);
}


int main() {
    char name_file_1[MAX];
    char name_file_2[MAX];
    printf("Write 1 file: ");
    scanf("%1023s", name_file_1);
    printf("Write 2 file: ");
    scanf("%1023s", name_file_2);

    peremeshka(name_file_1, name_file_2);

    return 0;
}