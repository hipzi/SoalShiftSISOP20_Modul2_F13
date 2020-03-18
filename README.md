# MODUL 2

 - Soal 1 :
	 * <a href="#soal-1-a-b">soal 1 : a & b </a>
	 * <a href="#soal-1-c">soal 1 : c </a>
	 * <a href="#soal-1-d">soal 1 : d </a>
	 * <a href="#soal-1-e">soal 1 : e </a>
 - Soal 2
	 * <a href="#soal-2-a">soal 2 : a </a>
	 * <a href="#soal-2-b">soal 2 : b </a>
	 * <a href="#soal-2-c">soal 2 : c </a>
	 * <a href="#soal-2-d-e">soal 2 : d & e </a>
 - Soal 3
	 * <a href="#soal-3-a">soal 3 : a </a>
	 * <a href="#soal-3-b">soal 3 : b </a>
	 * <a href="#soal-3-c">soal 3 : c </a>
	 * <a href="#soal-3-d">soal 3 : d </a>

<a id="soal-1-a-b"> </a> 
## SOAL 1
<justify>
1. Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan ketentuan sebagai berikut:
<p></p>
a. Program menerima 4 argumen berupa:</br>
&nbsp;&nbsp;&nbsp;&nbsp;i.Detik: 0-59 atau * (any value)</br>
&nbsp;&nbsp;&nbsp;&nbsp;ii.Menit: 0-59 atau * (any value)</br>
&nbsp;&nbsp;&nbsp;&nbsp;iii.Jam: 0-23 atau * (any value)</br>
&nbsp;&nbsp;&nbsp;&nbsp;iv.Path file .sh
<p></p>
b. Program akan mengeluarkan pesan error jika argumen yang diberikan tidak sesuai
<p></p>
    int main(int argc, char** argv) {
    
        int counter;
        int status;

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
                        exit(EXIT_FAILURE);
                    }
                }
                else if(counter==3){
                    if(atoi(argv[counter])>=0 && atoi(argv[counter])<=23 || !strcmp(argv[counter], "*")){
                        // printf("\nargv[%d]: %s",counter,argv[counter]);
                    }
                    else{
                        fprintf(stderr, "Argument out of the range argv[%d]: %s\n", counter, argv[counter]);
                        exit(EXIT_FAILURE);
                    }
                } 
                else
                {
                    // printf("\nargv[%d]: %s",counter,argv[counter]);
                }
            }
        }
    ...
<p></p>

Keterangan : </br>
<p></p> 
- <code>argc</code> untuk mengecek jumlah argumen yang dimasukkan </br>
- <code>for(counter=0;counter < argc;counter++) </code> melakukan looping sebanyak jumlah argumen</br>
- <code>if(counter>0 && counter<=2)</code> mengecek detik dan menit sesuai format : <code>(atoi(argv[counter])>=0 && atoi(argv[counter])<=59 || !strcmp(argv[counter], "*"))</code> yang berarti berisi angka dengan range 0-59 ataupun <code>*</code> </br>
- <code>fprintf(stderr, "Argument out of the range argv[%d]: %s\n", counter, argv[counter])</code>akan mengeluarkan pesan error jika menginputkan argumen tidak sesuai dengan format yang ditentukan dan program akan berhenti<code>exit(EXIT_FAILURE)</code></br>
- <code>if(counter==3)</code> mengecek jam sesuai format : <code>(atoi(argv[counter])>=0 && atoi(argv[counter])<=23 || !strcmp(argv[counter], "*"))</code> yang berarti berisi angka dengan range 0-23 ataupun <code>*</code></br>

<a id="soal-1-c"> </a>
<p></p>
c. Program hanya menerima 1 config cron

    ./bisa 10 \* \* /home/hipzi/bashsoal1.sh

