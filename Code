#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

// Structure to store mood entry with timestamp
struct MoodEntry {
    string mood;
    string timestamp;
    string date;
    
    MoodEntry(const string& m, const string& ts, const string& d) 
        : mood(m), timestamp(ts), date(d) {}
};

class MentalHealthSimulator {
private:
    string userName;
    vector<MoodEntry> moodHistory;  // Vector to store mood history
    map<string, vector<string>> moodExercises;  // Map for mood-specific exercises
    vector<string> motivationalQuotes;  // Vector for quotes
    
    // Initialize motivational quotes
    void initializeQuotes() {
        motivationalQuotes = {
            "You are stronger than you think and more capable than you imagine.",
            "Every small step you take matters. Progress is progress, no matter how small.",
            "It's okay to not be okay. What matters is that you're here, trying.",
            "You have survived 100% of your difficult days so far. You're doing great.",
            "Your mental health is just as important as your physical health.",
            "Be patient with yourself. Growth takes time.",
            "You are worthy of love, care, and happiness.",
            "Today is a new day, full of new possibilities.",
            "Your feelings are valid, and it's okay to feel them.",
            "You are not alone in this journey.",
            "Healing is not linear, and that's perfectly okay.",
            "You have the power to create positive change in your life.",
            "Take one breath at a time, one moment at a time.",
            "You are enough, just as you are.",
            "Tomorrow is a new opportunity to start fresh."
        };
    }
    
    // Initialize mood-specific exercises using map
    void initializeMoodExercises() {
        moodExercises["anxious"] = {
            "Deep Breathing: Inhale for 4 counts, hold for 4, exhale for 6. Repeat 5 times.",
            "5-4-3-2-1 Grounding: Name 5 things you see, 4 you hear, 3 you touch, 2 you smell, 1 you taste.",
            "Progressive muscle relaxation: Tense and release each muscle group for 5 seconds.",
            "Mindful walking: Take a slow 5-minute walk, focusing on each step."
        };
        
        moodExercises["sad"] = {
            "Gratitude journaling: Write down 3 things you're grateful for today.",
            "Self-compassion break: Place hand on heart and say 'This is a moment of suffering, may I be kind to myself.'",
            "Gentle movement: Do some light stretching or yoga for 10 minutes.",
            "Connect with nature: Spend 10 minutes outside or look at nature photos."
        };
        
        moodExercises["stressed"] = {
            "Box breathing: Breathe in for 4, hold for 4, out for 4, hold for 4. Repeat.",
            "Priority list: Write down your tasks and organize them by importance.",
            "Quick meditation: Sit quietly for 5 minutes focusing on your breath.",
            "Physical release: Do jumping jacks or shake out your limbs for 2 minutes."
        };
        
        moodExercises["angry"] = {
            "Cooling breath: Breathe in through nose, out through pursed lips slowly.",
            "Physical activity: Do 10 push-ups or go for a quick walk.",
            "Journaling: Write about your feelings without censoring yourself.",
            "Count backwards: From 100 to 1, focusing on each number."
        };
        
        moodExercises["overwhelmed"] = {
            "Brain dump: Write everything on your mind for 10 minutes without editing.",
            "One thing at a time: Choose just one small task to focus on right now.",
            "Breathing space: Take 10 deep breaths while sitting comfortably.",
            "Simplify: Remove one non-essential thing from your day."
        };
        
        moodExercises["happy"] = {
            "Gratitude practice: Reflect on what made you feel this way.",
            "Share the joy: Tell someone about your positive mood.",
            "Savor the moment: Take 5 minutes to fully appreciate this feeling.",
            "Future self: Write a note to yourself for when you're feeling down."
        };
        
        moodExercises["tired"] = {
            "Power nap: If possible, rest for 10-20 minutes.",
            "Gentle stretches: Do simple neck and shoulder rolls.",
            "Hydration check: Drink a glass of water slowly and mindfully.",
            "Energy scan: Notice which parts of your body need rest."
        };
    }
    
    // Get current timestamp
    string getCurrentTimestamp() {
        time_t now = time(0);
        char* timeStr = ctime(&now);
        string timestamp(timeStr);
        timestamp.pop_back(); // Remove newline character
        return timestamp;
    }
    
    // Get current date
    string getCurrentDate() {
        time_t now = time(0);
        struct tm* timeInfo = localtime(&now);
        char buffer[80];
        strftime(buffer, 80, "%Y-%m-%d", timeInfo);
        return string(buffer);
    }
    
    // Generate random motivational quote using simple random selection
    string getRandomQuote() {
        if (motivationalQuotes.empty()) return "You're doing great!";
        int randomIndex = rand() % motivationalQuotes.size();
        return motivationalQuotes[randomIndex];
    }
    
    // Get exercises for specific mood using map lookup
    vector<string> getExercisesForMood(const string& mood) {
        string lowerMood = mood;
        transform(lowerMood.begin(), lowerMood.end(), lowerMood.begin(), ::tolower);
        
        if (moodExercises.find(lowerMood) != moodExercises.end()) {
            return moodExercises[lowerMood];
        } else {
            // Default exercises for unrecognized moods
            return {
                "Take 5 deep breaths and focus on the present moment.",
                "Write down your current feelings in a journal.",
                "Take a short walk or do light stretching.",
                "Listen to calming music for 10 minutes."
            };
        }
    }
    
