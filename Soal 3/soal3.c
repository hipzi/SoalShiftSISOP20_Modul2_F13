#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <wait.h>

int main()
{  
    int status;
    int process_7;
    int process_6;
    int process_5;
    int process_4;
    int process_3;
    int process_2;
    int process_1;

    process_7 = fork();
    if(process_7 == 0){
        char *argv[] = {"mkdir", "-p", "/home/hipzi/modul2/indomie/", NULL};
        execv("/bin/mkdir", argv);
    }
    sleep(5);
    if(process_7 > 0){
        while ((wait(&status)) > 0);
            process_6 = fork();
            if(process_6 == 0){
                char *argv[] = {"mkdir", "-p", "/home/hipzi/modul2/sedaap/", NULL};
                execv("/bin/mkdir", argv);
            }
    }
    if(process_6 > 0){
        while ((wait(&status)) > 0);
            process_5 = fork();
            if(process_5 == 0){
                char *argv[] = {"unzip", "/home/hipzi/modul2/jpg.zip","-d","/home/hipzi/modul2/", NULL};
                execv("/usr/bin/unzip", argv);
            }
    }
    if(process_5 > 0){
        while ((wait(&status)) > 0);
            process_4 = fork();
            if(process_4 == 0){
                char *argv[] = {"find", "/home/hipzi/modul2/jpg/", "-type", "f", "-exec", "mv", "-t", "/home/hipzi/modul2/sedaap/","{}","+",NULL};
                execv("/usr/bin/find", argv);
            }
    }
    if(process_4 > 0){
        while ((wait(&status)) > 0);
            process_3 = fork();
            if(process_3 == 0){
                char *argv[] = {"find","/home/hipzi/modul2/jpg/", "-type", "d","-mindepth", "1", "-exec", 
                                "mv", "-t", "/home/hipzi/modul2/indomie/","{}","+",NULL};
                execv("/usr/bin/find", argv);
            }
    }
    if(process_3 > 0){
        while ((wait(&status)) > 0);
            process_2 = fork();
            if(process_2 == 0){
                char *argv[] = {"find","/home/hipzi/modul2/indomie/", "-type", "d","-mindepth", "1", "-exec", 
                                    "touch", "{}/coba1.txt", ";",NULL};
                execv("/usr/bin/find", argv);
            }
    }
    sleep(3);
    if(process_2 > 0){
        while ((wait(&status)) > 0);
            process_1 = fork();
            if(process_1 == 0){
                char *argv[] = {"find","/home/hipzi/modul2/indomie/", "-type", "d","-mindepth", "1", "-exec", 
                                    "touch", "{}/coba2.txt", ";",NULL};
                execv("/usr/bin/find", argv);
            }
    }
}
