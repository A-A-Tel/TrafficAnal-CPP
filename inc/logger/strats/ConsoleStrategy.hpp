//
// Created by anthony on 28-08-2025.
//

#ifndef LOGGERTESTING_CPP_CONSOLESTRATEGY_HPP
#define LOGGERTESTING_CPP_CONSOLESTRATEGY_HPP
#include <logger/strats/LogStrategy.hpp>

namespace logger::strats {
    class ConsoleStrategy : public LogStrategy {
    public:
        void log(std::string message) override;
    };
} // logger::strats

#endif //LOGGERTESTING_CPP_CONSOLESTRATEGY_HPP
