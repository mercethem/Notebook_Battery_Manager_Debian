
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

//    system("echo 2744543@heM | sudo -S chmod 777 /sys/class/power_supply/BAT1/charge_control_end_threshold"); //okunurdan yazılıra geçirir
//    system("echo 60 | tee /sys/class/power_supply/BAT1/charge_control_end_threshold"); //60 yapar
//    system("cp /media/asus/Software/C_Projects/MyProject/battery_saver_asus_ubuntu/main /usr/bin"); //dosyayı kopyalıyor orjinal
//    system("cp /media/asus/Software/C_Projects/MyProject/battery_saver_asus_ubuntu/main.desktop /home/asus/.config/autostart"); //dosyayı kopyalıyor orjinal

    ////Bat için dosya kontrolü kabulü

    char *filename_password = "/media/asus/Software/C_Projects/MyProject/battery_saver_asus_ubuntu/password.txt";
    FILE *file_path_password = fopen(filename_password, "r");
    if (file_path_password == NULL) {
        printf("Error: could not open file %s", filename_password);
    }

    char buffer_password[FILENAME_MAX];

    while (fgets(buffer_password, FILENAME_MAX, file_path_password));

    // close the file
    fclose(file_path_password);
    int password_length = strlen(buffer_password);

    char command_password_echo[FILENAME_MAX] = "echo ";
    char command_password_rank[FILENAME_MAX] = "";
    char command_password_path[FILENAME_MAX] = " | sudo -S chmod 777 /sys/class/power_supply/BAT*/charge_control_end_threshold";

    strcpy(command_password_rank, buffer_password);

    strncat(command_password_echo, command_password_rank, password_length - 1);
    strncat(command_password_echo, command_password_path, FILENAME_MAX);
    system(command_password_echo);

    ////batarya verisini ayarlama

    char *filename_battery_level = "/media/asus/Software/C_Projects/MyProject/battery_saver_asus_ubuntu/battery_end_level.txt";
    FILE *file_path_battery_level = fopen(filename_battery_level, "r");
    if (file_path_battery_level == NULL) {
        printf("Error: could not open file %s", filename_battery_level);
    }

    char buffer_battery_level[FILENAME_MAX];

    while (fgets(buffer_battery_level, FILENAME_MAX, file_path_battery_level));

    // close the file
    fclose(file_path_battery_level);
    int buffer_battery_level_length = strlen(buffer_battery_level);

    char command_battery_level_echo[FILENAME_MAX] = "echo ";
    char command_battery_level_rank[FILENAME_MAX] = "";
    char command_battery_level_path[FILENAME_MAX] = " | tee /sys/class/power_supply/BAT*/charge_control_end_threshold" ;

    strcpy(command_battery_level_rank, buffer_battery_level);

    strncat(command_battery_level_echo, command_battery_level_rank,buffer_battery_level_length - 1);
    strncat(command_battery_level_echo, command_battery_level_path,FILENAME_MAX);
    printf("%s",command_battery_level_echo);
    system(command_battery_level_echo);

//    // dosyayı kullanabilirliğini kaldırır
//
//    char r_command_password_echo[FILENAME_MAX] = "echo ";
//    char r_command_password_path[FILENAME_MAX] = " | sudo -S chmod 755 /sys/class/power_supply/BAT*/charge_control_end_threshold";
//
//    strcpy(command_password_rank, buffer_password);
//
//    strncat(r_command_password_echo, command_password_rank, password_length - 1);
//    strncat(r_command_password_echo, r_command_password_path, FILENAME_MAX);
//    printf("%s", r_command_password_echo);
//    system(r_command_password_echo);

    // dosyayı kullanabilir kılar
    char *filename_usable = "/media/asus/Software/C_Projects/MyProject/battery_saver_asus_ubuntu/password.txt";
    FILE *file_path_usable = fopen(filename_usable, "r");
    if (file_path_usable == NULL) {
        printf("Error: could not open file %s", filename_usable);
    }

    char buffer_usable[FILENAME_MAX];

    while (fgets(buffer_usable, FILENAME_MAX, file_path_usable));

    // close the file
    fclose(file_path_usable);
    int buffer_usable_length = strlen(buffer_usable);

    char command_usable_echo[FILENAME_MAX] = "echo ";
    char command_usable_rank[FILENAME_MAX] = "";
    char command_usable_path[FILENAME_MAX] = " | sudo -S chmod 777 /usr/bin" ;

    strcpy(command_usable_rank, buffer_usable);

    strncat(command_usable_echo, command_usable_rank,buffer_usable_length - 1);
    strncat(command_usable_echo, command_usable_path,FILENAME_MAX);
    printf("%s",command_usable_echo);
    system(command_usable_echo);



    ////dosya kopyalama işlemleri

    char *file_copy_path = "/media/asus/Software/C_Projects/MyProject/battery_saver_asus_ubuntu/path.txt"; //anadosyanın bulunduğu yerin adresi ve kendisinin adı
    FILE *file_copy = fopen(file_copy_path, "r");
    if (file_copy == NULL) {
        printf("Error: could not open file %s", file_copy_path);
    }

    char buffer_file_copy_level[FILENAME_MAX];

    while (fgets(buffer_file_copy_level, FILENAME_MAX, file_copy));

    // close the file
    fclose(file_copy);
    int buffer_file_copy_length = strlen(buffer_file_copy_level);

    char command_file_copy_echo[FILENAME_MAX] = "cp ";
    char command_file_copy_rank[FILENAME_MAX] = "";
    char command_file_copy_path[FILENAME_MAX] = "/main /usr/bin" ; //kopyalanacak main ve kopyalanacak yer

    strcpy(command_file_copy_rank, buffer_file_copy_level);
    strncat(command_file_copy_echo, command_file_copy_rank,buffer_file_copy_length - 1);
    strncat(command_file_copy_echo, command_file_copy_path,FILENAME_MAX);
    printf("%s",command_file_copy_echo);
    system(command_file_copy_echo);




    char *file_copy_config_path = "/media/asus/Software/C_Projects/MyProject/battery_saver_asus_ubuntu/path.txt"; //anadosyanın bulunduğu yerin adresin bulunduğu txt
    FILE *file_copy_config = fopen(file_copy_config_path, "r");
    if (file_copy_config == NULL) {
        printf("Error: could not open file %s", file_copy_config_path);
    }

    char buffer_file_copy_config_level[FILENAME_MAX];

    while (fgets(buffer_file_copy_config_level, FILENAME_MAX, file_copy_config));

    // close the file
    fclose(file_copy_config);
    int buffer_file_copy_config_length = strlen(buffer_file_copy_config_level);

    char command_file_copy_config_echo[FILENAME_MAX] = "cp ";
    char command_file_copy_config_rank[FILENAME_MAX] = "";
    char command_file_copy_config_path[FILENAME_MAX] = "/main.desktop /home/asus/.config/autostart" ; //kopyalanacak main ve kopyalanacak yer

    strcpy(command_file_copy_config_rank, buffer_file_copy_config_level);
    strncat(command_file_copy_config_echo, command_file_copy_config_rank,buffer_file_copy_config_length - 1);
    strncat(command_file_copy_config_echo, command_file_copy_config_path,FILENAME_MAX);
    printf("%s",command_file_copy_config_echo);
    system(command_file_copy_config_echo);


//TODO dosya yollarını ayarlayarak file'den okuyacak şekilde ayarlayıp son rütuşları yap ve tekrar değiştilemez kıl ve free işlemlerini yap

    return 0;
}

