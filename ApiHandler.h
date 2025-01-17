//
// Created by tony on 17/01/2025.
//

#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"
#include "FlowerAscii.h"
#include "CatAscii.h"

using json = nlohmann::json;
using namespace std;

#ifndef REST_PROJEKT_APIHANDLER_H
#define REST_PROJEKT_APIHANDLER_H

// Enum for execution mode
enum class ExecutionMode { ZenQuotes, MeowFacts };

class ApiHandler {

private:
    // Function to get JSON data from the API
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
        size_t totalSize = size * nmemb;
        output->append(static_cast<char*>(contents), totalSize);
        return totalSize;
    }

    // Function to get JSON data from the API
    static string get_jsonData(const string& mode, string& url) {
        CURL* curl;
        CURLcode res;
        string responseString;

        url = url + mode;
        // Initialize cURL
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if (curl) {
            // Set cURL options
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseString);

            // Perform the HTTP GET request
            res = curl_easy_perform(curl);

            // Check for errors
            if (res != CURLE_OK) {
                cerr << "cURL failed: " << curl_easy_strerror(res) << endl;
            }

            // Clean up
            curl_easy_cleanup(curl);
        }

        // Cleanup cURL global state
        curl_global_cleanup();

        return responseString;
    }

    // Function to print MeowFacts
    static void print_MeowFacts(const nlohmann::json& jsonData){
        int i = 0;
        if (jsonData.contains("data") && jsonData["data"].is_array()) {

            for (const auto& fact : jsonData["data"]) {
                cout << "--------------------- Random Cat Fact #" << i+1 << " ----------------------------------" << endl;
                cout << fact << endl;
                printRandomCatAscii();
                i++;
            }
        }
        else {
            cout << "Error: Wrong data type returned by MeowFacts API"<< endl;
        }
    }

    // Function to print ZenQuotes
    static void print_ZenQuotes(const nlohmann::json& jsonData, const int number) {
        int i = 0;
        for (const auto& jsonObject : jsonData) {
            cout << "--------------------- Random Zen Quote #" << i+1 << " ----------------------------------" << endl;
            cout << "Quote by: " << jsonObject.at("a") << ":\n" << jsonObject.at("q") << endl;
            i++;
            printRandomFlowerAscii();
            if (i==number+1) {break;}  // Break the loop if the specified number is exceeded
        }
    }

public:
    // Constructor
    ApiHandler();

    // Function to display JSON data formatted based on the execution mode
    static void display_jsonData_formatted(ExecutionMode mode, const int number = 1) {

        nlohmann::json jsonData;
        string APImode;
        string url;

        // set the URL and MODE according to the ExecutionMode
        switch (mode) {
            case ExecutionMode::ZenQuotes: {
                APImode = "quotes";
                url = "https://zenquotes.io/api/";
                break;
            }
            case ExecutionMode::MeowFacts: {
                APImode = "?count=" + to_string(number);
                url = "https://meowfacts.herokuapp.com/";
                break;
            }
            default:
                cerr << "Invalid Option entered." << endl;
                break;
        }

        // Call the API to get a JSON response
        string response = get_jsonData(APImode,url);

        // Try to parse the JSON data
        if (!response.empty()) {
            try {
                // Parse JSON response
                jsonData = nlohmann::json::parse(response);

            } catch (const nlohmann::json::exception& e) {
                cerr << "Error parsing JSON: " << e.what() << endl;
            }
        } else {
            cerr << "Error: Unable to retrieve data." << endl;
        }

        // Print the results
        switch (mode) {
            case ExecutionMode::ZenQuotes: {
                print_ZenQuotes(jsonData, number);
                break;
            }
            case ExecutionMode::MeowFacts: {
                print_MeowFacts(jsonData);
                break;
            }
            default:
                cerr << "Invalid Option entered." << endl;
                break;
        }
    }

};


#endif //REST_PROJEKT_APIHANDLER_H
