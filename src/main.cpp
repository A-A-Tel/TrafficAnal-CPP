
#include <iostream>
#include <traffic_anal/RequestManager.hpp>

int main()
{
    const traffic_anal::RequestManager manager = traffic_anal::RequestManager();
    auto [frc, currentSpeed, freeFlowSpeed, currentTravelTime, freeFlowTravelTime, confidence, roadClosure] = manager.getSegmentData(51.84605,5.86274);

    std::cout << frc << std::endl;
    std::cout << currentSpeed << std::endl;
    std::cout << freeFlowSpeed << std::endl;
    std::cout << currentTravelTime << std::endl;
    std::cout << freeFlowTravelTime << std::endl;
    std::cout << confidence << std::endl;
    std::cout << roadClosure << std::endl;

    return 0;
}