Keterangan : </br>
<p></p> 
- <code>./bisa</code> nama program </br>
- <code>10</code> program berjalan setiap detik ke-10</br>
- <code>*</code> program berjalan setiap menit</br>
- <code>*</code> program berjalan setiap jam</br>
- <code>/home/hipzi/bashsoal1.sh</code>path script yang akan dijalankan</br>
<p></p>   
Code :

    while (1) {

    now = time(NULL);

    ts = localtime(&now);
    strftime(sec, sizeof(sec), "%S", ts);
    strftime(min, sizeof(min), "%M", ts);
    strftime(hour, sizeof(hour), "%H", ts);
    strftime(buf, sizeof(buf), "%Y-%m-%d_%H:%M:%S", ts);
    ...
Keterangan : </br>
<p></p> 
- <code>now = time(NULL)</code> mengambil waktu sekarang dan menyimpan dalam variabel <code>now</code></br>
- <code>ts = localtime(&now)</code>mengambil localtime dan menyimpan dalam variabel <code>ts</code></br>
- <code>strftime(sec, sizeof(sec), "%S", ts)</code>mengambil detik sekarang dan menyimpannya dalam string <code>sec</code></br>
- <code>strftime(min, sizeof(min), "%M", ts)</code>mengambil menit sekarang dan menyimpannya dalam string <code>min</code></br>
- <code>strftime(hour, sizeof(hour), "%H", ts)</code>mengambil jam sekarang dan menyimpannya dalam string <code>hour</code></br>
- <code>strftime(buf, sizeof(buf), "%Y-%m-%d_%H:%M:%S", ts);</code>mengambil timestamp sekarang dan menyimpannya dengan format <code>%Y-%m-%d_%H:%M:%S</code>dalam string <code>buf</code></br>
<p></p>
Untuk menjalankan script sesuai dengan ketentuan detik menit jam yang telah tertera pada soal maka terdapat 8 kombinasi, seperti berikut :  

    if(!strcmp(argv[1], "*") && !strcmp(argv[2], "*") && !strcmp(argv[3], "*")){
        child = fork();
        // sleep(1);
    }
    ...
    else if( !strcmp(argv[1], "*") && atoi(argv[2])>=0 && atoi(argv[2])<=59 && !strcmp(argv[3], "*")){

        if( strlen(argv[2]) == 1){
          strcat(nol,argv[2]);
          sprintf(argv[2], "%s", nol);
        }
        if(strcmp(argv[2], min) == 0){
            child = fork();
        }
    }
    ...
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
    ...
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
    ...
Keterangan : </br>
<p></p> 
- <code>if(!strcmp(argv[1], "*") && !strcmp(argv[2], "*") && !strcmp(argv[3], "*"))</code> jika detik menit jam berupa any value <code>*</code></br>
- <code>else if( !strcmp(argv[1], "*") && atoi(argv[2])>=0 && atoi(argv[2])<=59 && !strcmp(argv[3], "*"))</code>jika detik dan jam any value <code>*</code> dan menit merupakan angka dalam range 0-59</br>
- <code>else if( atoi(argv[1])>=0 && atoi(argv[1])<=59 && atoi(argv[2])>=0 && atoi(argv[2])<=59 && !strcmp(argv[3],"*"))</code>jika detik dan menit merupakan angka dalam range 0-59 dan jam any value <code>*</code></br>
- <code>else if(atoi(argv[1])>=0 && atoi(argv[1])<=59  && atoi(argv[2])>=0 && atoi(argv[2])<=59 && atoi(argv[3])>=0 && atoi(argv[3])<=23)</code>jika detik dan menit merupakan angka dalam range 0-59 serta jam merupakan angka dalam range 0-23</br>
- <code>child = fork()</code>membuat child process dengan menggunakan <code>fork()</code></br>
- <code>if(strlen(argv[1]) == 1)</code>jika panjang string menit detik atau jam sama dengan satu maka harus menggunakan <code>strcat(nol,argv[1])</code> untuk menambahkan string tersebut dengan string <code>0</code> di depannya agar bisa dibandingkan dengan format time menggunakan <code>strcmp</code></br>
- <code>if(strcmp(argv[2], min) == 0)</code>jika inputan menit sama dengan waktu menit sekarang maka akan membuat <code>child = fork()</code> begitu pula untuk detik dan jam</br>
<p></p>

    if(child == 0){
      strcpy(path, argv[4]);
      char *argv[] = {"bash", path, NULL};
      execv("/bin/bash", argv);
    } 
    sleep(1);
  }
<p></p>
Keterangan : </br>
<p></p> 
- <code>if(child == 0)</code> jika ada child proses maka melakukan copy isi dari <code>argv[4]</code> ke dalam variabel path menggunakan <code>strcpy</code></br>
- <code>char *argv[] = {"bash", path, NULL}</code> untuk menjalankan command bash di c </br>
- <code>execv("/bin/bash", argv)</code>tempat dimana command<code>bash</code> berada, jika bingung mencari tempat command caranya adalah <code>which *namacommand*</code></br>
- <code>sleep(1)</code> program akan berjalan setiap detik</br>

