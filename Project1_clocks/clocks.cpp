/*
Alexander Wagner
5/21/2023
CS-210
*/

#include <iostream>
#include <ctime> // Provides functionality for working with time
#include <string>

#ifdef _WIN32
#include <Windows.h> // If Windows include
#else
#include <unistd.h> // Else include
#endif

using namespace std;

#ifdef _WIN32
// Windows version of SetConsoleColor
void SetConsoleColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}
#else
// SetConsoleColor for other platforms
void SetConsoleColor(int colorCode) {
    cout << "\033[38;5;" << colorCode << "m"; //purple code
}
#endif

class Clock {
private:
    int hours;
    int mins;
    int secs;

public:
    // Constructor
    Clock() {
        // Get current system time
        time_t now = time(0);
        struct tm currentTime;
        localtime_s(&currentTime, &now);

        // Set clock time
        hours = currentTime.tm_hour;
        mins = currentTime.tm_min;
        secs = currentTime.tm_sec;
    }

    // Function to set the time of the clock
    void setTime(int h, int m, int s) {
        // Check input values
        if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
            hours = h;
            mins = m;
            secs = s;
            SetConsoleColor(13); // Purple color
            cout << "Time set successfully." << endl;
        }
        else {
            SetConsoleColor(13);
            cout << "Invalid time input." << endl;
        }
    }

    // Function to add secs to the current time
    void addSecond() {
        secs++;
        if (secs >= 60) {
            secs = 0;
            mins++;
            if (mins >= 60) {
                mins = 0;
                hours++;
                if (hours >= 24) {
                    hours = 0;
                }
            }
        }
        SetConsoleColor(13);
        cout << "One second added to the current time." << endl;
    }

    // Function to add min to the current time
    void addMinute() {
        mins++;
        if (mins >= 60) {
            mins = 0;
            hours++;
            if (hours >= 24) {
                hours = 0;
            }
        }
        SetConsoleColor(13);
        cout << "One minute added to the current time." << endl;
    }

    // Function to add hour to the current time
    void addHour() {
        hours++;
        if (hours >= 24) {
            hours = 0;
        }
        SetConsoleColor(13);
        cout << "One hour added to the current time." << endl;
    }

    // Function to display time of clock in 12 hour format
    void display12HourClock() {
        int hour = hours % 12;
        string period = (hours < 12) ? "AM" : "PM";
        if (hour == 0)
            hour = 12;

        SetConsoleColor(13);
        cout << "*****************************      *****************************" << endl;
        cout << "*   Time (12-hour format)   *      *   Time (24-hour format)   *" << endl;
        cout << "*        ";
        if (hour < 10)
            cout << " ";
        cout << hour << ":";
        if (mins < 10)
            cout << "0";
        cout << mins << ":";
        if (secs < 10)
            cout << "0";
        cout << secs << " " << period;
        if (period == "AM")
            cout << "        *      *       ";
        else
            cout << "        *      *       ";
        if (hours < 10)
            cout << " ";
        cout << hours << ":";
        if (mins < 10)
            cout << "0";
        cout << mins << ":";
        if (secs < 10)
            cout << "0";
        cout << secs << "            *" << endl;
        cout << "*****************************      *****************************" << endl;
    }

    // Function to get input to change the time of the clock
    void userInputTime() {
        int h, m, s;
        SetConsoleColor(13);
        cout << "Enter the new time (HH MM SS): ";

        cin >> h >> m >> s;
        setTime(h, m, s);

        // Display updated time
        SetConsoleColor(13);
        cout << "Updated time:" << endl;

        display12HourClock();
    }
};

int main() {
    // Disable warning for localtime function
#pragma warning(disable : 4996)

    // Create clock object
    Clock clock;

    // Display current time
    SetConsoleColor(13);
    cout << "*****************************      *****************************" << endl;
    cout << "*         Current time      *      *         Current time      *" << endl;
    clock.display12HourClock();
    cout << "*****************************      *****************************" << endl;

    // Menu loop
    string input;
    while (true) {
        SetConsoleColor(13);
        cout << "\n--- Menu ---" << endl;
        cout << "1. Set clock time" << endl;
        cout << "2. Add a second to the current time" << endl;
        cout << "3. Add a minute to the current time" << endl;
        cout << "4. Add an hour to the current time" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        // Read user input
        cin >> input;

        if (input == "1") {
            SetConsoleColor(13);
            cout << "\n--- Set Clock Time ---" << endl;
            // Call userInputTime() to set the time
            clock.userInputTime();
        }
        else if (input == "2") {
            SetConsoleColor(13);
            cout << "\n--- Add a Second ---" << endl;
            // Call addSecond() to add a sec to the time
            clock.addSecond();
            SetConsoleColor(13);
            cout << "Updated time:" << endl;
            // Display the updated time
            clock.display12HourClock();
        }
        else if (input == "3") {
            SetConsoleColor(13);
            cout << "\n--- Add a Minute ---" << endl;
            // Call addMinute() to add a min to the time
            clock.addMinute();
            SetConsoleColor(13);
            cout << "Updated time:" << endl;
            clock.display12HourClock();
        }
        else if (input == "4") {
            SetConsoleColor(13);
            cout << "\n--- Add an Hour ---" << endl;
            // Call addHour() to add an hour to the time
            clock.addHour();
            SetConsoleColor(13);
            cout << "Updated time:" << endl;
            clock.display12HourClock();
        }
        else if (input == "5") {
            // Exit menu loop
            break;
        }
        else {
            SetConsoleColor(13);
            cout << "\nInvalid choice. Please try again." << endl;
        }
    }

    return 0;
}