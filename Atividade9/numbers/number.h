#ifndef NUMBER_H
#define NUMBER_H
#include "../Util/util.h"

typedef struct number_st NUMBER;

int get_key(NUMBER *num);
NUMBER *create_item(int num);

#endif //NUMBER_H