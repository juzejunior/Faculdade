#include<stdio.h>

int find(int n){


}

int main(int argc,char *argv[]){

    int (*find_fn)(int);
    find_fn = find;
    printf("%d", &find_fn);

}
