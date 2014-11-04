#pragma once

#include "piu.h"
#include <stdio.h>

typedef struct {
        int id_number;
        int num_patterns;
        user * user_patterns;
        piu * piu_patterns;
        FILE * write_here;
} surveillance_request;

void surveil(piu *entry);

