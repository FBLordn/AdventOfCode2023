#ifndef MACROS_H
#define MACROS_H

#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>

#define OPEN(filePath) std::ifstream file (filePath); \
                        if(!file.is_open()){ \
                            std::cout << "error"; \
                            return;\
                        }

#define TIMER(function, start, end)  start = std::chrono::high_resolution_clock::now();\
                        function();\
                        end = std::chrono::high_resolution_clock::now();\
                        std::cout << "Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;



#endif 