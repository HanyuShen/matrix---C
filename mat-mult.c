#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(int argc, char **argv){
    if(argc != 4){
        printf("You must enter three inputs!\n");
        exit(0);
    }
    else if(atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0){
        printf("The number must be positive integers.\n");
    }
    //else if
    else {
        int s = atoi(argv[3]);
        srand(s);
        clock_t start,finish;
        double time;
        start = clock();
        int i = 0,j = 0;
        int M = atoi(argv[1]);
        int N = atoi(argv[2]);
        //int Arr1[M][N];
        //int Arr2[N][M];
        //int Arr3[M][M];

        int** M1 = (int**)malloc(sizeof(int*) * M);
        for(int i=0;i<M;i++){
            M1[i] = (int*)malloc(sizeof(int*) * N);
        }
        printf("MATRIX 1 is: \n");
        for(i=0;i<M;++i){
            for(j=0;j<N;++j){
                int A1 = rand() % 99;
                M1[i][j] = A1;
                printf("%d\t",A1);
            }
            printf("\n");
        }

        int** M2 = (int**)malloc(sizeof(int*) * N);
        for(int i=0;i<N;i++){
            M2[i] = (int*)malloc(sizeof(int*) * M);
        }
        printf("MATRIX 2 is: \n");
        for(i=0;i<N;++i){
            for(j=0;j<M;++j){
                int A2 = rand() % 99;
                M2[i][j] = A2;
                printf("%d\t",A2);
            }
            printf("\n");
        }

        int** M3 = (int**)malloc(sizeof(int*) * M);
        for(int i=0;i<M;i++){
            M3[i] = (int*)malloc(sizeof(int*) * M);
        }
        printf("RESULT: \n");
        for(int rank=0;rank<M;rank++){
            for(int col=0;col<M;col++){
                M3[rank][col] = 0;
                for(int k=0;k<N;k++){
                    M3[rank][col] += M1[rank][k] * M2[k][col];
                }
            }
        }

        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                int A3;
                A3 = M3[i][j];
                printf("%d\t",A3);
            }
            printf("\n");
        }


        finish = clock();
        time = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("EXECUTION TIME: %f\n",time);

        for(int i=0;i<M;i++){
            free(M1[i]);
            free(M3[i]);
        }
        for(int i=0;i<N;i++){
            free(M2[i]);
        }
        free(M1);
        free(M2);
        free(M3);

        return 0;
    }
}