<p></p>

<a id="soal-1-d"> </a>
<p></p>
d. Program berjalan di background (daemon)

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
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
<p></p>
Keterangan : </br>
<p></p> 
- <code>pid = fork();</code> untuk membuat parent process dan memunculkan child process, menyimpan pid dari child process </br>
- <code>if (pid < 0)</code> program akan keluar jika fork gagal <code>exit(EXIT_FAILURE)</code></br>
- <code>if (pid > 0)</code> program akan keluar jika fork berhasil <code>exit(EXIT_SUCCESS)</code> parent process dibunuh agar sistem operasi mengira bahwa proses telah selesai</br>
- <code>umask(0)</code> untuk mengatur permission agar mendapat akses full terhadap file yang dibuat oleh daemon</br>
- <code>sid = setsid()</code>untuk mendapatkan SID, sebuah child harus memiliki SID agar saat parentnya sudah di-<code>kill</code> dapat tetap berjalan dan tidak menjadi orphan process</br>
- <code>if (sid < 0)</code> program akan keluar jika sid gagal <code>exit(EXIT_FAILURE)</code></br>
- <code>if ((chdir("/")) < 0)</code> change working directory harus diubah ke suatu directory yang pasti ada jadi untuk amannya maka working directory diubah ke root <code>/</code></br>
- karena sebuah daemon tidak boleh berjalan di terminal maka harus menutup file descriptor standar yaitu : <code>close(STDIN_FILENO)</code> tidak menerima inputan, <code>close(STDOUT_FILENO)</code> tidak mengeluarkan output, <code>close(STDERR_FILENO)</code> tidak mengeluarkan pesan error</br>
<p></p>
<a id="soal-1-e"> </a>
<p></p>
e. Tidak boleh menggunakan fungsi system()
</justify>
    
    Tidak ada fungsi system()

Source Code : [Soal 1](https://github.com/hipzi/SoalShiftSISOP20_Modul2_F13/blob/master/Soal%201/revisisoal1.c)
 
<a id="soal-2-a"></a> 
## SOAL 2
<justify>
2. Shisoppu mantappu! itulah yang selalu dikatakan Kiwa setiap hari karena sekarang dia merasa sudah jago materi sisop. Karena merasa jago, suatu hari Kiwa iseng membuat sebuah program. 
<p></p>   
<p>a. Pertama-tama, Kiwa membuat sebuah folder khusus, di dalamnya dia membuat sebuah program C yang per 30 detik membuat sebuah folder dengan nama timestamp [YYYY-mm-dd_HH:ii:ss]. </p>
<p></p>

    while (1) {
            now = time(NULL);
            ts = localtime(&now);
            strftime(buf, sizeof(buf), "%Y-%m-%d_%H:%M:%S", ts);

            pid_t child1 = fork();
            if (child1 == 0) {
            pid_t make_folder = fork();

                if (make_folder == 0) {
                    char *argv[] = {"mkdir", buf, NULL};
                    execv("/bin/mkdir", argv);
                }
                ...
            }
        sleep(30);
    }
Keterangan : </br>
<p></p> 
- <code>now = time(NULL)</code> mengambil waktu sekarang dan menyimpan dalam variabel <code>now</code></br>
- <code>ts = localtime(&now)</code>mengambil localtime dan menyimpan dalam variabel <code>ts</code></br>
- <code>strftime(buf, sizeof(buf), "%Y-%m-%d_%H:%M:%S", ts);</code>mengambil timestamp sekarang dan menyimpannya dengan format <code>%Y-%m-%d_%H:%M:%S</code>dalam string <code>buf</code></br>
- <code>pid_t child1 = fork()</code>membuat child process dengan menggunakan <code>fork()</code></br>
- <code>if(child1 == 0)</code> jika ada child proses yang bernama child1 maka membuat child proses baru yang bernama <code>pid_t make_folder = fork()</code> </br>
- <code>if (make_folder == 0)</code> jika ada child proses yang bernama <code>make_folder</code> maka akan <code>char *argv[] = {"mkdir", buf, NULL}</code> menjalankan command <code>mkdir</code> dan memberi nama folder tersebut dengan string <code>buf</code></br>
- <code>execv("/bin/mkdir", argv)</code>untuk menjalankan command <code>mkdir</code></br>
- <code>sleep(30)</code> untuk membuat folder setiap 30 detik</br>
<p></p>
<a id="soal-2-b"></a>
<p>b. Tiap-tiap folder lalu diisi dengan 20 gambar yang di download dari https://picsum.photos/, dimana tiap gambar di download setiap 5 detik. Tiap gambar berbentuk persegi dengan ukuran (t%1000)+100 piksel dimana t adalah detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss]. </p>
<p></p>

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
    ...
    }

