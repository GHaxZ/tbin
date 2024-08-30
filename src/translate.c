#include "exit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *transb(const char *bstr) {

  size_t len = strlen(bstr);

  // Estimate character count by considering spaces
  size_t charc = 0;
  for (size_t i = 0; i < len; i++) {
    if (bstr[i] != ' ') {
      charc++;
    }
  }

  // Check if binary string length is a multiple of 8
  if (charc % 8 != 0) {
    tb_exit(TB_WRONG_STR_LEN);
  }

  charc = charc / 8;

  // Allocate enough space for the result string + null terminator
  char *result = malloc(charc + 1);
  if (!result) {
    tb_exit(TB_FAILURE); // Handle memory allocation failure
  }

  // Loop through the binary string and process each byte
  for (size_t x = 0, byteIndex = 0; x < charc; x++, byteIndex += 9) {
    // Allocate space for 8 bits + null terminator
    char bytes[9] = {0};
    size_t bitPos = 0;

    // Extract 8 bits and skip spaces
    while (bitPos < 8) {
      if (*bstr != ' ') {
        bytes[bitPos++] = *bstr;
      }
      bstr++;
    }

    // Convert the binary byte to a character
    char character = (char)strtol(bytes, NULL, 2);

    // Add character to the result string
    result[x] = character;
  }

  // Null-terminate the result string
  result[charc] = '\0';

  return result;
}

char *transx(char *xstr) { return ""; }
