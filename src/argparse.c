#include "argparse.h"
#include "exit.h"
#include "translate.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

static struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {"binary", required_argument, 0, 'b'},
    {"hex", required_argument, 0, 'x'},
    {"decimal", required_argument, 0, 'd'},
    {0, 0, 0, 0} // Terminate the array with a zero-filled entry
};

void parseargs(int argc, char *argv[]) {
  if (argc < 2) {
    tb_exit(TB_MISSING_ARGS);
  }

  int opt;
  int opt_index;

  while ((opt = getopt_long(argc, argv, "hb:x:d:", long_options, &opt_index)) !=
         -1) {
    switch (opt) {
    case 'h':
      usage(argc, argv);
      tb_exit(TB_SUCCESS);
    case 'b':
      outres(transb(optarg));
      tb_exit(TB_SUCCESS);
    case 'x':
      outres(transx(optarg));
      tb_exit(TB_SUCCESS);
    case 'd':
      printf("Translate decimal");
    default:
      tb_exit(TB_MALFORMED_ARGS);
    }
  }
}

void outres(char *res) {
  printf("%s\n", res);
  free(res);
}

void usage(int argc, char *argv[]) {
  printf(
      "Usage for %s"
      "\n\t[-h | --help] Show this usage hint"
      "\n\t[-b \"<string>\" | --binary \"<string>\"] Translate a binary string"
      "\n\t\t String length must be multiple of 8"
      "\n\t[-x \"<string>\" | --hex \"<string>\"] Translate a hex string"
      "\n\t\t String length must be multiple of 2"
      "\n",
      argv[0]);
}
