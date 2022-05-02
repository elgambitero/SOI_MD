#ifndef PASSWORD_H
#define PASSWORD_H

SOI_game_status_t PWD_create_game_from_password(char * password);
char * PWD_get_password_from_status(SOI_game_status_t status);

#endif