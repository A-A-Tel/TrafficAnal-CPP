//
// Created by anthony on 14/10/2025.
//

#include <traffic_anal/requests.hpp>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

#include <boost/asio/ip/tcp.hpp>

#include <boost/json.hpp>


#include <iostream>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace json = boost::json;
using tcp = net::ip::tcp;

namespace traffic_anal::requests {
    std::string getSegmentData(double lat, double lon) {

        std::string response;

        try
        {
            // Ignore error, CLion bugged
            const std::string target = std::format(
                "/traffic/services/4/flowSegmentData/absolute/10/json?key={}&point={},{}",
                std::getenv("TOMTOM_TOKEN") ? std::getenv("TOMTOM_TOKEN") : "",
                lat,
                lon
            );
            int version = 11;

            // Boilerplate
            net::io_context ioc;
            tcp::resolver resolver(ioc);
            beast::tcp_stream stream(ioc);


            // Resolve and connect
            net::ip::basic_resolver_results<tcp> const results = resolver.resolve(host, port);
            stream.connect(results);

            // Build request
            http::request<http::string_body> req{http::verb::get, target, version};
            req.set(http::field::host, host);
            req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

            // Send
            http::write(stream, req);

            beast::flat_buffer buffer;
            http::response<http::dynamic_body> res;
            http::read(stream, buffer, res);

            response = beast::buffers_to_string(res.body().cdata());

            // Disconnect
            beast::error_code error;
            stream.socket().shutdown(tcp::socket::shutdown_both, error);

            if(error && error != beast::errc::not_connected)
                throw beast::system_error(error);

        }
        catch(std::exception const& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return "{}"; // Fallback
        }

        return response;
    }

    FlowSegmentData parseSegmentData(const std::string &json_str) {

        // Test data
        // json_str = R"({"flowSegmentData":{"frc":"FRC1","currentSpeed":25,"freeFlowSpeed":25,"currentTravelTime":59,"freeFlowTravelTime":59,"confidence":1,"roadClosure":false,"coordinates":{"coordinate":[{"latitude":51.842671952025697,"longitude":5.866043378102120},{"latitude":51.842611622086366,"longitude":5.865791250454691},{"latitude":51.842564652712788,"longitude":5.865612883555173},{"latitude":51.842331306895552,"longitude":5.864658017145615},{"latitude":51.842174395912245,"longitude":5.863948572861034},{"latitude":51.842073827595044,"longitude":5.863240469680932},{"latitude":51.842038975597490,"longitude":5.862905193553985},{"latitude":51.842004071786867,"longitude":5.862301696525464},{"latitude":51.841994698503697,"longitude":5.862083096490721},{"latitude":51.841990659187758,"longitude":5.861971784816575},{"latitude":51.841998737819374,"longitude":5.861462165103603},{"latitude":51.842017484381984,"longitude":5.861065198169342},{"latitude":51.842038975597490,"longitude":5.860847939239079},{"latitude":51.842060415016697,"longitude":5.860666890130545},{"latitude":51.842104692045829,"longitude":5.860433537946165},{"latitude":51.842160983363840,"longitude":5.860193480239303}]},"@version":"4"}})";

        try {
            const json::value jv = json::parse(json_str);

            // Extract the flowSegmentData object from the root
            const json::object &obj = jv.as_object();
            const json::value &flow_data = obj.at("flowSegmentData");

            return json::value_to<FlowSegmentData>(flow_data);
        }
        catch (const std::exception& e) {
            std::cerr << "Error parsing JSON: " << e.what() << std::endl;
            return FlowSegmentData{};  // Fallback
        }
    }
} //traffic_anal
