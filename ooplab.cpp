#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Country {
    std::string name;
    std::string capital;
};

int main() {
    std::vector<Country> countries;
    std::string countryFile = "countries.txt";
    std::string capitalFile = "capitals.txt";
    
    //read
    std::ifstream countryInput(countryFile);
    std::ifstream capitalInput(capitalFile);

    if (!countryInput || !capitalInput) {
        std::cerr << "Failed to open input files." << std::endl;
        return 1;
    }

    std::string countryName;
    std::string capitalName;

    while (std::getline(countryInput, countryName) && std::getline(capitalInput, capitalName)) {
        countries.push_back({countryName, capitalName});
    }

    // update
    for (auto& country : countries) {
        std::cout << "Enter new capital for " << country.name << ": ";
        std::getline(std::cin, country.capital);
    }

    // write upd
    std::ofstream countryOutput(countryFile);
    std::ofstream capitalOutput(capitalFile);

    if (!countryOutput || !capitalOutput) {
        std::cerr << "Failed to open output files." << std::endl;
        return 1;
    }

    for (const Country& country : countries) {
        countryOutput << country.name << '\n';
        capitalOutput << country.capital << '\n';
    }

    // count
    int countryCount = countries.size();
    std::cout << "Updated countries and capitals. Total countries: " << countryCount << std::endl;

    return 0;
}
