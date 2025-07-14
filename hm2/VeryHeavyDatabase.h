#ifndef VERYHEAVYDATABASE_H
#define VERYHEAVYDATABASE_H

#include <string>
#include <iostream>
#include <map>

class VeryHeavyDatabase 
{
public:
    std::string GetData(const std::string& key) const {
        std::cout << "Accessing VeryHeavyDatabase for key: " << key << std::endl;
        if (data_.count(key)) {
            return data_.at(key);
        }
        return "Unknown key: " + key;
    }

private:
    std::map<std::string, std::string> data_ = {
        {"key", "value"},
        {"test", "some_data"}
    };
};

#endif // VERYHEAVYDATABASE_H
