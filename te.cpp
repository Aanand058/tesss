// // #include <iostream>
// // #include <fstream>
// // #include <map>
// // #include <string>
// // #include <sstream>

// // using namespace std;

// // int main() {
// //     // Open the file containing the data
// //     ifstream file("sample.txt");

// //     // Check if the file was opened successfully
// //     if (!file.is_open()) {
// //         cerr << "Error opening file!" << endl;
// //         return 1;
// //     }

// //     // Create a map to store the count of each Occupancy Type for each unit
// //     map<int, map<string, int>> unitOccupancyCount;

// //     string line;
// //     while (getline(file, line)) {
// //         stringstream ss(line);
// //         string unitStr, occupancy;

// //         // Read the unit and occupancy type from the line
// //         getline(ss, unitStr, ',');
// //         getline(ss, occupancy);

// //         // Convert unit to an integer
// //         int unit = stoi(unitStr);

// //         // Increment the count for the given unit and occupancy type
// //         unitOccupancyCount[unit][occupancy]++;
// //     }

// //     // Close the file
// //     file.close();

// //     // Print the results
// //     for (const auto& unit : unitOccupancyCount) {
// //         cout << "Unit " << unit.first << ":\n";
// //         for (const auto& occupancy : unit.second) {
// //             cout << "  " << occupancy.first << ": " << occupancy.second << endl;
// //         }
// //     }

// //     return 0;
// // }





// #include <iostream>
// #include <fstream>
// #include <map>
// #include <string>
// #include <sstream>
// #include <iomanip>

// using namespace std;

// int main() {
//     // Open the file containing the data
//     ifstream file("sample.txt");

//     // Check if the file was opened successfully
//     if (!file.is_open()) {
//         cerr << "Error opening file!" << endl;
//         return 1;
//     }

//     // Create a map to store the count of each Occupancy Type for each unit
//     map<int, map<string, int>> unitOccupancyCount;

//     string line;
//     while (getline(file, line)) {
//         stringstream ss(line);
//         string unitStr, occupancy;

//         // Read the unit and occupancy type from the line
//         getline(ss, unitStr, ',');
//         getline(ss, occupancy);

//         // Convert unit to an integer
//         int unit = stoi(unitStr);

//         // Increment the count for the given unit and occupancy type
//         unitOccupancyCount[unit][occupancy]++;
//     }

//     // Close the file
//     file.close();

//     // Print the header of the table
//     cout << left << setw(10) << "Unit" << setw(20) << "Owner On-Site" << setw(20) << "Owner Off-Site" << setw(20) << "Tenant" << endl;
//     cout << "-----------------------------------------------------------" << endl;

//     // Print the results
//     for (const auto& unit : unitOccupancyCount) {
//         // Get the counts for each occupancy type, default to 0 if not found
//         int ownerOnSite = unit.second.count("Owner On-Site") ? unit.second.at("Owner On-Site") : 0;
//         int ownerOffSite = unit.second.count("Owner Off-Site") ? unit.second.at("Owner Off-Site") : 0;
//         int tenant = unit.second.count("Tenant") ? unit.second.at("Tenant") : 0;

//         // Output in a table format
//         cout << left << setw(10) << unit.first 
//              << setw(20) << ownerOnSite 
//              << setw(20) << ownerOffSite 
//              << setw(20) << tenant << endl;
//     }

//     return 0;
// }






// #include <iostream>
// #include <fstream>
// #include <map>
// #include <string>
// #include <sstream>
// #include <iomanip>

// using namespace std;

// int main() {
//     // Open the file containing the data
//     ifstream file("sample.txt");

//     // Check if the file was opened successfully
//     if (!file.is_open()) {
//         cerr << "Error opening file!" << endl;
//         return 1;
//     }

//     // Create a map to store the count of each Occupancy Type for each unit
//     map<int, map<string, int>> unitOccupancyCount;

//     string line;
//     while (getline(file, line)) {
//         stringstream ss(line);
//         string unitStr, occupancy;

//         // Read the unit and occupancy type from the line
//         getline(ss, unitStr, ',');
//         getline(ss, occupancy);

//         // Convert unit to an integer
//         int unit = stoi(unitStr);

//         // Increment the count for the given unit and occupancy type
//         unitOccupancyCount[unit][occupancy]++;
//     }

//     // Close the file
//     file.close();

//     // Print the header of the table
//     cout << left << setw(10) << "Unit" << setw(20) << "Owner On-Site" << setw(20) << "Owner Off-Site"
//          << setw(20) << "Tenant" << setw(20) << "Unit Manager" << endl;
//     cout << "-------------------------------------------------------------------------------------" << endl;

//     // Print the results
//     for (const auto& unit : unitOccupancyCount) {
//         // Get the counts for each occupancy type, default to 0 if not found
//         int ownerOnSite = unit.second.count("Owner On-Site") ? unit.second.at("Owner On-Site") : 0;
//         int ownerOffSite = unit.second.count("Owner Off-Site") ? unit.second.at("Owner Off-Site") : 0;
//         int tenant = unit.second.count("Tenant") ? unit.second.at("Tenant") : 0;
//         int unitManager = unit.second.count("Unit Manager") ? unit.second.at("Unit Manager") : 0;

//         // Output in a table format
//         cout << left << setw(10) << unit.first 
//              << setw(20) << ownerOnSite 
//              << setw(20) << ownerOffSite 
//              << setw(20) << tenant 
//              << setw(20) << unitManager << endl;
//     }

//     return 0;
// }





//EXCEL
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    // Open the file containing the data
    ifstream file("sample.txt");

    // Check if the file was opened successfully
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Create a map to store the count of each Occupancy Type for each unit
    map<int, map<string, int>> unitOccupancyCount;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string unitStr, occupancy;

        // Read the unit and occupancy type from the line
        getline(ss, unitStr, ',');
        getline(ss, occupancy);

        // Convert unit to an integer
        int unit = stoi(unitStr);

        // Increment the count for the given unit and occupancy type
        unitOccupancyCount[unit][occupancy]++;
    }

    // Close the file
    file.close();

    // Create and open a CSV file to export the data
    ofstream outputFile("occupancy_data.csv");

    // Check if the file was opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error creating output file!" << endl;
        return 1;
    }

    // Write the header row to the CSV file
    outputFile << "Unit,Owner On-Site,Owner Off-Site,Tenant,Unit Manager,Resident Only Not On Deed\n";

    // Write the data rows to the CSV file
    for (const auto& unit : unitOccupancyCount) {
        // Get the counts for each occupancy type, default to 0 if not found
        int ownerOnSite = unit.second.count("Owner On-Site") ? unit.second.at("Owner On-Site") : 0;
        int ownerOffSite = unit.second.count("Owner Off-Site") ? unit.second.at("Owner Off-Site") : 0;
        int tenant = unit.second.count("Tenant") ? unit.second.at("Tenant") : 0;
        int unitManager = unit.second.count("Unit Manager") ? unit.second.at("Unit Manager") : 0;
        int residentOnlyNotOnDeed = unit.second.count("Resident Only Not On Deed") ? unit.second.at("Resident Only Not On Deed") : 0;

        // Write the unit and its occupancy counts to the file
        outputFile << unit.first << ","
                   << ownerOnSite << ","
                   << ownerOffSite << ","
                   << tenant << ","
                   << unitManager << ","
                   << residentOnlyNotOnDeed << "\n";
    }

    // Close the output file
    outputFile.close();

    cout << "Data successfully exported to occupancy_data.csv" << endl;

    return 0;
}
