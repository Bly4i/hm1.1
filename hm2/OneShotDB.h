#ifndef ONESHOTDB_H
#define ONESHOTDB_H

#include "VeryHeavyDatabase.h"
#include <string>
#include <map>
#include <memory>

class OneShotDB {
private:
    std::unique_ptr<VeryHeavyDatabase> real_object_;
    size_t shots_remaining_;
    std::map<std::string, size_t> key_shots_remaining_; 

public:
    
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots = 1)
        : real_object_(real_object), shots_remaining_(shots) {
    }

    std::string GetData(const std::string& key) {
        if (shots_remaining_ > 0) {
            shots_remaining_--;
            return real_object_->GetData(key);
        }
        return "error";
    }
};

#endif 
