#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <wait.h>
#include <time.h>

int main(int argc, char** argv) {
  pid_t pid, sid;            
  time_t     now;
  struct tm *ts;
  char    path[80];
  char    sec[3];
  char    min[3];
  char    hour[3];
  char    nol[2]="0";
  int     child;

  pid = fork();    

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);

  while (1) {
    int counter;
    int status;

    now = time(NULL);

    ts = localtime(&now);
    strftime(sec, sizeof(sec), "%S", ts);
    strftime(min, sizeof(min), "%M", ts);
    strftime(hour, sizeof(hour), "%H", ts);
 
    if(argc==1){ 
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
    } 
    if(argc>=2) 
    { 
        for(counter=0;counter<argc;counter++){
            if(counter>0 && counter<=2){
                if(atoi(argv[counter])>=0 && atoi(argv[counter])<=59 || !strcmp(argv[counter], "*")){
                    // printf("\nargv[%d]: %s",counter,argv[counter]);
                }
                else{
                    fprintf(stderr, "Argument out of the range argv[%d]: %s\n", counter, argv[counter]);
                }
            }
            else if(counter==3){
                if(atoi(argv[counter])>=0 && atoi(argv[counter])<=23 || !strcmp(argv[counter], "*")){
                    // printf("\nargv[%d]: %s",counter,argv[counter]);
                }
                else{
                    fprintf(stderr, "Argument out of the range argv[%d]: %s\n", counter, argv[counter]);
                }
            } 
            else
            {
                // printf("\nargv[%d]: %s",counter,argv[counter]);
            }
        }
    }

    if(!strcmp(argv[1], "*") && !strcmp(argv[2], "*") && !strcmp(argv[3], "*")){
        child = fork();
        // sleep(1);
    }
    else if( atoi(argv[1])>=0 && atoi(argv[1])<=59 && !strcmp(argv[2], "*") && !strcmp(argv[3], "*")){
        
        if( strlen(argv[1]) == 1){
          strcat(nol,argv[1]);
          sprintf(argv[1], "%s", nol);
        }
        printf("%s %s\n", argv[1], sec);
        if(strcmp(argv[1], sec) == 0){
            child = fork();
        }
    }
    else if( !strcmp(argv[1], "*") && atoi(argv[2])>=0 && atoi(argv[2])<=59 && !strcmp(argv[3], "*")){

        if( strlen(argv[2]) == 1){
          strcat(nol,argv[2]);
          sprintf(argv[2], "%s", nol);
        }
        if(strcmp(argv[2], min) == 0){
            child = fork();
        }
    }
    else if( !strcmp(argv[1], "*") && !strcmp(argv[2], "*") && atoi(argv[3])>=0 && atoi(argv[3])<=23 ){

        if( strlen(argv[3]) == 1){
          strcat(nol,argv[3]);
          sprintf(argv[3], "%s", nol);
        }
        if(strcmp(argv[3], hour) == 0){
          child = fork();
        }
    }
    else if( atoi(argv[1])>=0 && atoi(argv[1])<=59 && atoi(argv[2])>=0 && atoi(argv[2])<=59 && !strcmp(argv[3],"*")){

        if( strlen(argv[1]) == 1){
          strcat(nol,argv[1]);
          sprintf(argv[1], "%s", nol);
        }
        if( strlen(argv[2]) == 1){
          strcat(nol,argv[2]);
          sprintf(argv[2], "%s", nol);
        }
        if(strcmp(argv[1], sec) == 0 && strcmp(argv[2], min) == 0){
          child = fork();
        }
    }
    else if( atoi(argv[1])>=0 && atoi(argv[1])<=59 && !strcmp(argv[2], "*") && atoi(argv[3])>=0 && atoi(argv[3])<=23 ){

        if( strlen(argv[1]) == 1){
          strcat(nol,argv[1]);
          sprintf(argv[1], "%s", nol);
        }
        if( strlen(argv[3]) == 1){
          strcat(nol,argv[3]);
          sprintf(argv[3], "%s", nol);
        }
        if(strcmp(argv[1], sec) == 0 && strcmp(argv[3], hour) == 0){
          child = fork();
        }
    }
    else if( !strcmp(argv[1], "*") && atoi(argv[2])>=0 && atoi(argv[2])<=59 && atoi(argv[3])>=0 && atoi(argv[3])<=23 ){

        if( strlen(argv[2]) == 1){
          strcat(nol,argv[2]);
          sprintf(argv[2], "%s", nol);
        }
        if( strlen(argv[3]) == 1){
          strcat(nol,argv[3]);
          sprintf(argv[3], "%s", nol);
        }
        if(strcmp(argv[1], min) == 0 && strcmp(argv[3], hour) == 0){
          child = fork();
        }
    }
    else if(atoi(argv[1])>=0 && atoi(argv[1])<=59  && atoi(argv[2])>=0 && atoi(argv[2])<=59 && atoi(argv[3])>=0 && atoi(argv[3])<=23){

        if( strlen(argv[1]) == 1){
          strcat(nol,argv[1]);
          sprintf(argv[1], "%s", nol);
        }
        if( strlen(argv[2]) == 1){
          strcat(nol,argv[2]);
          sprintf(argv[2], "%s", nol);
        }
        if( strlen(argv[3]) == 1){
          strcat(nol,argv[3]);
          sprintf(argv[3], "%s", nol);
        }
        if(strcmp(argv[1], sec) == 0 && strcmp(argv[1], min) == 0 && strcmp(argv[3], hour) == 0){
          child = fork();
        }
    }

    if(child == 0){
      strcpy(path, argv[4]);
      char *argv[] = {"bash", path, NULL};
      execv("/bin/bash", argv);
    } 
    sleep(1);
  }
}