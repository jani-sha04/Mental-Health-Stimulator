#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// ANSI color codes for beautiful output
const string RESET = "\033[0m";
const string CYAN = "\033[36m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string MAGENTA = "\033[35m";
const string BLUE = "\033[34m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";

// Helper to clear screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Helper to sleep for seconds
void sleepSeconds(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

// ASCII Art Banner
void printBanner() {
    cout << CYAN << BOLD;
    cout << "==========================================\n";
    cout << "   🐔  Mental Health Check Simulator  🐔   \n";
    cout << "==========================================\n";
    cout << RESET;
}

// User class
class User {
    string name;
    vector<string> moodHistory;
public:
    void setName(const string& n) { name = n; }
    string getName() const { return name; }
    void addMood(const string& mood) { moodHistory.push_back(mood); }
    void printMoodHistory() const {
        cout << YELLOW << "\nMood History for " << name << ":\n" << RESET;
        if (moodHistory.empty()) {
            cout << "  (No moods logged yet)\n";
        } else {
            for (size_t i = 0; i < moodHistory.size(); ++i) {
                cout << "  [" << (i+1) << "] " << moodHistory[i] << "\n";
            }
        }
    }
};

// CodeProvider class
class CodeProvider {
    vector<string> quotes = {
        "This too shall pass.",
        "You are stronger than you think.",
        "Every day is a second chance.",
        "Believe in yourself!",
        "Keep going, you are doing great.",
        "Your feelings are valid.",
        "Take it one step at a time.",
        "You matter."
    };
public:
    string getRandomQuote() {
        int idx = rand() % quotes.size();
        return quotes[idx];
    }
};

// MoodTracker class
class MoodTracker {
public:
    string askMood() {
        cout << GREEN << "\nHow are you feeling today? " << RESET;
        string mood;
        getline(cin, mood);
        return mood;
    }
};

// CalmingActivity class
class CalmingActivity {
public:
    void start() {
        clearScreen();
        cout << MAGENTA << BOLD << "\nLet's do a calming breathing exercise together!\n" << RESET;
        cout << "Follow the prompts...\n\n";
        for (int i = 0; i < 3; ++i) {
            cout << BLUE << "Breathe in... " << RESET;
            sleepSeconds(2);
            cout << YELLOW << "Hold... " << RESET;
            sleepSeconds(3);
            cout << GREEN << "Breathe out...\n" << RESET;
            sleepSeconds(3);
        }
        cout << MAGENTA << "\nGreat job! Hope you feel a bit better.\n" << RESET;
        sleepSeconds(2);
    }
};

// Assistant class
class Assistant {
    User user;
    CodeProvider codeProvider;
    MoodTracker moodTracker;
    CalmingActivity calmingActivity;
public:
    void run() {
        srand((unsigned)time(0));
        clearScreen();
        printBanner();
        cout << BOLD << "\nWelcome! What's your name? " << RESET;
        string name;
        getline(cin, name);
        user.setName(name);
        clearScreen();
        printBanner();
        cout << "Hello, " << CYAN << BOLD << user.getName() << RESET << "!\n";
        cout << "Would you like to start a session? (Y/N): ";
        string start;
        getline(cin, start);
        if (start.empty() || (start[0] != 'Y' && start[0] != 'y')) {
            cout << "\nTake care! See you next time.\n";
            return;
        }
        clearScreen();
        printBanner();
        string mood = moodTracker.askMood();
        user.addMood(mood);
        cout << "\nYour motivational quote: " << YELLOW << '"' << codeProvider.getRandomQuote() << '"' << RESET << "\n";
        cout << "\nWould you like to do a calming exercise? (Y/N): ";
        string doCalm;
        getline(cin, doCalm);
        if (!doCalm.empty() && (doCalm[0] == 'Y' || doCalm[0] == 'y')) {
            calmingActivity.start();
        }
        cout << GREEN << "\nMood logged: '" << mood << "'\n" << RESET;
        sleepSeconds(1);
        cout << "\nWould you like to view your mood history? (Y/N): ";
        string viewHist;
        getline(cin, viewHist);
        if (!viewHist.empty() && (viewHist[0] == 'Y' || viewHist[0] == 'y')) {
            user.printMoodHistory();
        }
        cout << "\nThank you for using the Mental Health Check Simulator, " << CYAN << user.getName() << RESET << "!\n";
        cout << "Remember: You are not alone.\n";
    }
};

int main() {
#ifdef _WIN32
    // Enable ANSI escape codes on Windows 10+
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= 0x0004; // ENABLE_VIRTUAL_TERMINAL_PROCESSING
            SetConsoleMode(hOut, dwMode);
        }
    }
#endif
    Assistant assistant;
    assistant.run();
    return 0;
}