Keterangan : </br>
<p></p> 
- <code> if (make_folder > 0)</code> kondisi bernilai true ketika child process yang bernama <code>make_folder</code> telah kembali ke parent process <code>while ((wait(&status))>0)</code> untuk menunggu dan memastikan bahwa folder telah terbentuk </br>
- <code>for(int i=0; i < 20; i++)</code> melakukan looping (untuk download gambar) sebanyak 20 </br>
- <code>now = time(NULL)</code> untuk mengambil waktu lagi saat melalukan looping dan menyimpan dalam variabel <code>now</code></br>
- <code>ts = localtime(&now)</code>mengambil localtime lagi saat melalukan looping dan menyimpan dalam variabel <code>ts</code></br>
- <code>t = (unsigned)time(NULL)</code> mengambil detik Epoch Unix </br>
- <code>size = (t%1000)+100</code> merupakan ukuran gambar yang di download </br>
- <code>sprintf(download, "https://picsum.photos/%u", size)</code> menggabungkan link tempat download gambar dengan ukuran gambar ke dalam variabel <code>download</code></br>
- <code>sprintf(photo, "%s/%s", buf, namafile)</code> menggabungkan <code>buf</code>(nama folder) dan <code>namafile</code> ke dalam variabel <code>photo</code></br>
- <code>pid_t download_files = fork()</code> membuat child process yang bernama <code>download_files</code></br> 
- <code>if (download_files == 0)</code> jika child process yang bernama <code>download_files</code> berjalan maka <code>char *argv[] = {"wget", download, "-O", photo, "-q", NULL}</code> menjalankan command <code>wget</code> link download tertera dalam variabel <code>download</code> mengunakan parameter <code>-O</code> untuk merename gambar hasil download sesuai dengan isi variabel <code>photo</code> sedangkan parameter <code>-q</code>agar log wget-nya tidak muncul di terminal</br>
- <code>execv("/usr/bin/wget", argv)</code>untuk menjalankan command <code>wget</code></br>
- <code>sleep(5)</code> agar gambar di download setiap 5 detik</br>

<p></p>
<a id="soal-2-c"></a>
c. Agar rapi, setelah sebuah folder telah terisi oleh 20 gambar, folder akan di zip dan
folder akan di delete(sehingga hanya menyisakan .zip).
<p></p>

    pid_t zip_folder = fork();

    if (zip_folder == 0) {
        sprintf(zip, "%s.zip", buf);
        char *argv[] = {"zip", "-mr", zip, buf, NULL};
        execv("/usr/bin/zip", argv);
    }
Keterangan : </br>
<p></p> 
- <code>pid_t zip_folder = fork()</code> membuat child process yang bernama <code>zip_folder</code></br>
- <code>if (zip_folder == 0)</code> jika child process yang bernama <code>zip_folder</code> berjalan maka <code>sprintf(zip, "%s.zip", buf)</code> menggabungkan nama folder menjadi <code>namafolder.zip</code> kemudian menyimpannya dalam variabel <code>zip</code></br>
- <code>char *argv[] = {"zip", "-mr", zip, buf, NULL}</code> menjalankan command <code>zip</code>dengan parameter <code>m</code> menghapus folder yang telah di zip dan parameter <code>r</code> (rekursi) agar file dalam folder juga ikut ter-zip dan terhapus setelah di-zip. <code>zip</code>merupakan<code>namafolder.zip</code> dan <code>buf</code> adalah nama folder yang akan di-zip.</br>
- <code>execv("/usr/bin/zip", argv)</code>untuk menjalankan command <code>zip</code></br>

