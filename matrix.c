#ifndef STDLIB
#define STDLIB
#include<stdlib.h>
#endif
#ifndef MATRIX
#define MATRIX
#include"matrix.h"
#endif

int getPosition(const struct Matrix *now_used, const int row, const int col) {
    return (now_used -> col) * (row - 1) + col - 1;
}

float getNum(const struct Matrix *now_used, const int row, const int col) {
    if( row > ( now_used -> row ) || col > ( now_used -> col ) || row <= 0 || col <= 0 ) return 0;
    return now_used -> data[ getPosition (now_used, row, col) ];
}
void setNum(struct Matrix *now_used, const float num, const int row, const int col) {
    if( row > (now_used -> row) || col > (now_used -> col) || row<=0 || col<=0 ) return ;
    now_used->data[ getPosition (now_used, row, col) ]=num;
}

//构造函数
void createMatrix(const int row, const int col, struct Matrix *used) {
    if( row <= 0 || col <= 0) return;
    used->col = col;
    used->row = row;
    used->data = (float *) malloc( sizeof(float) * row * col );
}
void deleteMatrix(struct Matrix *used) {
    free(used->data);
    free(used);
}
void copyMatrix(const struct Matrix *source, struct Matrix *dest) {
    deleteMatrix(dest);
    createMatrix(source->row, source->col, dest);
    for(int r=1; r<=source->row; r++) {
        for(int c=1; c<=source->col; c++){
            setNum(dest, getNum(source, r, c), r, c);
        }
    }
}