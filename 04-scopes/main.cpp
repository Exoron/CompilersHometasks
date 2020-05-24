#include <iostream>
#include <driver.hh>

int main(int argc, char** argv) {
  Driver driver;

  for (int i = 1; i < argc; ++i) {
    if (argv[i] == std::string("-p")) {
      driver.trace_parsing = true;
    } else if (argv[i] == std::string("-s")) {
      driver.trace_scanning = true;
    } else if(argv[i] == std::string("--print")) {
      std::cout << "Print Tree" << std::endl;
      driver.PrintTree(argv[i + 1]);
      ++i;
    } else {
      driver.parse(argv[i]);
      driver.Run();
      std::cout << std::endl << "Driver result: " << driver.result << std::endl;
    }
  }

  return 0;
}