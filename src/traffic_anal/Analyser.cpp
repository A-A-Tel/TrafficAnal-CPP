#include <traffic_anal/Analyser.hpp>

namespace traffic_anal {

    Analyser::Analyser(const double lat, const double lon) : lon(lon), lat(lat) {}

    FlowSegmentData Analyser::analyse(
        std::chrono::time_point<std::chrono::utc_clock> start,
        std::chrono::time_point<std::chrono::utc_clock> end
        ) const {

        return {};
    }
}
