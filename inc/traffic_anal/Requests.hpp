#ifndef TRAFFICANAL_CPP_REQUEST_HPP
#define TRAFFICANAL_CPP_REQUEST_HPP
#include "data_structs.hpp"

namespace traffic_anal {

    class Requests {
        public:
            static std::string get_segment_data(double lat, double lon);

            static FlowSegmentData parse_segment_data(std::string json_str);

            Requests() = delete;
            ~Requests() = delete;
        private:
            static const std::string host;
            static const std::string port;
    };
} //trafic_anal

#endif //TRAFFICANAL_CPP_REQUEST_HPP