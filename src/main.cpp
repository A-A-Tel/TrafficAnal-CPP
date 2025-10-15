
#include <iostream>
#include <traffic_anal/requests.hpp>

namespace req = traffic_anal::requests;

int main(int argc, char **argv)
{
    auto [frc,
        currentSpeed,
        freeFlowSpeed,
        currentTravelTime,
        freeFlowTravelTime,
        confidence,
        roadClosure]
            = req::parseSegmentData(req::getSegmentData(40.7603901911296, -73.97380128799641));


    std::cout << frc << std::endl;
    std::cout << currentSpeed << std::endl;
    std::cout << freeFlowSpeed << std::endl;
    std::cout << currentTravelTime << std::endl;
    std::cout << freeFlowTravelTime << std::endl;
    std::cout << confidence << std::endl;
    std::cout << std::boolalpha << roadClosure << std::endl;

    return 0;
}