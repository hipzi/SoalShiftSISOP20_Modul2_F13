#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <wait.h>

int main(int argc, char **argv) 
{
    pid_t pid, sid;
    time_t     now;
    struct tm *ts;
    struct tm *timefile;   

    int     status;
    char    buf[80];
    char    str[80];
    char    namafile[80];
    char    photo[80];

    char    zip[255];
    char    download[255];

    unsigned int t;
    unsigned int size;

    pid = fork();
    pid_t get_pid = getpid(); 

    if (argv[1][1] == 'a') 
    {
        FILE *killer;
        killer = fopen("killer.sh", "w");
        fprintf(killer, "#!/bin/bash\n\n");
        fprintf(killer, "killall %s\n", argv[0]);
        fprintf(killer, "rm $0\n");
        fclose(killer);

        pid_t kill = fork();

        if (kill == 0) {
            char *argv[] = {"chmod", "+x", "killer.sh", NULL};
            execv("/bin/chmod", argv);
        }
    }
    else if (argv[1][1] == 'b') 
    {
        FILE *killer;
        killer = fopen("killer.sh", "w");
        fprintf(killer,"#!/bin/bash\n\n");
        fprintf(killer,"kill -9 %d\n", (int)get_pid);
        fprintf(killer,"rm $0\n");
        fclose(killer);

        pid_t kill = fork();

        if (kill == 0) {
            char *argv[] = {"chmod", "+x", "killer.sh", NULL};
            execv("/bin/chmod", argv);
        }
    }
    else if (argc==1 || (argv[1][1] != 'a' && argv[1][1] != 'b')) {
        printf("Pilih Mode : Masukan argumen dengan menggunakan parameter a atau b\n");
    }

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

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
        now = time(NULL);
        ts = localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d_%H:%M:%S", ts);
        // sprintf(str, "/home/hipzi/Documents/Sisop/Modul-2/%s/", buf);

        pid_t child1 = fork();
        if (child1 == 0) {
        pid_t make_folder = fork();

            if (make_folder == 0) {
                char *argv[] = {"mkdir", buf, NULL};
                execv("/bin/mkdir", argv);
            }
            if (make_folder > 0) {
                while ((wait(&status))>0);

                for(int i=0; i<20; i++)
                {
                    now = time(NULL);
                    timefile = localtime(&now);

                    strftime(namafile, sizeof(namafile), "%Y-%m-%d_%H:%M:%S", timefile);
                    t = (unsigned)time(NULL);
                    size = (t%1000)+100;
                    
                    sprintf(download, "https://picsum.photos/%u", size);
                    sprintf(photo, "%s/%s", buf, namafile);

                    pid_t download_files = fork();
                    if (download_files == 0) {
                        char *argv[] = {"wget", download, "-O", photo, "-q", NULL};
                        execv("/usr/bin/wget", argv);
                    }
                    sleep(5);
                }

                pid_t zip_folder = fork();

                if (zip_folder == 0) {
                    sprintf(zip, "%s.zip", buf);
                    char *argv[] = {"zip", "-mr", zip, buf, NULL};
                    execv("/usr/bin/zip", argv);
                }
            }
        }
    sleep(30);
    }
}