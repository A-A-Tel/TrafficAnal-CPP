//
// Created by anthony on 14/10/2025.
//

#ifndef TRAFFICANAL_CPP_REQUESTMANAGER_HPP
#define TRAFFICANAL_CPP_REQUESTMANAGER_HPP
#include "data_structs.hpp"

namespace traffic_anal {
    class RequestManager {

    public:
        [[nodiscard]] FlowSegmentData getSegmentData(double lat, double lon) const;

    private:
        const std::string host = "api.tomtom.com";
        const std::string port = "80";

        [[nodiscard]] static FlowSegmentData parseSegmentData(const std::string& json_str);
    };
} //trafic_anal

#endif //TRAFFICANAL_CPP_REQUESTMANAGER_HPP