#include <traffic_anal/data_structs.hpp>

#include <iostream>
#include <regex>

#include <boost/json.hpp>

int main()
{

    const std::string json_str = R"({"frc": "FRC3","currentSpeed": 35,"freeFlowSpeed": 43,"currentTravelTime": 354,"freeFlowTravelTime": 288,"confidence": 1,"roadClosure": false,"datetime": {"date": "30/10/25","time": "15:06:13","epoch": 1761833173715}})";
    const json::value obj = json::parse(json_str);
    const traffic_anal::FlowSegmentData data = json::value_to<traffic_anal::FlowSegmentData>(obj);


    std::cout << data.datetime.time << std::endl;

    return 0;
}
