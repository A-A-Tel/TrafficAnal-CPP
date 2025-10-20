#ifndef TRAFFIC_ANAL_ANALYSER_HPP
#define TRAFFIC_ANAL_ANALYSER_HPP

#include <chrono>
#include <traffic_anal/data_structs.hpp>

namespace traffic_anal {
    class Analyser {
        public:
        Analyser(double lat, double lon);
        virtual ~Analyser() = default;

        [[nodiscard]] virtual FlowSegmentData analyse(std::chrono::time_point<std::chrono::utc_clock> start, std::chrono::time_point<std::chrono::utc_clock> end) const;

    private:
            const double lon;
            const double lat;
    };
}

#endif // TRAFFIC_ANAL_ANALYSER_HPP
