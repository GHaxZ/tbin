#ifndef EXIT_H
#define EXIT_H

void tb_exit(int code);

#define TB_SUCCESS 0
#define TB_FAILURE 1
#define TB_MISSING_ARGS 2
#define TB_MALFORMED_ARGS 3
#define TB_WRONG_STR_LEN 4

#endif // !EXIT_H