    // Display mood statistics using algorithms
    void displayMoodStatistics() {
        if (moodHistory.empty()) {
            cout << "\n📊 No mood data available yet.\n";
            return;
        }
        
        cout << "\n📊 MOOD STATISTICS\n";
        cout << "==================\n";
        
        // Count mood frequencies using map
        map<string, int> moodCount;
        for (const auto& entry : moodHistory) {
            moodCount[entry.mood]++;
        }
        
        cout << "Mood Frequency:\n";
        for (const auto& pair : moodCount) {
            cout << "  " << pair.first << ": " << pair.second << " times\n";
        }
        
        // Find most common mood using algorithm
        auto mostCommon = max_element(moodCount.begin(), moodCount.end(),
            [](const pair<string, int>& a, const pair<string, int>& b) {
                return a.second < b.second;
            });
        
        cout << "\nMost common mood: " << mostCommon->first 
             << " (" << mostCommon->second << " times)\n";
        cout << "Total entries: " << moodHistory.size() << "\n";
    }

public:
    MentalHealthSimulator() {
        srand(time(nullptr)); // Initialize random seed
        initializeQuotes();
        initializeMoodExercises();
    }
    
    // Welcome and get user name
    void welcome() {
        cout << "🌟 Welcome to Mental Health Companion 🌟\n";
        cout << "=========================================\n\n";
        cout << "This is a safe space for you to track your mental wellness.\n";
        cout << "Please enter your name: ";
        getline(cin, userName);
        
        cout << "\nHello, " << userName << "! It's wonderful to have you here.\n";
    }
    
    // Ask for session continuation
    bool askToContinue() {
        char choice;
        cout << "\nWould you like to start a wellness session? (y/n): ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer
        
        return (choice == 'y' || choice == 'Y');
    }
    
    // Main session flow
    void startSession() {
        cout << "\n🌸 Starting your wellness session...\n";
        cout << "=====================================\n";
        
        // Get current mood
        string currentMood;
        cout << "\nHow are you feeling right now?\n";
        cout << "You can describe your mood in your own words: ";
        getline(cin, currentMood);
        
        // Store mood with timestamp using vector
        string timestamp = getCurrentTimestamp();
        string date = getCurrentDate();
        moodHistory.push_back(MoodEntry(currentMood, timestamp, date));
        
        cout << "\nThank you for sharing, " << userName << ".\n";
        
        // Generate and display motivational quote
        cout << "\n💭 Here's a message for you:\n";
        cout << "\"" << getRandomQuote() << "\"\n";
        
        // Provide mood-specific exercises
        cout << "\n🧘 Recommended calming exercises for you:\n";
        cout << "==========================================\n";
        
        vector<string> exercises = getExercisesForMood(currentMood);
        for (size_t i = 0; i < exercises.size(); i++) {
            cout << (i + 1) << ". " << exercises[i] << "\n\n";
        }
        
        cout << "Take your time with these exercises. You deserve this care.\n";
    }
    
    // Display mood history using queue-like display (recent entries first)
    void displayMoodHistory() {
        if (moodHistory.empty()) {
            cout << "\n📝 No mood history available yet.\n";
            cout << "Start a session to begin tracking your wellness journey!\n";
            return;
        }
        
        cout << "\n📝 YOUR MOOD HISTORY\n";
        cout << "====================\n";
        
        // Display recent entries first (reverse iteration)
        for (int i = moodHistory.size() - 1; i >= 0; i--) {
            cout << "📅 " << moodHistory[i].date << " at " << moodHistory[i].timestamp << "\n";
            cout << "💭 Mood: " << moodHistory[i].mood << "\n";
            cout << "-------------------\n";
        }
        
        displayMoodStatistics();
    }
    
    // Search mood history by date
    void searchMoodByDate() {
        if (moodHistory.empty()) {
            cout << "\n📝 No mood history available to search.\n";
            return;
        }
        
        string searchDate;
        cout << "\nEnter date to search (YYYY-MM-DD): ";
        getline(cin, searchDate);
        
        cout << "\n🔍 Entries for " << searchDate << ":\n";
        cout << "================================\n";
        
        bool found = false;
        for (const auto& entry : moodHistory) {
            if (entry.date == searchDate) {
                cout << "⏰ " << entry.timestamp << " - Mood: " << entry.mood << "\n";
                found = true;
            }
        }
        
        if (!found) {
            cout << "No entries found for this date.\n";
        }
    }
    
    // Main menu system
    void showMenu() {
        int choice;
        
        do {
            cout << "\n🌟 MENTAL HEALTH COMPANION MENU 🌟\n";
            cout << "====================================\n";
            cout << "1. Start Wellness Session\n";
            cout << "2. View Mood History\n";
            cout << "3. View Mood Statistics\n";
            cout << "4. Search Mood by Date\n";
            cout << "5. Get Random Motivation\n";
            cout << "6. Exit\n";
            cout << "\nChoose an option (1-6): ";
            
            cin >> choice;
            cin.ignore(); // Clear input buffer
            
            switch (choice) {
                case 1:
                    startSession();
                    break;
                case 2:
                    displayMoodHistory();
                    break;
                case 3:
                    displayMoodStatistics();
                    break;
                case 4:
                    searchMoodByDate();
                    break;
                case 5:
                    cout << "\n💭 " << getRandomQuote() << "\n";
                    break;
                case 6:
                    cout << "\nThank you for using Mental Health Companion, " << userName << "!\n";
                    cout << "Remember: You're stronger than you know. Take care! 🌟\n";
                    break;
                default:
                    cout << "\nPlease enter a valid option (1-6).\n";
            }
        } while (choice != 6);
    }
};

// Main function
int main() {
    MentalHealthSimulator simulator;
    
    simulator.welcome();
    
    if (simulator.askToContinue()) {
        simulator.showMenu();
    } else {
        cout << "\nThat's okay! Remember, we're here whenever you need support.\n";
        cout << "Take care of yourself! 🌟\n";
    }
    
    return 0;
}
