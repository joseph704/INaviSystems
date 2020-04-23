//
//  main.c
//  iNaViSystems
//
//  Created by 차요셉 on 20/04/2020.
//  Copyright © 2020 차요셉. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
FILE *fp;

void create_data(int max_count,char *fileName,int *data){
    fp = fopen(fileName, "w");
    int i, sub_i;
    srand((unsigned int)time(NULL));
    for (i = 0;i<max_count;i++){
        data[i] = rand() % 1000000 + 1;     // 1~1000000까지 난수 발생
        for (sub_i = 0; sub_i<i;sub_i++){
            if (data[i] == data[sub_i]) {     // 중복 배제
                i--;
                break;
            }
        }
    }
    for (i = 0; i < max_count; i++) fprintf(fp,"%d\n", data[i]); // a.txt 또는 b.txt 에 난수들 저장
    fclose(fp);
}



int main(int argc, const char * argv[]) {
    int a_count = 100000;
    int b_count = 1000;
    int data_a[a_count],data_b[b_count];
    int i,j;
    
    create_data(a_count, "a.txt",data_a);    // data_a : a.txt 난수들의 배열
    usleep(100000);
    create_data(b_count, "b.txt",data_b);    // data_b : b.txt 난수들의 배열
    fp = fopen("r.txt", "w");
    for (i=0;i<a_count;i++){
        for (j=0;j<b_count;j++){
            if(data_a[i]==data_b[j]){
                fprintf(fp,"%d\n", data_a[i]); // a.txt 난수들과 b.txt 난수들의 교집합 r.txt에 저장
            }
        }
    }
    printf("Finished\n");
    fclose(fp);
    return 0;
}
