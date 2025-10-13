//
// Created by anthony on 13/10/2025.
//

#ifndef TRAFFICANAL_CPP_DATA_STRUCTS_HPP
#define TRAFFICANAL_CPP_DATA_STRUCTS_HPP
#include <string>
#include <vector>

struct coord {

    double latitude;
    double longitude;

};

struct FlowSegmentData {

    std::string xmlns;
    std::string version;
    std::string frc;

    unsigned int currentSpeed;
    unsigned int freeFlowSpeed;
    unsigned int currentTravelTime;
    unsigned int freeFlowTravelTime;

    float confidence;

    bool roadClosure;

    struct {

        std::vector<coord> coordinate;

    } coordinates;

};

typedef struct {} IncidentData;

#endif //TRAFFICANAL_CPP_DATA_STRUCTS_HPP