<p></p>
<a id="soal-2-d-e"></a>
<p>d. Karena takut program tersebut lepas kendali, Kiwa ingin program tersebut men-
generate sebuah program "killer" yang siap di run(executable) untuk
menterminasi semua operasi program tersebut. Setelah di run, program yang
menterminasi ini lalu akan mendelete dirinya sendiri.</p>
<p>e. Kiwa menambahkan bahwa program utama bisa dirun dalam dua mode, yaitu
MODE_A dan MODE_B. untuk mengaktifkan MODE_A, program harus dijalankan
dengan argumen -a. Untuk MODE_B, program harus dijalankan dengan argumen
-b. Ketika dijalankan dalam MODE_A, program utama akan langsung
menghentikan semua operasinya ketika program killer dijalankan. Untuk
MODE_B, ketika program killer dijalankan, program utama akan berhenti tapi
membiarkan proses di setiap folder yang masih berjalan sampai selesai(semua
folder terisi gambar, terzip lalu di delete).</p>
</justify>
<p></p>

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

Keterangan : </br>
<p></p> 
- <code>if (argv[1][1] == 'a')</code> jika menjalankan program menggunakan argumen dengan parameter a</br>
- <code>else if (argv[1][1] == 'b')</code> jika menjalankan program menggunakan argumen dengan parameter b</br>
- <code>else if (argc==1 || (argv[1][1] != 'a' && argv[1][1] != 'b'))</code> jika tidak ada argumen yang diinputkan atau argumen yang diinputkan bukan dengan parameter a maupun b</br>
- <code>FILE *killer</code>memberi tau bahwa pointer killer merupakan sebuah file</br>
- <code>killer = fopen("killer.sh", "w")</code> membuat script bash dengan nama <code>killer.sh</code> dengan mode <code>w</code> agar file bisa di-write</br>
- <code>fprintf(killer,"#!/bin/bash\n\n");</code>menulis <code>#!/bin/bash\n\n</code> karena file tersebut merupakan bash script</br>
- untuk mode a : <code>fprintf(killer, "killall %s\n", argv[0])</code>agar program utama langsung
menghentikan semua operasinya ketika program killer dijalankan sedangkan <code>argv[0]</code> untuk mengambil nama program tersebut</br>
- untuk mode b : <code>fprintf(killer,"kill -9 %d\n", (int)get_pid)</code>untuk mengambil pid program utama agar program utama saja yang berhenti sedangkan child processnya masih berjalan <code>(int)get_pid</code> untuk mengambil pid program utama</br>
- <code>pid_t kill = fork()</code> membuat child process yang bernama <code>kill</code></br>
- <code>if (kill == 0)</code> jika child process yang bernama <code>kill</code> berjalan maka <code>char *argv[] = {"chmod", "+x", "killer.sh", NULL}</code> menjalankan command <code>chmod</code> untuk mengganti  izin akses agar file bash <code>killer.sh</code> bisa langsung di eksekusi <code>+x</code></br>
- <code>execv("/bin/chmod", argv)</code>untuk menjalankan command <code>chmod</code></br>

