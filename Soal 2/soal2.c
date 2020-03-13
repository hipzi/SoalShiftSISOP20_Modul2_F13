#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <wait.h>
#include <time.h>

int main() 
{
    pid_t pid, sid;       
    pid = fork();
  
    time_t     now;
    struct tm *ts;
    char    buf[80];
    char    str[80];
    char    namafile[80];
    char    photo[80];
    char    path[80];

    unsigned int t;
    unsigned int size;

    char    download[255];
    char    zip[255];
    
    int make_folder;
    int download_photos;
    int loop_photos;
    int zip_folder;
    int status; 
    int child_id;   

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

    //   close(STDIN_FILENO);
    //   close(STDOUT_FILENO);
    //   close(STDERR_FILENO);

    while (1) {

        now = time(NULL);

        ts = localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d_%H:%M:%S", ts);
        sprintf(str, "/home/hipzi/Documents/Sisop/Modul-2/%s/", buf);

            make_folder = fork();
            if(make_folder == 0){
                char *argv[] = {"mkdir", str, NULL};
                execv("/bin/mkdir", argv);
            } 
            // else if (make_folder > 0){
                sleep(30);
            // }
            // else {
            //sleep(30);
            if (make_folder > 0){
                loop_photos = fork();
                for(int i=0; i<20; i++){
                    now = time(NULL);
                    ts = localtime(&now);
                    strftime(namafile, sizeof(namafile), "%Y-%m-%d_%H:%M:%S", ts);
                    sprintf(photo, "%s/%s", str, namafile);
                    download_photos = fork();
                    if(download_photos == 0){
                        t = (unsigned)time(NULL);
                        // sprintf(photo, "%s/%s", str, buf);
                        size = (t%1000)+100;
                        sprintf(download, "https://picsum.photos/%u", size);
                        char *argv[] = {"wget", "-O", photo, download, NULL};
                        execv("/usr/bin/wget", argv);
                    }
                sleep(5);
                }
            }
            // }
            if(loop_photos > 0){
                zip_folder = fork();
                if(zip_folder == 0){
                    sprintf(zip, "%s.zip", buf);
                    // sprintf(buff, "%s/", buf);
                    // printf("%s\n", "BISA");
                    //char *argv[] = {"zip", "-m", zip, str, NULL};
                    char *argv[] = {"zip","-mr", zip, buf, NULL};
                    // char *argv[] = {"zip", zip, buf, NULL};
                    // printf("srgv : %s %s\n", zip, buf);
                    execv("/usr/bin/zip", argv);
                    // sleep(30);
                }
            }
            // sleep(1);
        // }
        // if(loop_photos > 0){
        // while ((wait(&status)) > 0);
        // sprintf(path, "%s", "/home/hipzi/Documents/Sisop/Modul-2/");
        // }
        //printf("%lld\n", size);

        //char *argv[] = {"mkdir", str, NULL};
        //execv("/bin/mkdir", argv);
    }
}