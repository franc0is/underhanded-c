#pragma once

#include <time.h>

typedef struct user_struct {
        int user_id;
        time_t when_created;
        time_t last_activity;
        char * name;
        char * URL_of_avatar;

        int num_following, * ids_following;
        int num_blocked, * ids_blocked;
} user;

typedef struct piu_struct {
        int piu_id;
        int piu_id_of_repiu, user_id_of_repiu;    /* zero if not a re-Piu */

        int user_id_of_poster;
        user * poster;

        char piu_text_utf8[140*4+1];
        unsigned char piu_length;   /* UTF8 characters, not bytes */
        unsigned char visible_only_to_followers;
} piu;

