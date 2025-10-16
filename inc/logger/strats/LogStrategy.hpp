//
// Created by anthony on 28-08-2025.
//

#ifndef LOGGERTESTING_CPP_STRATS_HPP
#define LOGGERTESTING_CPP_STRATS_HPP

#include <iostream>
#include <string>

namespace logger::strats {

    class LogStrategy {

    public:
        virtual ~LogStrategy() = default;

        virtual void log(std::string message) = 0;
    };
} // logger::strats

#endif //LOGGERTESTING_CPP_STRATS_HPP