<p></p>
Source Code : [Soal 2](https://github.com/hipzi/SoalShiftSISOP20_Modul2_F13/blob/master/Soal%202/revisirevisi.c)
<a id="soal-3-a"></a>

## SOAL 3
<justify>
1. Jaya adalah seorang programmer handal mahasiswa informatika. Suatu hari dia
memperoleh tugas yang banyak dan berbeda tetapi harus dikerjakan secara bersamaan
(multiprocessing).
<p></p>
a. Program buatan jaya harus bisa membuat dua direktori di “/home/[USER]/modul2/”. Direktori yang pertama diberi nama “indomie”, lalu lima detik kemudian membuat direktori yang kedua bernama “sedaap”.
<p></p>

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

Keterangan : </br>
<p></p> 
- <code>process_7 = fork()</code> membuat child process yang bernama <code>process_7</code></br>
- <code>if(process_7 == 0)</code> jika child process yang bernama <code>process_7</code> berjalan maka <code>char *argv[] = {"mkdir", "-p", "/home/hipzi/modul2/indomie/", NULL}</code> menjalankan command <code>mkdir</code> untuk membuat folder dengan parameter <code>-p</code> untuk menunjukkan path <code>/home/hipzi/modul2/indomie/</code> dimana folder akan dibuat</br>
- <code>sleep(5)</code> agar proses selanjutnya dilakukan setelah menunggu selama 5 detik</br>
- <code> if(process_7 > 0)</code> kondisi bernilai true ketika child process yang bernama <code>process_7</code> telah kembali ke parent process, <code>while ((wait(&status))>0)</code> untuk menunggu dan memastikan bahwa folder indomie telah terbentuk </br>
- <code>process_6 = fork()</code> membuat child process yang bernama <code>process_6</code></br>
- <code>if(process_6 == 0)</code> jika child process yang bernama <code>process_6</code> berjalan maka <code>char *argv[] = {"mkdir", "-p", "/home/hipzi/modul2/sedaap/", NULL}</code> menjalankan command <code>mkdir</code> untuk membuat folder dengan parameter <code>-p</code> untuk menunjukkan path <code>/home/hipzi/modul2/sedaap/</code> dimana folder akan dibuat</br>
- <code>execv("/bin/mkdir", argv)</code>untuk menjalankan command <code>mkdir</code></br>

<p></p>
<a id="soal-3-b"></a>
b. Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori “/home/[USER]/modul2/”. Setelah tugas sebelumnya selesai, ternyata tidak
hanya itu tugasnya.
<p></p>

    if(process_6 > 0){
    while ((wait(&status)) > 0);
        process_5 = fork();
        if(process_5 == 0){
            char *argv[] = {"unzip", "/home/hipzi/modul2/jpg.zip","-d","/home/hipzi/modul2/", NULL};
            execv("/usr/bin/unzip", argv);
        }
    }

Keterangan : </br>
<p></p> 
- <code> if(process_6 > 0)</code> kondisi bernilai true ketika child process yang bernama <code>process_6</code> telah kembali ke parent process, <code>while ((wait(&status))>0)</code> untuk menunggu dan memastikan bahwa proses sebelumnya telah selesai </br>
- <code>process_5 = fork()</code> membuat child process yang bernama <code>process_5</code></br>
- <code>if(process_5 == 0)</code> jika child process yang bernama <code>process_5</code> berjalan maka <code>char *argv[] = {"unzip", "/home/hipzi/modul2/jpg.zip","-d","/home/hipzi/modul2/", NULL}</code> menjalankan command <code>unzip</code> untuk meng-ekstrak file jpg.zip yang berada pada path <code>/home/hipzi/modul2/jpg.zip</code> menggunakan parameter <code>-d</code> untuk menaruh hasil ekstrak-an tersebut pada direktori <code>/home/hipzi/modul2/</code></br>
- <code>execv("/usr/bin/unzip", argv)</code>untuk menjalankan command <code>unzip</code></br>

<a id="soal-3-c"></a>
c. Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di
dalam direktori “home/[USER]/modul2/jpg/”) harus dipindahkan sesuai dengan
pengelompokan, semua file harus dipindahkan ke
“/home/[USER]/modul2/sedaap/” dan semua direktori harus dipindahkan ke
“/home/[USER]/modul2/indomie/”.
<p></p>

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
                char *argv[] = {"find","/home/hipzi/modul2/jpg/", "-type", "d","-mindepth", "1", "-exec", "mv", "-t", "/home/hipzi/modul2/indomie/","{}","+",NULL};
                execv("/usr/bin/find", argv);
            }
    }

