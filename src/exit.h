#ifndef EXIT_H
#define EXIT_H

// Exit with a specific code and print explanation
void tb_exit(int code);

// Program was successful
#define TB_SUCCESS 0

// Program failed
#define TB_FAILURE 1

// User didn't supply necessary arguments
#define TB_MISSING_ARGS 2

// User arguments were wrong
#define TB_MALFORMED_ARGS 3

// Translation string length was wrong
#define TB_WRONG_STR_LEN 4

#endif // !EXIT_H
