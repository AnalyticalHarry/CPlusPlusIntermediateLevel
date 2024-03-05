#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// function to display the specified number of rows from the CSV content
void displayRows(const std::vector<std::vector<std::string>>& content, int numRows) {
    for(int i = 0; i < std::min(numRows, static_cast<int>(content.size())); i++) {
        for(const auto& cell : content[i]) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

// function to read data from a CSV file into a 2D vector
std::vector<std::vector<std::string>> readCSV(const std::string& filePath) {
    std::vector<std::vector<std::string>> content;
    std::ifstream file(filePath);
    std::string line;

    if(file.is_open()) {
        while(std::getline(file, line)) {
            std::vector<std::string> row;
            std::stringstream lineStream(line);
            std::string cell;
            // ensure delimiter is specified for CSV format
            while(std::getline(lineStream, cell, ',')) { 
                row.push_back(cell);
            }

            content.push_back(row);
        }
    } else {
        std::cerr << "Could not open the file at " << filePath << std::endl;
    }

    return content;
}

int main() {
    // specify the CSV file path
    std::string filePath = "customer_data.csv";

    // read from the file and store its content
    auto content = readCSV(filePath);

    // number of rows to display
    int numRowsToShow = 20;

    // selectable number of rows
    std::cout << "Displaying the first " << numRowsToShow << " rows of the CSV file:\n";
    displayRows(content, numRowsToShow);

    return 0;
}


// g++ readCSV.cpp -o readCSV.exe
// .\readCSV.exe

// Code pushed on 05.03.2024
// Hemant Thapa
