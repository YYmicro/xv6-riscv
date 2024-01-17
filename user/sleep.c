// #include "kernel/types.h"
// #include "user/user.h"

// int main(int argc, char **argv){
//     if(argc<2)
//         printf("no argument\n");
//     else if(argc>2)
//         printf("excessive argument\n");
//     else{
//         int tag = 1;
//         char *p = argv[1];
//         // printf("%c\n",argv[0]);
//         while(*p){
//             if(*p < '0' || *p > '9'){
//                 tag = 0;
//                 break;
//             }
//             // printf("%c\n",*p);
//             p++;
//         }
//         if(tag)
//             sleep(atoi(argv[1]));
//         else 
//             printf("illegal argument\n");
//     }
//     return 0;
// }

#include "kernel/types.h"
#include "user/user.h"
int main(int argc, char** argv){
    if(argc<2){
        printf("not enough\n");
    }
    else if(argc>2){
        printf("args are too many\n");
    }
    else {
        int valid=1;
        char* p = argv[1];
        while(*p){
            if(*p<'0' || *p>'9'){
                valid=0;
                break;
            }
            p++;
        }
        if(valid){
            sleep(atoi(argv[1]));
        }
        else{
            printf("invalid arguments\n");
        }
    }
    exit(0);
}
