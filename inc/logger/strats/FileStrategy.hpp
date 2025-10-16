//
// Created by anthony on 28-08-2025.
//

#ifndef LOGGERTESTING_CPP_FILESTRATEGY_HPP
#define LOGGERTESTING_CPP_FILESTRATEGY_HPP

#include <fstream>

#include <logger/strats/LogStrategy.hpp>

namespace logger::strats {
    class FileStrategy : public LogStrategy {

    public:
        FileStrategy();
        void log(std::string message) override;
    private:
        std::ofstream log_file;
    };
} // logger::strats

#endif //LOGGERTESTING_CPP_FILESTRATEGY_HPP
