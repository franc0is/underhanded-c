#include "surveil.h"
#include <string.h>

extern int num_requests;
extern surveillance_request * requests_to_scan;

static unsigned char text_matches(piu *e, piu *pp) {
  return (strstr(pp->piu_text_utf8, e->piu_text_utf8) != NULL);
}

static unsigned char ids_block_matches(int *e_block, int *p_block) {
  int e_size = *e_block++, p_size = *p_block++;
  if (e_size != p_size) return 0;

  for (int i = 0; i < e_size; ++i) {
    if (e_block[i] != p_block[i]) {
      return 0;
    }
  }

  return 1;
}

static unsigned char piu_matches(piu *e, piu *pp) {
  int *e_ptr = (int *)e, *pp_ptr = (int *)pp;
  for (int i = 0; i < sizeof(piu) / sizeof(int); ++i) {
    if (!pp_ptr[i]) continue;
    if (pp_ptr[i] != e_ptr[i]) return 0;
  }

  return 1;
}

static unsigned char pattern_matches(piu *e, user *up, piu *pp) {
  return (text_matches(e, pp) &&
      ids_block_matches(&e->poster->num_following, &up->num_following) &&
      ids_block_matches(&e->poster->num_blocked, &up->num_blocked) &&
      piu_matches(e, pp));
}

void surveil(piu *entry) {
  for (int i = 0; i < num_requests; ++i) {
    surveillance_request *request = &requests_to_scan[i];
    for (int j = 0; j < request->num_patterns; ++j) {
      if (pattern_matches(entry, &request->user_patterns[j], &request->piu_patterns[j])) {
        printf("Pattern Matches!\n");
      }
    }
  }
}

