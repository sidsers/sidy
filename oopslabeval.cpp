#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Country {
    std::string name;
    std::string capital;
};

std::vector<Country> readCountriesFromFile(const std::string &filename) {
    std::vector<Country> countries;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Cannot open the file " << filename << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find(',');
        if (pos != std::string::npos) {
            Country country;
            country.name = line.substr(0, pos);
            country.capital = line.substr(pos + 1);
            countries.push_back(country);
        }
    }

    file.close();
    return countries;
}

void updateCountriesInFile(const std::string &filename, const std::vector<Country> &countries) {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Error: Cannot open the file " << filename << " for writing." << std::endl;
        exit(1);
    }

    for (const Country &country : countries) {
        file << country.name << "," << country.capital << "\n";
    }

    file.close();
}

int main() {
    std::string filename = "country.txt;
    std::vector<Country> countries = readCountriesFromFile(filename);

    int choice;
    do {
        std::cout << "1. Update countries and capitals" << std::endl;
        std::cout << "2. Count the number of countries" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string countryName, capitalName;
                std::cout << "Enter country name: ";
                std::cin >> countryName;
                std::cout << "Enter capital name: ";
                std::cin >> capitalName;

                bool updated = false;
                for (Country &country : countries) {
                    if (country.name == countryName) {
                        country.capital = capitalName;
                        updated = true;
                        break;
                    }
                }

                
                if (!updated) {
                    Country newCountry;
                    newCountry.name = countryName;
                    newCountry.capital = capitalName;
                    countries.push_back(newCountry);
                }

                
                updateCountriesInFile(filename, countries);
                std::cout << "Country and capital updated successfully." << std::endl;
                break;
            }
            case 2: {
                std::cout << "Number of countries: " << countries.size() << std::endl;
                break;
            }
            case 3: {
                std::cout << "Exiting program." << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}