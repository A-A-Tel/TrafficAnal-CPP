#ifndef TRAFFIC_ANAL_ANALYSER_HPP
#define TRAFFIC_ANAL_ANALYSER_HPP

#include <chrono>
#include <traffic_anal/data_structs.hpp>

namespace traffic_anal {
    class Analyser {
        public:
        virtual ~Analyser() = default;

        virtual FlowSegmentData analyse(
            std::chrono::time_point<std::chrono::utc_clock> start,
            std::chrono::time_point<std::chrono::utc_clock> end,
            std::string dataset)
        const;

    protected:

        Analyser() = default;
    };
}

#endif // TRAFFIC_ANAL_ANALYSER_HPP
