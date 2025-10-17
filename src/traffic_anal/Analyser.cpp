#include <traffic_anal/Analyser.hpp>

namespace traffic_anal {

    FlowSegmentData Analyser::get_analysed_data() const {
        return strat->analyse(lat, lon);
    }

    Analyser::Analyser(const double lat, const double lon, const AnalyseStrategy* strat) : lon(lon), lat(lat), strat(strat) {}
}
