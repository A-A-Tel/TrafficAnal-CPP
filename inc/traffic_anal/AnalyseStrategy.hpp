//
// Created by anthony on 17/10/2025.
//

#ifndef TRAFFICANAL_CPP_ANALYSE_STRATEGY_HPP
#define TRAFFICANAL_CPP_ANALYSE_STRATEGY_HPP
#include "data_structs.hpp"

namespace traffic_anal {

    class AnalyseStrategy {
        public:
        virtual ~AnalyseStrategy() = default;

        virtual FlowSegmentData analyse(double lat, double lon) const;
    };
} //traffic_anal

#endif //TRAFFICANAL_CPP_ANALYSE_STRATEGY_HPP