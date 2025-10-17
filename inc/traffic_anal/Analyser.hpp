#ifndef TRAFFIC_ANAL_ANALYSER_HPP
#define TRAFFIC_ANAL_ANALYSER_HPP

#include <traffic_anal/data_structs.hpp>
#include <traffic_anal/AnalyseStrategy.hpp>

namespace traffic_anal {
    class Analyser {
        public:
            [[nodiscard]] FlowSegmentData get_analysed_data() const;

            Analyser(double lat, double lon, const AnalyseStrategy* strat);

        private:
            const double lon;
            const double lat;
            const AnalyseStrategy *strat;
    };
}

#endif // TRAFFIC_ANAL_ANALYSER_HPP
