#include "exit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Remove spaces in strings
char *trim(char *str) {
  size_t len = strlen(str);
  size_t charc = 0;

  // Calculate actual character length excluding spaces
  for (size_t i = 0; i < len; i++) {
    if (str[i] != ' ') {
      charc++;
    }
  }

  // Allocate memory for the result string plus null terminator
  char *result = malloc(charc + 1);
  if (!result) {
    tb_exit(TB_FAILURE); // Handle memory allocation failure
  }

  size_t cpos = 0;

  // Copy characters from str to result, skipping spaces
  for (size_t x = 0; x < len; x++) {
    if (str[x] != ' ') {
      result[cpos++] = str[x];
    }
  }

  // Add null terminator
  result[charc] = '\0';

  return result;
}

// Translate a binary string to ascii
char *transb(const char *bstr) {
  char *trimmed_str = trim((char *)bstr);

  size_t len = strlen(trimmed_str);

  // Check if binary string length is a multiple of 8
  if (len % 8 != 0) {
    free(trimmed_str);
    tb_exit(TB_WRONG_STR_LEN);
  }

  size_t charc = len / 8;

  // Allocate enough space for the result string + null terminator
  char *result = malloc(charc + 1);
  if (!result) {
    free(trimmed_str);
    tb_exit(TB_FAILURE); // Handle memory allocation failure
  }

  // Loop through the binary string and process each byte
  for (size_t x = 0; x < charc; x++) {
    char bytes[9] = {0}; // Allocate space for 8 bits + null terminator

    // Extract 8 bits
    strncpy(bytes, trimmed_str + x * 8, 8);

    // Convert the binary byte to a character
    char character = (char)strtol(bytes, NULL, 2);

    // Add character to the result string
    result[x] = character;
  }

  // Null-terminate the result string
  result[charc] = '\0';

  free(trimmed_str); // Free the trimmed string
  return result;
}

// Translate a hexadecimal string to ascii
char *transx(char *xstr) {
  char *str = trim(xstr); // Trim the input string

  size_t len = strlen(str);

  // Check if hexadecimal string length is a multiple of 2
  if (len % 2 != 0) {
    free(str);
    tb_exit(TB_WRONG_STR_LEN);
  }

  size_t charc = len / 2;

  // Allocate enough space for the result string + null terminator
  char *result = malloc(charc + 1);
  if (!result) {
    free(str);
    tb_exit(TB_FAILURE); // Handle memory allocation failure
  }

  // Loop through the hexadecimal string and process each byte
  for (size_t x = 0; x < charc; x++) {
    char bytes[3] = {0}; // Allocate space for 2 hex digits + null terminator

    // Extract 2 hex digits
    strncpy(bytes, str + x * 2, 2);

    // Convert the hex byte to a character
    char character = (char)strtol(bytes, NULL, 16);

    // Add character to the result string
    result[x] = character;
  }

  // Null-terminate the result string
  result[charc] = '\0';

  free(str); // Free the trimmed string
  return result;
}
