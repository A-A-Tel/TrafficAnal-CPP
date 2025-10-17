//
// Created by anthony on 13/10/2025.
//

#ifndef TRAFFICANAL_CPP_DATA_STRUCTS_HPP
#define TRAFFICANAL_CPP_DATA_STRUCTS_HPP
#include <iostream>
#include <string>
#include <boost/json/conversion.hpp>

namespace json = boost::json;


/**
 * The main namespace for the project.
 */
namespace traffic_anal {

    /**
     * Enum indicating if parsing was successful.
     */
    enum struct Status {

        /**
         * Parsing was successful and the struct is guaranteed to be valid.
         */
        VALID,

        /**
         * Parsing failed entirely.
         */
        INVALID,

        /**
         * Parsing (partially) failed. struct may contain some data.
         */
        UNKNOWN
    };

    /**
     * JSON representation from TomTom's API response.
     */
    struct FlowSegmentData {

        /**
         * Indication for if the parsing was successful. May contain partial data when @ref traffic_anal::Status::UNKNOWN
         */
        Status status{Status::UNKNOWN};

        /**
         * Functional Road Class. This indicates the road type:
         * - FRC0: Freeway, freeway or other major road.
         * - FRC1: Major road, less important than a freeway.
         * - FRC2: Other major road.
         * - FRC3: Secondary road.
         * - FRC4: Local connecting road.
         * - FRC5: Local road of high importance.
         * - FRC6: Local road
         */
        std::string frc{};

        /**
         * The current average speed at the selected point, in the unit requested.
         * This is calculated from the currentTravelTime and the length of the selected segment.
         */
        uint16_t currentSpeed{};

        /**
         * The free flow speed expected under ideal conditions, expressed in the unit requested.
         * This is related to the freeFlowTravelTime.
         */
        uint16_t freeFlowSpeed{};

        /**
         * Current travel time in seconds based on fused real-time measurements between the defined locations in the specified direction.
         */
        uint16_t currentTravelTime{};

        /**
         * The travel time in seconds which would be expected under ideal free flow conditions.
         */
        uint16_t freeFlowTravelTime{};

        /**
         * The confidence is a measure of the quality of the provided travel time and speed.
         * A value ranges between 0 and 1.0 where 1.0 means full confidence,
         * meaning that the response contains the highest quality data.
         * Lower values indicate the degree that the response may vary from the actual conditions on the road.
         */
        float_t confidence{};

        /**
         * This indicates if the road is closed to traffic or not.
         */
        bool roadClosure{};
    };

    // Jsonify the FlowSegmentData struct
    inline FlowSegmentData tag_invoke(json::value_to_tag<FlowSegmentData>, const json::value& jv) {
        const auto& obj = jv.as_object();
        FlowSegmentData data;

        try {
            data.frc = json::value_to<std::string>(obj.at("frc"));
            data.currentSpeed = json::value_to<uint16_t>(obj.at("currentSpeed"));
            data.freeFlowSpeed = json::value_to<uint16_t>(obj.at("freeFlowSpeed"));
            data.currentTravelTime = json::value_to<uint16_t>(obj.at("currentTravelTime"));
            data.freeFlowTravelTime = json::value_to<uint16_t>(obj.at("freeFlowTravelTime"));
            data.confidence = json::value_to<float_t>(obj.at("confidence"));
            data.roadClosure = json::value_to<bool>(obj.at("roadClosure"));
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return data;
        }
        data.status = Status::VALID;
        return data;
    }
}

#endif //TRAFFICANAL_CPP_DATA_STRUCTS_HPP