<p></p>
Keterangan : </br>
<p></p> 
- <code> if(process_5 > 0)</code> kondisi bernilai true ketika child process yang bernama <code>process_5</code> telah kembali ke parent process, <code>while ((wait(&status))>0)</code> untuk menunggu dan memastikan bahwa proses sebelumnya telah selesai </br>
- <code>process_4 = fork()</code> membuat child process yang bernama <code>process_4</code></br>
- <code>if(process_4 == 0)</code> jika child process yang bernama <code>process_4</code> berjalan maka <code>char *argv[] = {"find", "/home/hipzi/modul2/jpg/", "-type", "f", "-exec", "mv", "-t", "/home/hipzi/modul2/sedaap/","{}","+",NULL}</code> menjalankan command <code>find</code> untuk mencari <code>-type f</code> (file) pada path <code>/home/hipzi/modul2/jpg/</code> <code>-exec</code> untuk mengeksekusi hasil dari find dengan menggunakan command <code>mv</code> menggunakan parameter <code>-t</code> (target, hasil dari command find) dipindahkan ke path <code>/home/hipzi/modul2/sedaap/</code></br>
- <code> if(process_4 > 0)</code> kondisi bernilai true ketika child process yang bernama <code>process_4</code> telah kembali ke parent process, <code>while ((wait(&status))>0)</code> untuk menunggu dan memastikan bahwa proses sebelumnya telah selesai </br>
- <code>process_3 = fork()</code> membuat child process yang bernama <code>process_3</code></br>
- <code>if(process_3 == 0)</code> jika child process yang bernama <code>process_3</code> berjalan maka <code>char *argv[] = {"find","/home/hipzi/modul2/jpg/", "-type", "d","-mindepth", "1", "-exec", "mv", "-t", "/home/hipzi/modul2/indomie/","{}","+",NULL}</code> menjalankan command <code>find</code> untuk mencari <code>-type d</code> (directory) pada path <code>/home/hipzi/modul2/jpg/</code> serta menggunakan <code>-mindepth 1</code> agar direktori “.” dan “..” tidak termasuk.<code>-exec</code> untuk mengeksekusi hasil dari find dengan menggunakan command <code>mv</code> menggunakan parameter <code>-t</code> (target, hasil dari command find) dipindahkan ke path <code>/home/hipzi/modul2/indomie/</code></br>
- <code>execv("/usr/bin/find", argv)</code>untuk menjalankan command <code>find</code></br>
<p></p>
<a id="soal-3-d"></a>
d. Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/”
harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu 3 detik kemudian membuat file bernama “coba2.txt”.
</justify>
<p></p>

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

<p></p>
Keterangan : </br>
<p></p> 
- <code> if(process_3 > 0)</code> kondisi bernilai true ketika child process yang bernama <code>process_3</code> telah kembali ke parent process, <code>while ((wait(&status))>0)</code> untuk menunggu dan memastikan bahwa proses sebelumnya telah selesai </br>
- <code>process_2 = fork()</code> membuat child process yang bernama <code>process_2</code></br>
- <code>if(process_2 == 0)</code> jika child process yang bernama <code>process_2</code> berjalan maka <code> char *argv[] = {"find","/home/hipzi/modul2/indomie/", "-type", "d","-mindepth", "1", "-exec", "touch", "{}/coba1.txt", ";",NULL}</code> menjalankan command <code>find</code> untuk mencari <code>-type d</code> (directory) pada path <code>/home/hipzi/modul2/indomie/</code> serta menggunakan <code>-mindepth 1</code> agar direktori “.” dan “..” tidak termasuk.<code>-exec</code> untuk mengeksekusi hasil dari find dengan menggunakan command <code>touch</code> kemudian membuat file dengan nama <code>{}/coba1.txt</code> </br>
- <code>sleep(3)</code> agar proses selanjutnya dilakukan setelah menunggu selama 3 detik</br>
- <code> if(process_2 > 0)</code> kondisi bernilai true ketika child process yang bernama <code>process_2</code> telah kembali ke parent process, <code>while ((wait(&status))>0)</code> untuk menunggu dan memastikan bahwa proses sebelumnya telah selesai </br>
- <code>process_1 = fork()</code> membuat child process yang bernama <code>process_1</code></br>
- <code>if(process_1 == 0)</code> jika child process yang bernama <code>process_1</code> berjalan maka <code> char *argv[] = {"find","/home/hipzi/modul2/indomie/", "-type", "d","-mindepth", "1", "-exec", "touch", "{}/coba2.txt", ";",NULL}</code> menjalankan command <code>find</code> untuk mencari <code>-type d</code> (directory) pada path <code>/home/hipzi/modul2/indomie/</code> serta menggunakan <code>-mindepth 1</code> agar direktori “.” dan “..” tidak termasuk.<code>-exec</code> untuk mengeksekusi hasil dari find dengan menggunakan command <code>touch</code> kemudian membuat file dengan nama <code>{}/coba2.txt</code> </br>
- <code>execv("/usr/bin/find", argv)</code>untuk menjalankan command <code>find</code></br>
<p></p>
Source Code : [Soal 3](https://github.com/hipzi/SoalShiftSISOP20_Modul2_F13/blob/master/Soal%203/soal3.c)

# Kendala

Minggu ini kondisi kesehatan menurun, jadi dalam mengerjakan soal shift kurang maksimal
