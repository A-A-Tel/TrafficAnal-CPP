//
// Created by anthony on 13/10/2025.
//

#ifndef TRAFFICANAL_CPP_DATA_STRUCTS_HPP
#define TRAFFICANAL_CPP_DATA_STRUCTS_HPP
#include <string>
#include <boost/json/conversion.hpp>

namespace json = boost::json;

namespace traffic_anal {

    /**
     * Struct representation of a JSON response from TomTom.
     */
    struct FlowSegmentData {

        /**
         * Road class
         */
        std::string frc;

        /**
         * Live flow speed
         */
        uint16_t currentSpeed{};

        /**
         * Test.
         */
        uint16_t freeFlowSpeed{};
        /**
         * Test.
         */
        uint16_t currentTravelTime{};
        /**
         * Test.
         */
        uint16_t freeFlowTravelTime{};
        /**
         * Test.
         */
        float_t confidence{};
        /**
         * Test.
         */
        bool roadClosure{};
    };


    // Jsonify the FlowSegmentData struct
    inline FlowSegmentData tag_invoke(json::value_to_tag<FlowSegmentData>, const json::value& jv) {
        const auto& obj = jv.as_object();
        FlowSegmentData data;

        data.frc = json::value_to<std::string>(obj.at("frc"));
        data.currentSpeed = json::value_to<uint16_t>(obj.at("currentSpeed"));
        data.freeFlowSpeed = json::value_to<uint16_t>(obj.at("freeFlowSpeed"));
        data.currentTravelTime = json::value_to<uint16_t>(obj.at("currentTravelTime"));
        data.freeFlowTravelTime = json::value_to<uint16_t>(obj.at("freeFlowTravelTime"));
        data.confidence = json::value_to<float_t>(obj.at("confidence"));
        data.roadClosure = json::value_to<bool>(obj.at("roadClosure"));

        return data;
    }
}

#endif //TRAFFICANAL_CPP_DATA_STRUCTS_HPP
