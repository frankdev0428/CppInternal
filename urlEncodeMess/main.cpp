#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <curl/curl.h>

using namespace std;

/* Curl write callback */
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

/* Extract values between <td> and </td> */
vector<string> extractTDValues(const string& html)
{
    vector<string> values;
    size_t pos = 0;

    while ((pos = html.find("<td", pos)) != string::npos)
    {
        pos = html.find(">", pos);
        if (pos == string::npos) break;

        size_t end = html.find("</td>", pos);
        if (end == string::npos) break;

        string value = html.substr(pos + 1, end - pos - 1);

        // Remove inner HTML tags like <span>
        string clean;
        bool insideTag = false;
        for (char c : value)
        {
            if (c == '<') insideTag = true;
            else if (c == '>') insideTag = false;
            else if (!insideTag) clean += c;
        }

        // Trim whitespace
        stringstream ss(clean);
        string finalValue;
        ss >> finalValue;

        if (!finalValue.empty())
            values.push_back(finalValue);

        pos = end + 5;
    }

    return values;
}

/* Main decoding function */
void decodeSecretMessage(const string& url)
{
    CURL* curl;
    CURLcode res;
    string response;

    curl = curl_easy_init();
    if (!curl)
    {
        cerr << "Curl initialization failed.\n";
        return;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK)
    {
        cerr << "Error downloading document.\n";
        return;
    }

    vector<string> values = extractTDValues(response);

    map<pair<int,int>, char> grid;
    int maxX = 0;
    int maxY = 0;

    // Read every 3 values as x, character, y
    for (size_t i = 0; i + 2 < values.size(); i += 3)
    {
        try
        {
            int x = stoi(values[i]);
            int y = stoi(values[i + 2]);
            string character = values[i + 1];

            grid[{x, y}] = character[0];

            maxX = max(maxX, x);
            maxY = max(maxY, y);
        }
        catch (...)
        {
            // Skip header row or invalid data
            continue;
        }
    }

    // Create board
    vector<vector<char>> board(maxY + 1, vector<char>(maxX + 1, ' '));

    // Fill board
    for (auto& entry : grid)
    {
        int x = entry.first.first;
        int y = entry.first.second;
        board[y][x] = entry.second;
    }

    // Print correctly oriented output (top to bottom)
    for (int y = maxY; y >= 0; y--)
    {
        for (int x = 0; x <= maxX; x++)
        {
            cout << board[y][x];
        }
        cout << endl;
    }
}

int main()
{
    string url;
    cout << "Enter Google Doc URL: ";
    getline(cin, url);

    decodeSecretMessage(url);

    return 0;
}
