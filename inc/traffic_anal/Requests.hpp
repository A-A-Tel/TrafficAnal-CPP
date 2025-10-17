#ifndef TRAFFICANAL_CPP_REQUEST_HPP
#define TRAFFICANAL_CPP_REQUEST_HPP
#include "data_structs.hpp"


const static std::string host = "api.tomtom.com";
const static std::string port = "80";

namespace traffic_anal {

    class Requests {
        public:
            static std::string get_segment_data(double lat, double lon);

            static FlowSegmentData parse_segment_data(std::string json_str);

        Requests() = delete;
        virtual ~Requests();
    };
} //trafic_anal

#endif //TRAFFICANAL_CPP_REQUEST_HPP