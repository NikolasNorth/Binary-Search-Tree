//
//  main.c
//  CS2211_Assign5
//
//  Created by Nikolas North on 2018-11-21.
//  Copyright © 2018 Nikolas North. All rights reserved.
//

#include "matrix.h"

int main(int argc, const char * argv[]) {
    // create a new matrix
    Matrix matrix = matrix_construction();

    char absolute_path[100];

    printf("Enter the absolute pathname to your file: ");
    scanf("%s", absolute_path);

    // read from stdin string pairs (i.e. two strings per line)
    char input_str[100], str1[100], str2[100], *pstr;

    FILE *pfile = fopen(absolute_path, "r");
    if(pfile == 0) {
        perror("fopen");
        exit(1);
    }
    while (!feof(pfile)) {
        fgets(input_str, 100, pfile);
        pstr = strtok(input_str, " ");
        strcpy(str1, pstr);
        pstr = strtok(NULL, "\n");
        strcpy(str2, pstr);

        if (matrix_isin(matrix, str1, str2) == 0) {
            // string pair not in matrix
            matrix_set(matrix, str1, str2, 1);
        } else {
            // string pair is in matrix
            // increment value by 1
            matrix_inc(matrix, str1, str2, 1);
        }
    }
    fclose(pfile);
    printf("String 1 | String 2 | Occurrence \n");
    matrix_list(matrix);
    matrix_destruction(matrix);

    printf("\n");
    printf("Program finished. \n");
    return 0;
}
