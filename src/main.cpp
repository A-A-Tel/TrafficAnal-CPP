/**
@plantumlfile{doc/class.puml}
*/
#include <boost/algorithm/string.hpp>

#include <iostream>
#include <regex>

#include <traffic_anal/Requests.hpp>

namespace anal = traffic_anal;

/**
 * This funciton parses out 2 coordinates from a string using <code>(\-?\d+)(\.\d+)?</code>.
 *
 * @param input The input string of your coordinates
 * @param output The output vector for your coordinates
 * @throws std::invalid_argument if there are more/less than 2 coordinates.
 */
void filter_coords_input(const std::string& input, std::vector<double>& output) {

    const std::regex pattern{R"((\-?\d+)(\.\d+)?)"};

    for (std::sregex_iterator it(input.begin(), input.end(), pattern), end; it != end; ++it) {
        output.push_back(std::strtod(it->str().c_str(), nullptr));
    }

    if (output.size() != 2) throw std::invalid_argument("Too many coordinates.");

}

int main()
{
    std::string input;
    std::cout <<  "Please enter coordinates (lat,lon): ";
    std::getline(std::cin, input);

    std::vector<double> coords;
    filter_coords_input(input, coords);

    // const std::string json = anal::Requests::getSegmentData(coords[0], coords[1]);
    const traffic_anal::FlowSegmentData data = anal::Requests::parseSegmentData("json");

    std::cout << data.currentSpeed << std::endl;

    return 0;
}
