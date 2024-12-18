#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to trim leading and trailing spaces from a string
string trim(const string &str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == string::npos || end == string::npos) ? "" : str.substr(start, end - start + 1);
}

// Function to parse the extracted text and process the counts
void processTextFile(const string &filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open the file." << endl;
        return;
    }

    // Map to store counts grouped by Unit #
    map<string, map<string, int>> unitData;

    string line;
    while (getline(inputFile, line)) {
        // Trim leading/trailing spaces from the line
        line = trim(line);
        if (line.empty()) continue; // Skip empty lines
        
        // Split each line by comma
        stringstream ss(line);
        string unitNumber, status;
        
        if (getline(ss, unitNumber, ',') && getline(ss, status)) {
            // Trim spaces from the unit number and status
            unitNumber = trim(unitNumber);
            status = trim(status);

            // Debug: Print parsed unit number and status
            cout << "Unit: " << unitNumber << ", Status: " << status << endl;

            // Standardize status values
            if (status == "Owner On-Site" || status == "owner on-site") status = "Owner On-Site";
            else if (status == "Owner Off-Site" || status == "owner off-site") status = "Owner Off-Site";
            else if (status == "Tenant" || status == "tenant") status = "Tenant";

            // Update the counts
            unitData[unitNumber][status]++;
        }
    }

    // Output the results
    cout << "\nUnit #\tOwner Off-site\tOwner On-site\tTenant" << endl;
    for (const auto &unit : unitData) {
        // Ensure every status is printed even if it's missing by using 0 as a default value
        int ownerOffSite = unit.second.count("Owner Off-Site") > 0 ? unit.second.at("Owner Off-Site") : 0;
        int ownerOnSite = unit.second.count("Owner On-Site") > 0 ? unit.second.at("Owner On-Site") : 0;
        int tenant = unit.second.count("Tenant") > 0 ? unit.second.at("Tenant") : 0;

        cout << unit.first << "\t" 
             << ownerOffSite << "\t\t"
             << ownerOnSite << "\t\t"
             << tenant << endl;
    }

    inputFile.close();
}

int main() {
    // Path to the text file generated from the PDF
    string textFilePath = "cs.txt";

    // Process the file and analyze the data
    processTextFile(textFilePath);

    return 0;
}
