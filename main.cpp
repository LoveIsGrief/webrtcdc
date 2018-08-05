#include <iostream>
#include "rtcdcpp/PeerConnection.hpp"

int main(){
    std::cout << "Building configuration" << std::endl;

    rtcdcpp::RTCIceServer iceServer = {
        std::string(""),
        0
    };
    auto iceServers = std::vector<rtcdcpp::RTCIceServer>();
    iceServers.push_back(iceServer);
    rtcdcpp::RTCConfiguration config = {
        iceServers
    };

    return 0;
}

