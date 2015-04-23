#ifndef READCOMMANDLINE_H_
#define READCOMMANDLINE_H_

#include <iostream>
#include <vector>
#include <boost/program_options.hpp>

std::vector<std::string> readCommandLine(int argc, char** argv);

#endif  /* READCOMMANDLINE_H_ */