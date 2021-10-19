#include<stdio.h>
#define d_boot_normal_start 0xe500
unsigned int r_address = d_boot_normal_start;
int main(){
    int var;
    int *ptr;
    int val;
    var = 3000;
    ptr = &var;
    val = *ptr;
    printf("%d\n",var);
    printf("%d\n",ptr);
    printf("%d\n",val);
}