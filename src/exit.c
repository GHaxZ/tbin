#include "exit.h"
#include <stdio.h>
#include <stdlib.h>

void tb_exit(int code) {
  switch (code) {
  case TB_SUCCESS:
    exit(TB_SUCCESS);
  case TB_FAILURE:
    printf("The programs execution has failed (%i)\n", TB_FAILURE);
    exit(TB_FAILURE);
  case TB_MISSING_ARGS:
    printf("Missing arguments, use '--help' for usage hint (%i)\n",
           TB_MISSING_ARGS);
    exit(TB_MISSING_ARGS);
  case TB_MALFORMED_ARGS:
    printf("Malformed arguments, use '--help' for usage hint (%i)\n",
           TB_MALFORMED_ARGS);
    exit(TB_MALFORMED_ARGS);
  case TB_WRONG_STR_LEN:
    printf("The string provided for translation does not have the correct "
           "length. Use '--help' for the expected length (%i)\n",
           TB_WRONG_STR_LEN);
    exit(TB_WRONG_STR_LEN);
  }
}
