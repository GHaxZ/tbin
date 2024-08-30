#include "argparse.h"
#include "exit.h"
#include "translate.h"
#include <getopt.h>
#include <stdio.h>

static struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {"binary", required_argument, 0, 'b'},
    {"hex", required_argument, 0, 'x'},
    {0, 0, 0, 0} // Terminate the array with a zero-filled entry
};

void parseargs(int argc, char *argv[]) {
  if (argc < 2) {
    tb_exit(TB_MISSING_ARGS);
  }

  int opt;
  int opt_index;

  while ((opt = getopt_long(argc, argv, "hb:x:", long_options, &opt_index)) !=
         -1) {
    switch (opt) {
    case 'h':
      usage(argc, argv);
      tb_exit(TB_SUCCESS);
    case 'b':
      printf("%s\n", transb(optarg));
      tb_exit(TB_SUCCESS);
    case 'x':
      printf("Translate from hex: %s\n", optarg);
      tb_exit(TB_SUCCESS);
    default:
      tb_exit(TB_MALFORMED_ARGS);
    }
  }
}

void usage(int argc, char *argv[]) {
  printf("Usage for %s"
         "\n\t[-h | --help] Show this usage hint"
         "\n\t[-b | --binary] Translate a binary string"
         "\n\t\t Length must be multiple of 8"
         "\n\t[-x | --hex] Translate a hex string"
         "\n",
         argv[0]);
}
