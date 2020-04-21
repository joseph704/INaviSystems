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
        data[i] = rand() % 1000000 + 1;
        for (sub_i = 0; sub_i<i;sub_i++){
            if (data[i] == data[sub_i]) {
                i--;
                break;
            }
        }
    }
    for (i = 0; i < max_count; i++) fprintf(fp,"%d\n", data[i]);
    fclose(fp);
}



int main(int argc, const char * argv[]) {
    int a_count = 100000;
    int b_count = 1000;
    int data_a[a_count],data_b[b_count];
    int i,j;
    
    create_data(a_count, "a.txt",data_a);
    usleep(100000);
    create_data(b_count, "b.txt",data_b);
    fp = fopen("r.txt", "w");
    for (i=0;i<a_count;i++){
        for (j=0;j<b_count;j++){
            if(data_a[i]==data_b[j]){
                fprintf(fp,"%d\n", data_a[i]);
            }
        }
    }
    printf("Finished");
    fclose(fp);
    return 0;
}
