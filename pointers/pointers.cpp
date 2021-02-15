#include <iostream>

#define SIZE 9

int* create_array(){
    //static int arr[SIZE];
    int *arr2 = (int*)std::calloc(SIZE,sizeof(int));
    //for(int i =0; i < SIZE; i++){
     //}
    return arr2;
}

void print_array(int* arr){
    for (int i=0; i<SIZE;i++){
        std::cout << arr[i];
    }
}

void fill_array(int*arr){
    for (int i=0; i < SIZE; i++){
        arr[i] = i;
    }
}

int **create_matrix(){
    static int* matrix[SIZE];
    for (int i=0;i<SIZE;i++){
        matrix[i] = create_array();
    }
    return matrix;
}
void print_matrix(int **matrix){
    for(int i=0;i<SIZE;i++){
        for(int j=0; j<SIZE;j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void fill_matrix(int **matrix){
    int k = 0;
    for(int i=0;i<SIZE;i++){
        for(int j=0; j<SIZE;j++){
            matrix[i][j] = k;
            k++;
            print_matrix(matrix);
        }
    }
}


void change_value_in_matrix(int **matrix, int row, int col, int value){
    matrix[row][col] = value;
}


int main(){
    //int *array1 = create_array();
    //int *array2 = create_array();
    //fill_array(array1);
    //print_array(array1);
    //std::cout << std::endl;
    //print_array(array2);
    int **matrix = create_matrix();
    print_matrix(matrix);
    change_value_in_matrix(matrix, 0,0,1);
    std::cout << "-------------------------------" << std::endl;
    //fill_matrix(matrix);
    print_matrix(matrix);
    for (int i=0;i<SIZE;i++){
        free(matrix[i]);
    }
return 0;
}
