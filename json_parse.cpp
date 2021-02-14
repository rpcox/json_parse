/*
 *  json_parse.cpp
 *
 */

#include <cstdio>    // fgets, fopen
#include <cstdlib>   // EXIT_FAILURE, EXIT_SUCCESS, perror
#include <iostream>  // cerr, cout

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#define BUF_SIZE 8192

int main(int argc, char **argv) {
  char buf[BUF_SIZE];
  std::FILE *stream;

  if (argc > 1) {
    stream = std::fopen(argv[1], "r");
    if (!stream) {
      std::perror("fail to open");
      return EXIT_FAILURE;
    }
  }
  else
    stream = stdin;

  auto fail_count = 0;
  auto line_count = 0;

  while (std::fgets(buf, BUF_SIZE, stream) != NULL) {
    line_count++;

    json j;

    try {
      j = json::parse(buf);
    }
    catch (json::parse_error& e) {
      fail_count++;
      std::cerr << '\n' << buf << '\n'
                << "ERROR: " << e.what() << '\n'
                << "line: " << line_count << '\n'
                << "byte position: " << e.byte << std::endl;
    }
  }

  if (fail_count)
    std::cout << '\n';

  std::cout << "objects: " << line_count << '\n'
            << "success: " << line_count - fail_count << '\n'
            << "   fail: " << fail_count << std::endl;

  return EXIT_SUCCESS;
}

