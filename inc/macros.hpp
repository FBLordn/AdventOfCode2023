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

#define AVGTIMER(function)  time = 0;\
                        for(int i=0; i<count; i++){\
                        start = std::chrono::high_resolution_clock::now();\
                        function();\
                        end = std::chrono::high_resolution_clock::now();\
                        time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();\
                        }\
                        std::cout << "Time: " << time/count << std::endl;

#endif 