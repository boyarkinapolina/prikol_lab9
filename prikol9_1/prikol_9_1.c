#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
// читаем файл 
void tail(const char *name_file, int n) {
    FILE *file = fopen(name_file, "r");
    if (file == NULL) {
        printf("Error.\n");
        return;
    }
    // вводим массив, в котором будут хранится последние строки, заполнив его null
    char **lines = (char **)malloc(n * sizeof(char *));
    int count = 0;  
    int i;
    for (i = 0; i < n; i++) {
        lines[i] = NULL;
    }
    char m[MAX];
    while (fgets(m, sizeof(m), file) != NULL) {
        if (lines[count % n] != NULL) {
            free(lines[count % n]);
        }
        lines[count % n] = strdup(m); 
        count++;
    }
    //вывод
    fclose(file);
    int start; 
    if (count > n){
        start = count % n; 
    } else{
        start = 0;
    }
    for (i = 0; i < n; i++) {
        if (lines[(start + i) % n] != NULL) {
            printf("%s", lines[(start + i) % n]);
            free(lines[(start + i) % n]);
        }
    }
    free(lines);
}


int main() {
    char name_file[100];
    int n;  
    printf("Write name file: ");
    scanf("%99s", name_file);
    printf("Write number strings: ");
    scanf("%d", &n);

    tail(name_file, n);

    return 0;
}