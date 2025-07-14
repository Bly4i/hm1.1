#include <iostream>
#include <memory> 

#include "VeryHeavyDatabase.h"
#include "OneShotDB.h"

int main() {
    std::cout << "--- OneShotDB Demonstration ---" << std::endl;

    auto real_db = std::make_unique<VeryHeavyDatabase>();

    auto limit_db = OneShotDB(real_db.release(), 2); 

    std::cout << "Call 1: " << limit_db.GetData("key") << std::endl; 
    std::cout << "Call 2: " << limit_db.GetData("key") << std::endl; 
    std::cout << "Call 3: " << limit_db.GetData("key") << std::endl; 
    std::cout << "Call 4: " << limit_db.GetData("test") << std::endl; 

    std::cout << "\n--- OneShotDB (another test with different key) ---" << std::endl;
    auto real_db_2 = std::make_unique<VeryHeavyDatabase>();
    auto limit_db_2 = OneShotDB(real_db_2.release(), 1);

    std::cout << "Call 1 (test): " << limit_db_2.GetData("test") << std::endl; 
    std::cout << "Call 2 (test): " << limit_db_2.GetData("test") << std::endl; 

    return 0;
}
