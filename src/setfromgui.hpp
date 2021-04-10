#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <nlohmann/json.hpp>

namespace setfromgui {

class ReadJson {

public:
    nlohmann::json json;
    bool debug;
    ReadJson(bool debug) : debug(debug) {
        if (debug) {
            std::ifstream ifs("../sfg-config.json");
            ifs >> json;
        } else {
            std::string home = std::getenv("HOME");
            std::ifstream ifs(home + "/.config/SetFromGUI/sfg-config.json");
            ifs >> json;
        }
    }

    void change_status(int number, bool status) {
        json["list"]["toggle"][number]["status"] = status;
        write_config();
        write_setting();
    }

    void change_colorscheme(std::string colorscheme) {
        json["list"]["other"]["colorscheme"]["current"] = colorscheme;
        write_config();
        write_setting();
    }

    void write_config() {
        std::ofstream config;
        if (!debug) {
            std::string home = std::getenv("HOME");
            config.open(home + "/.config/SetFromGUI/config.vim", std::ios::trunc);
        }
        for (const auto& [_, v] : json["list"]["toggle"].items()) {
            if  (debug) {
                if (v["status"]) {
                    std::cout << v["command"][0].get<std::string>() << std::endl;
                } else {
                    std::cout << v["command"][1].get<std::string>() << std::endl;
                }
            } else {
                if (v["status"]) {
                    config << v["command"][0].get<std::string>() << std::endl;
                } else {
                    config << v["command"][1].get<std::string>() << std::endl;
                }
            }
        }
        std::string current = json["list"]["other"]["colorscheme"]["current"];
        (debug ? std::cout : config) << "colorscheme " + current << std::endl;
    }

    void write_setting() {
        if (debug) {
            std::ofstream setting("../sfg-config.json");
            setting << std::setw(4) << json;
        } else {
            std::string home = std::getenv("HOME");
            std::ofstream setting(home + "/.sfg-config/SetFromGUI/settings.json");
            setting << std::setw(4) << json;
        }
    }
};

} // setFromGUI
