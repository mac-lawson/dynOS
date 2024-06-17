#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rows;
    int cols;
    double **data;
    char **row_labels;
    char **col_labels;
} DataFrame;

DataFrame* create_dataframe(int rows, int cols, char **row_labels, char **col_labels, double **data) {
    DataFrame *df = (DataFrame*) malloc(sizeof(DataFrame));
    df->rows = rows;
    df->cols = cols;

    // Allocate memory for data
    df->data = (double**) malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        df->data[i] = (double*) malloc(cols * sizeof(double));
        memcpy(df->data[i], data[i], cols * sizeof(double));
    }

    // Allocate memory for row labels
    df->row_labels = (char**) malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        df->row_labels[i] = strdup(row_labels[i]);
    }

    // Allocate memory for column labels
    df->col_labels = (char**) malloc(cols * sizeof(char*));
    for (int i = 0; i < cols; i++) {
        df->col_labels[i] = strdup(col_labels[i]);
    }

    return df;
}

void free_dataframe(DataFrame *df) {
    for (int i = 0; i < df->rows; i++) {
        free(df->data[i]);
        free(df->row_labels[i]);
    }
    for (int i = 0; i < df->cols; i++) {
        free(df->col_labels[i]);
    }

    free(df->data);
    free(df->row_labels);
    free(df->col_labels);
    free(df);
}

