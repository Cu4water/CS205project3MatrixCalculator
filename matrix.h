#ifndef MATRIX
#define MATRIX
struct Matrix{
    int row,col;
    float *data;
};

float getNum(const Matrix *now_used, const int row, const int col);
int getPosition(const int max_row, const int max_col, const int row, const int col);
int matrexLen(const Matrix *used);

void createMatrix(const int row, const int col, Matrix *used);
void deleteMatrix(Matrix *used);
void copyMatrix(const Matrix *source, Matrix *dest);
void copyMatrix(const Matrix source, Matrix *dest);

Matrix constAddMatrix(const Matrix *a, const Matrix *b);            //a+b
Matrix constSubtractMatrix(const Matrix *a, const Matrix *b);       //a-b
Matrix constMultiplyMatrix(const Matrix *a, const Matrix *b);       //a*b
Matrix constAddScaler(const float num, const Matrix *used);         //used each +num
Matrix constSubtractScaler(const float num, const Matrix *used);    //used each -num
Matrix constMultiplyScaler(const float num, const Matrix *used);    //used*num

void addMatrix(const Matrix *a, Matrix *b);                         //b+=a
void subtractMatrix(const Matrix *a, Matrix *b);                    //b-=a
void multiplyMatrix(const Matrix *a, Matrix *b);                    //b*=a
void addScaler(const float num, Matrix *used);                      //used each +=num
void subtractScaler(const float num, Matrix *used);                 //used each -=num
void constMultiplyScaler(const float num, Matrix *used);            //used*=num

float max(const Matrix *used);
float min(const Matrix *used);

void print(const Matrix *used);

#endif