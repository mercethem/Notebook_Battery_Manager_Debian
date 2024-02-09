#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Directories START
#define DIRECTORY  "/home/asus/battery_saver_asus_ubuntu/path.txt"
#define PASSWORD_DIRECTORY "/home/asus/battery_saver_asus_ubuntu/password.txt"
#define BATTERY_LEVEL_DIRECTORY "/home/asus/battery_saver_asus_ubuntu/battery_end_level.txt"
//Directories Finish

int main() {

    //Change to permission (Writable-Readable-Changeable) power_ folder for BAT
    char *filename_password = PASSWORD_DIRECTORY;
    FILE *file_path_password = fopen(filename_password, "r");
    if (file_path_password == NULL) {
        printf("Error: could not open file %s", filename_password);
    }
    char buffer_password[FILENAME_MAX];
    while (fgets(buffer_password, FILENAME_MAX, file_path_password));
    fclose(file_path_password);
    int password_length = strlen(buffer_password);

    //Command string START
    char command_password_echo[FILENAME_MAX] = "echo ";
    char command_password_rank[FILENAME_MAX] = "";
    char command_password_path[FILENAME_MAX] = " | sudo -S chmod 777 /sys/class/power_supply/BAT*/charge_control_end_threshold";
    //Command string FINISH

    //Concatenation START
    strcpy(command_password_rank, buffer_password);
    strncat(command_password_echo, command_password_rank, password_length - 1);
    strncat(command_password_echo, command_password_path, FILENAME_MAX);
    //Concatenation FINISH

    //System for Terminal
    system(command_password_echo);

    //-------------------------------------------------------------------------------------------------

    //Set battery level
    char *filename_battery_level = BATTERY_LEVEL_DIRECTORY;
    FILE *file_path_battery_level = fopen(filename_battery_level, "r");
    if (file_path_battery_level == NULL) {
        printf("Error: could not open file %s", filename_battery_level);
    }
    char buffer_battery_level[FILENAME_MAX];
    while (fgets(buffer_battery_level, FILENAME_MAX, file_path_battery_level));
    fclose(file_path_battery_level);
    int buffer_battery_level_length = strlen(buffer_battery_level);

    //Command string START
    char command_battery_level_echo[FILENAME_MAX] = "echo ";
    char command_battery_level_rank[FILENAME_MAX] = "";
    char command_battery_level_path[FILENAME_MAX] = " | tee /sys/class/power_supply/BAT*/charge_control_end_threshold";
    //Command string FINISH

    //Concatenation START
    strcpy(command_battery_level_rank, buffer_battery_level);
    strncat(command_battery_level_echo, command_battery_level_rank, buffer_battery_level_length - 1);
    strncat(command_battery_level_echo, command_battery_level_path, FILENAME_MAX);
    //Concatenation FINISH

    //System for Terminal
    system(command_battery_level_echo);

    //-------------------------------------------------------------------------------------------------

    //Change to permission (only-readable) power_ folder for BAT
    char r_command_password_echo[FILENAME_MAX] = "echo ";
    char r_command_password_path[FILENAME_MAX] = " | sudo -S chmod 755 /sys/class/power_supply/BAT*/charge_control_end_threshold";
    strcpy(command_password_rank, buffer_password);
    strncat(r_command_password_echo, command_password_rank, password_length - 1);
    strncat(r_command_password_echo, r_command_password_path, FILENAME_MAX);

    //System for Terminal
    system(r_command_password_echo);

    //-------------------------------------------------------------------------------------------------

    //Change to permission main for bin
    char *filename_usable = PASSWORD_DIRECTORY;
    FILE *file_path_usable = fopen(filename_usable, "r");
    if (file_path_usable == NULL) {
        printf("Error: could not open file %s", filename_usable);
    }
    char buffer_usable[FILENAME_MAX];
    while (fgets(buffer_usable, FILENAME_MAX, file_path_usable));
    fclose(file_path_usable);
    int buffer_usable_length = strlen(buffer_usable);

    //Command string START
    char command_usable_echo[FILENAME_MAX] = "echo ";
    char command_usable_rank[FILENAME_MAX] = "";
    char command_usable_path[FILENAME_MAX] = " | sudo -S chmod 777 /usr/bin";
    //Command string FINISH

    //Concatenation START
    strcpy(command_usable_rank, buffer_usable);
    strncat(command_usable_echo, command_usable_rank, buffer_usable_length - 1);
    strncat(command_usable_echo, command_usable_path, FILENAME_MAX);
    //Concatenation FINISH

    //System for Terminal
    system(command_usable_echo);

    //-------------------------------------------------------------------------------------------------

    //CP main for bin
    char *file_copy_path = DIRECTORY;
    FILE *file_copy = fopen(file_copy_path, "r");
    if (file_copy == NULL) {
        printf("Error: could not open file %s", file_copy_path);
    }
    char buffer_file_copy_level[FILENAME_MAX];
    while (fgets(buffer_file_copy_level, FILENAME_MAX, file_copy));
    fclose(file_copy);
    int buffer_file_copy_length = strlen(buffer_file_copy_level);

    //Command string START
    char command_file_copy_echo[FILENAME_MAX] = "cp ";
    char command_file_copy_rank[FILENAME_MAX] = "";
    char command_file_copy_path[FILENAME_MAX] = "/main /usr/bin";
    //Command string FINISH

    //Concatenation START
    strcpy(command_file_copy_rank, buffer_file_copy_level);
    strncat(command_file_copy_echo, command_file_copy_rank, buffer_file_copy_length - 1);
    strncat(command_file_copy_echo, command_file_copy_path, FILENAME_MAX);
    //Concatenation FINISH

    //System for Terminal
    system(command_file_copy_echo); //System for Terminal

    //-------------------------------------------------------------------------------------------------

    //CP main.config for autostart
    char *file_copy_config_path = DIRECTORY;
    FILE *file_copy_config = fopen(file_copy_config_path, "r");
    if (file_copy_config == NULL) {
        printf("Error: could not open file %s", file_copy_config_path);
    }

    char buffer_file_copy_config_level[FILENAME_MAX];
    while (fgets(buffer_file_copy_config_level, FILENAME_MAX, file_copy_config));
    fclose(file_copy_config);
    int buffer_file_copy_config_length = strlen(buffer_file_copy_config_level);


    //Command string START
    char command_file_copy_config_echo[FILENAME_MAX] = "cp ";
    char command_file_copy_config_rank[FILENAME_MAX] = "";
    char command_file_copy_config_path[FILENAME_MAX] = "/main.desktop /home/asus/.config/autostart"; //kopyalanacak main ve kopyalanacak yer
    //Command string FINISH


    //Concatenation START
    strcpy(command_file_copy_config_rank, buffer_file_copy_config_level);
    strncat(command_file_copy_config_echo, command_file_copy_config_rank, buffer_file_copy_config_length - 1);
    strncat(command_file_copy_config_echo, command_file_copy_config_path, FILENAME_MAX);
    //Concatenation FINISH

    //System for Terminal
    system(command_file_copy_config_echo);

    return 0;
}

