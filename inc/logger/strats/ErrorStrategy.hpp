//
// Created by anthony on 28-08-2025.
//

#ifndef LOGGERTESTING_CPP_ERRORSTRATEGY_HPP
#define LOGGERTESTING_CPP_ERRORSTRATEGY_HPP
#include <logger/strats/ConsoleStrategy.hpp>

namespace logger::strats {
    class ErrorStrategy : public ConsoleStrategy {

    public:
        void log(std::string message) override;
    };
} // logger::strats

#endif //LOGGERTESTING_CPP_ERRORSTRATEGY_HPP
