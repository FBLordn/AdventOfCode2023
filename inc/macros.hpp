#ifndef MACROS_H
#define MACROS_H

#include <fstream>
#include <iostream>
#include <filesystem>

#define OPEN(filePath) std::ifstream file (filePath); \
                        if(!file.is_open()){ \
                            std::cout << "error"; \
                            return;\
                        }

#endif 