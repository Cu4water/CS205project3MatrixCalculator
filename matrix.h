struct Matrix{
    int row,col;// 我们使用了[0,0]~[row-1,col-1]的内存，您可以调用[1,1]~[row,col]的数据,请使用get和set
    float *data;
};

//get, set
float getNum(const struct Matrix *now_used, const int row, const int col);
void setNum(struct Matrix *now_used, const float num, const int row, const int col);

//构造函数
void createMatrix(const int row, const int col, struct Matrix *used);
void deleteMatrix(struct Matrix *used);
struct Matrix *copyMatrix(const struct Matrix *source, struct Matrix *dest);

//计算
struct Matrix *addMatrix(const struct Matrix *a, const struct Matrix *b, struct Matrix *ans);       //ans=a+b
struct Matrix *subtractMatrix(const struct Matrix *a, const struct Matrix *b, struct Matrix *ans);  //ans=a-b
struct Matrix *multiplyMatrix(const struct Matrix *a, const struct Matrix *b, struct Matrix *ans);  //ansa*b
struct Matrix *addScaler(const float num, const struct Matrix *used, struct Matrix *ans);           //ans=used each +num
struct Matrix *subtractScaler(const float num, const struct Matrix *used, struct Matrix *ans);      //ans=used each -num
struct Matrix *multiplyScaler(const float num, const struct Matrix *used, struct Matrix *ans);      //ans=used*num


//最大最小
float max(const struct Matrix *used);
float min(const struct Matrix *used);

//输出
void print(const struct Matrix *used);
