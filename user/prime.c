//递归(为了开不同的管道) + fork子进程
    #include "kernel/types.h"
    #include "user/user.h"
/**
 * @brief 通过子进程递归的方式来写素数筛
*/
    void get_prime(int p1[2]){
        close(p1[1]);
        int n;
        int tag = read(p1[0],&n,4);
        if(!tag){   //管道中无数据
            close(p1[0]);
            exit(0);
        }
        printf("prime %d\n",n);
        int p2[2];
        pipe(p2);   //开新管道
        int pid = fork();
        if(!pid) get_prime(p2);
        else if(pid > 0){
            int m;
            while(read(p1[0],&m,4)){    //筛掉n的倍数
                if(m % n){ 
                    write(p2[1],&m,4);
                }
            }
            close(p1[0]);
            close(p2[1]);
            close(p2[0]);
            wait(0);    //回收子进程
        }
        else{
            printf("fork error\n");
            exit(pid);
        }
        exit(0);
    }
    int main(){
        int p[2];
        pipe(p);
        int i;
        for(i = 2; i <= 35; i++)
            write(p[1],&i,4);
        get_prime(p);
        exit(0);
    }