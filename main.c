
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

    //system("echo 2744543@heM | sudo -S chmod 777 /sys/class/power_supply/BAT1/charge_control_end_threshold"); //okunurdan yazılıra geçirir
    //system("echo 60 | tee /sys/class/power_supply/BAT1/charge_control_end_threshold"); //60 yapar

    char *filename_password = "/media/asus/Software/C_Projects/MyProject/battery_saver_asus_ubuntu/password.txt";
    FILE *file_path_password = fopen(filename_password, "r");
    if (file_path_password == NULL) {
        printf("Error: could not open file %s", filename_password);
        return 1;
    }

    char buffer_password[FILENAME_MAX];

    while (fgets(buffer_password, FILENAME_MAX, file_path_password));

    // close the file
    fclose(file_path_password);
    int password_length = strlen(buffer_password);

    char command_password_echo[FILENAME_MAX] = "echo ";
    char command_password_rank[FILENAME_MAX] = "";
    char command_password_path[FILENAME_MAX] = " | sudo -S chmod 777 /sys/class/power_supply/BAT*/charge_control_end_threshold" ;

    strcpy(command_password_rank, buffer_password);

    strncat(command_password_echo, command_password_rank,password_length - 1);
    strncat(command_password_echo, command_password_path,FILENAME_MAX);
    system(command_password_echo);


    char *filename_battery_level = "/media/asus/Software/C_Projects/MyProject/battery_saver_asus_ubuntu/battery_end_level.txt";
    FILE *file_path_battery_level = fopen(filename_battery_level, "r");
    if (file_path_battery_level == NULL) {
        printf("Error: could not open file %s", filename_battery_level);
        return 1;
    }

    char buffer_battery_level[FILENAME_MAX];

    while (fgets(buffer_battery_level, FILENAME_MAX, file_path_battery_level));

    // close the file
    fclose(file_path_battery_level);
    int buffer_battery_level_length = strlen(buffer_battery_level);

    char command_battery_level_echo[FILENAME_MAX] = "echo ";
    char command_battery_level_rank[FILENAME_MAX] = "";
    char command_battery_level_path[FILENAME_MAX] = " | tee /sys/class/power_supply/BAT*/charge_control_end_threshold" ;
    //char command3[FILENAME_MAX] = " | sudo -S chmod 777 /sys/class/power_supply/BAT1/charge_control_end_threshold" ;

    strcpy(command_battery_level_rank, buffer_battery_level);

    strncat(command_battery_level_echo, command_battery_level_rank,buffer_battery_level_length - 1);
    strncat(command_battery_level_echo, command_battery_level_path,FILENAME_MAX);
    printf("%s",command_battery_level_echo);
    system(command_battery_level_echo);

//    system("gnome-session-properties");


    return 0;
}

