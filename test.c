#include "surveil.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

//
// User Data
//////////////////////////////////////////

user users[] = {
  {
    .user_id = 1,
    .when_created = 1415075300,
    .last_activity =  1415075381,
    .name = "Darth Vader",
    .URL_of_avatar = "http://empire.gov/our_team/vader.jpg",
    .num_following = 0,
    .ids_following = NULL,
    .num_blocked = 0,
    .ids_blocked = NULL,
  }, {
    .user_id = 2,
    .when_created = 1415075271,
    .last_activity =  1415075377,
    .name = "Luke Skywalker",
    .URL_of_avatar = "http://xzbreg.onion/luke.jpg",
    .num_following = 0,
    .ids_following = NULL,
    .num_blocked = 0,
    .ids_blocked = NULL,
  }
};
int num_users = ARRAY_SIZE(users);

//
// Piu Data
//////////////////////////////////////////

piu pius[] = {
  {
    .piu_id = 1,
    .piu_id_of_repiu = 0,
    .user_id_of_repiu  = 0,
    .user_id_of_poster = 1,
    .poster = &users[0],
    .piu_text_utf8 = "Luke, I am your father",
    .piu_length = sizeof("Luke, I am your father"),
    .visible_only_to_followers = 1,
  }, {
    .piu_id = 2,
    .piu_id_of_repiu = 0,
    .user_id_of_repiu  = 0,
    .user_id_of_poster = 2,
    .poster = &users[1],
    .piu_text_utf8 = "NOOOOOOOOOOOOOOO",
    .piu_length = sizeof("NOOOOOOOOOOOOOOO"),
    .visible_only_to_followers = 1,
  }
};
int num_pius = ARRAY_SIZE(pius);

//
// Surveillance Data
//////////////////////////////////////////

surveillance_request requests_to_scan[] = {
  {
    .id_number = 1,
    .num_patterns = 1,
    .user_patterns = &users[1],
    .piu_patterns = &pius[1],
    .write_here = NULL,
  }
};
int num_requests = ARRAY_SIZE(requests_to_scan);

//
// Main
/////////////////////////////////////////////

int main(int argc, char **argv) {
  for (int i = 0; i < num_pius; ++i) {
    surveil(&pius[i]);
  }
}

