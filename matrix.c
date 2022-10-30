#ifndef STDLIB_H
#define STDLIB_H
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
    if( row > ( now_used -> row ) || col > ( now_used -> col ) || row <= 0 || col <= 0 ) return 0.0;
    return now_used -> data[ getPosition (now_used, row, col) ];
}
void setNum(struct Matrix *now_used, const float num, const int row, const int col) {
    if( row > (now_used -> row) || col > (now_used -> col) || row<=0 || col<=0 ) return ;
    now_used -> data[ getPosition (now_used, row, col) ]=num;
}

//构造函数
void createMatrix(const int row, const int col, struct Matrix *used) {
    if( row <= 0 || col <= 0) return;
    if(used == NULL) return;
    used -> col = col;
    used -> row = row;
    used -> data = (float *) malloc( sizeof(float) * row * col );
}
void deleteMatrix(struct Matrix *used) {
    if(used == NULL) return;
    free(used -> data);
    free(used);
}
struct Matrix *copyMatrix(const struct Matrix *source, struct Matrix *dest) {
    if(source == NULL || dest == NULL) return NULL;
    deleteMatrix(dest);
    createMatrix(source -> row, source -> col, dest);
    for(int r=1; r<=source -> row; r++) {
        for(int c=1; c<=source -> col; c++){
            setNum(dest, getNum(source, r, c), r, c);
        }
    }
    return dest;
}

//计算
struct Matrix *addMatrix(const struct Matrix *a, const struct Matrix *b, struct Matrix *ans) {
    deleteMatrix(ans);
    ans = (struct Matrix *) malloc ( sizeof( struct Matrix ) );
    if(a == NULL || b == NULL) return NULL;
    if( a -> row != b -> row || a -> col != b -> col ) return NULL;
    createMatrix(a -> row, a -> col, ans);
    for(int r=1; r<=ans -> row; r++) {
        for(int c=1; c<=ans -> col; c++) {
            setNum(ans, getNum(a, r, c) + getNum(b, r, c), r, c);
        }
    }
    return ans;
}
struct Matrix *subtractMatrix(const struct Matrix *a, const struct Matrix *b, struct Matrix *ans) {
    deleteMatrix(ans);
    ans = (struct Matrix *) malloc ( sizeof( struct Matrix ) );
    if(a == NULL || b == NULL) return NULL;
    if( a -> row != b -> row || a -> col != b -> col ) return NULL;
    createMatrix(a -> row, a -> col, ans);
    for(int r=1; r<=ans -> row; r++) {
        for(int c=1; c<=ans -> col; c++) {
            setNum(ans, getNum(a, r, c) - getNum(b, r, c), r, c);
        }
    }
    return ans;
}
struct Matrix *multiplyMatrix(const struct Matrix *a, const struct Matrix *b, struct Matrix *ans) {
    deleteMatrix(ans);
    ans =  (struct Matrix *) malloc ( sizeof( struct Matrix ) );
    if(a == NULL || b == NULL) return NULL;
    if(a -> col != b -> row) return NULL;
    createMatrix(a -> row, b -> col, ans);
    for(int r=1; r<=ans -> row; r++) {
        for(int c=1; c<=ans -> col; c++) {
            float ans_tmp=0;
            for(int k=1; k<=a->col;k++) {
                ans_tmp+=getNum(a, r, k) * getNum(b, k, c);
            }
            setNum(ans, ans_tmp, r, c);
        }
    }
    return ans;
}
struct Matrix *addScaler(const float num, const struct Matrix *used, struct Matrix *ans) {
    if(used == NULL) return NULL;
    ans = (struct Matrix *) malloc ( sizeof( struct Matrix ) );
    copyMatrix(used, ans);
    for(int r=1; r<=ans -> row; r++) {
        for(int c=1; c<=ans -> col; c++) {
            setNum(ans, getNum(ans, r, c) + num, r, c);
        }
    }
    return ans;
}
struct Matrix *subtractScaler(const float num, const struct Matrix *used, struct Matrix *ans) {
    if(used == NULL) return NULL;
    ans = (struct Matrix *) malloc ( sizeof( struct Matrix ) );
    copyMatrix(used, ans);
    for(int r=1; r<=ans -> row; r++) {
        for(int c=1; c<=ans -> col; c++) {
            setNum(ans, getNum(ans, r, c) - num, r, c);
        }
    }
    return ans;
}
struct Matrix *multiplyScaler(const float num, const struct Matrix *used, struct Matrix *ans) {
    if(used == NULL) return NULL;
    ans = (struct Matrix *) malloc ( sizeof( struct Matrix ) );
    copyMatrix(used, ans);
    for(int r=1; r<=ans -> row; r++) {
        for(int c=1; c<=ans -> col; c++) {
            setNum(ans, getNum(ans, r, c) * num, r, c);
        }
    }
    return ans;
}

//最大最小
float max(const struct Matrix *used) {
    if(used == NULL) return 0.0;
    float ans = getNum(used, 1, 1);
    for(int r=1; r<=used -> row; r++) {
        for(int c=1; c<=used -> col; c++) {
            if(getNum(used, r, c) > ans) {
                ans =getNum(used, r, c);
            }
        }
    }
    return ans;
}
float min(const struct Matrix *used) {
    if(used == NULL) return 0.0;
    float ans = getNum(used, 1, 1);
    for(int r=1; r<=used -> row; r++) {
        for(int c=1; c<=used -> col; c++) {
            if(getNum(used, r, c) < ans) {
                ans =getNum(used, r, c);
            }
        }
    }
    return ans;
}

//输出
void print(const struct Matrix *used) {
    if(used == NULL) return;
    for(int r=1; r<=used -> row; r++) {
        for(int c=1; c<=used -> col; c++) {
            printf("%f ", getNum(used, r, c));
        }
        printf("\n");
    }
    return ;
}