/**
 * @file main.cpp
 * @author Aleksey Vinogradov (aleksey.develop@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-03
 * 
 * Copyright 2025 AVM Research
 * 
 **/
#include <tmaster.h>

using namespace trex;
using namespace trex::tmaster;

int main(int argc, char** argv) {
    try {
        master_process _mp{ argc, argv };
        _mp.run();
    }
    catch(const base::exception_t&) {

    }
    return 0;
} // main