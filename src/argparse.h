#ifndef ARGPARSE_H
#define ARGPARSE_H

// Parse commandline arguments and run corresponding code
void parseargs(int argc, char *argv[]);

// Output the result of a conversion
void outres(char *res);

// Print the usage hint
void usage(int argc, char *argv[]);

#endif // !ARGPARSE_H
