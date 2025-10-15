//
// Created by anthony on 13/10/2025.
//

#ifndef TRAFFICANAL_CPP_DATA_STRUCTS_HPP
#define TRAFFICANAL_CPP_DATA_STRUCTS_HPP
#include <string>
#include <vector>
#include <boost/json/conversion.hpp>

namespace json = boost::json;

namespace traffic_anal {

    struct FlowSegmentData {
        std::string frc;
        unsigned int currentSpeed{};
        unsigned int freeFlowSpeed{};
        unsigned int currentTravelTime{};
        unsigned int freeFlowTravelTime{};
        float confidence{};
        bool roadClosure{};
    };


    // Jsonify the FlowSegmentData struct
    inline FlowSegmentData tag_invoke(json::value_to_tag<FlowSegmentData>, const json::value& jv) {
        const auto& obj = jv.as_object();
        FlowSegmentData d;

        d.frc = json::value_to<std::string>(obj.at("frc"));
        d.currentSpeed = json::value_to<unsigned int>(obj.at("currentSpeed"));
        d.freeFlowSpeed = json::value_to<unsigned int>(obj.at("freeFlowSpeed"));
        d.currentTravelTime = json::value_to<unsigned int>(obj.at("currentTravelTime"));
        d.freeFlowTravelTime = json::value_to<unsigned int>(obj.at("freeFlowTravelTime"));
        d.confidence = json::value_to<float>(obj.at("confidence"));
        d.roadClosure = json::value_to<bool>(obj.at("roadClosure"));

        return d;
    }
}

#endif //TRAFFICANAL_CPP_DATA_STRUCTS_HPP
