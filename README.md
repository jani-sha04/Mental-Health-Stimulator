# 🌟 Mental Health Simulator

A C++ console application designed to help users track their mental wellness, receive personalized support, and maintain a mood history log. This project demonstrates the implementation of various data structures and algorithms in a practical, meaningful application.

## 🎯 Features

### Core Functionality
- **Personal Mood Tracking**: Record and timestamp your current emotional state
- **Motivational Quotes**: Randomly generated inspirational messages to uplift your spirits
- **Mood-Specific Exercises**: Tailored calming and wellness exercises based on your current mood
- **Mood History Log**: Complete record of all your mood entries with dates and times
- **Statistical Analysis**: View patterns and frequency of different moods over time
- **Date-Based Search**: Find mood entries from specific dates
- **User-Friendly Interface**: Intuitive menu system with supportive messaging

### Supported Moods & Exercises
- **Anxious**: Deep breathing, grounding techniques, muscle relaxation
- **Sad**: Gratitude journaling, self-compassion, gentle movement
- **Stressed**: Box breathing, priority organization, meditation
- **Angry**: Cooling breath, physical activity, journaling
- **Overwhelmed**: Brain dumping, task simplification, breathing exercises
- **Happy**: Gratitude practice, joy sharing, moment savoring
- **Tired**: Rest techniques, gentle stretches, hydration focus
- **Custom Moods**: Default exercises for any mood not listed above

## 🛠️ Technical Implementation

### Data Structures Used
- **Vector**: Stores mood history entries and motivational quotes
- **Map**: Links specific moods to appropriate exercises and tracks mood frequency
- **Struct**: `MoodEntry` structure for organized data storage
- **String**: User input handling and text processing

### Algorithms Implemented
- **Random Selection**: For motivational quote generation
- **Frequency Analysis**: Mood pattern tracking and statistics
- **Search Algorithm**: Date-based mood entry retrieval
- **Sorting & Comparison**: Finding most common moods using `max_element`
- **String Processing**: Case-insensitive mood matching

### Key Programming Concepts
- Object-Oriented Programming (OOP)
- STL (Standard Template Library) usage
- File I/O concepts (timestamp generation)
- Menu-driven programming
- Error handling and input validation

## 🚀 Getting Started

### Prerequisites
- C++ compiler (GCC, MinGW, or similar)
- Basic understanding of command line operations

### Installation Options

#### Option 1: Local Development
1. **Clone or Download** the source code
2. **Save** the code as `mental_health_simulator.cpp`
3. **Compile** using your preferred method:

**Using GCC/MinGW:**
```bash
g++ -o mental_health_simulator mental_health_simulator.cpp
```

**Using Visual Studio:**
```bash
cl mental_health_simulator.cpp
```

4. **Run** the executable:
```bash
./mental_health_simulator        # Linux/Mac
mental_health_simulator.exe     # Windows
```

#### Option 2: Online Compilers
- **Replit.com**: Create new C++ project and paste the code
- **OnlineGDB.com**: Quick testing and execution
- **CodeChef IDE**: Alternative online compiler

### Recommended IDEs
- **Code::Blocks** (Cross-platform, beginner-friendly)
- **Visual Studio Community** (Windows, feature-rich)
- **VS Code** (Cross-platform, with C++ extensions)
- **Dev-C++** (Windows, lightweight)

## 📋 Usage Guide

### First Time Setup
1. Run the program
2. Enter your name when prompted
3. Choose to start a wellness session

### Main Menu Options
1. **Start Wellness Session**: Record your current mood and receive personalized support
2. **View Mood History**: See all your previous mood entries in chronological order
3. **View Mood Statistics**: Analyze patterns and frequency of your moods
4. **Search Mood by Date**: Find entries from a specific date (YYYY-MM-DD format)
5. **Get Random Motivation**: Receive an instant motivational quote
6. **Exit**: Close the application safely

### Sample Workflow
```
1. Start the program → Enter name → Choose to continue
2. Describe current mood → Receive motivational quote
3. Get personalized calming exercises → Practice them
4. Use menu to view history or get more motivation
5. Return anytime to track new moods
```

## 📁 Project Structure

```
MentalHealthSimulator/
├── mental_health_simulator.cpp    # Main source code
├── README.md                      # This documentation
├── compiled_executable            # After compilation
└── screenshots/                   # Optional: Program screenshots
```

## 🎨 Sample Output

```
🌟 Welcome to Mental Health Companion 🌟
=========================================

This is a safe space for you to track your mental wellness.
Please enter your name: Alex

Hello, Alex! It's wonderful to have you here.

Would you like to start a wellness session? (y/n): y

🌸 Starting your wellness session...
=====================================

How are you feeling right now?
You can describe your mood in your own words: anxious

Thank you for sharing, Alex.

💭 Here's a message for you:
"You are stronger than you think and more capable than you imagine."

🧘 Recommended calming exercises for you:
==========================================
1. Deep Breathing: Inhale for 4 counts, hold for 4, exhale for 6. Repeat 5 times.

2. 5-4-3-2-1 Grounding: Name 5 things you see, 4 you hear, 3 you touch, 2 you smell, 1 you taste.
```

## 🔧 Customization

### Adding New Moods
Modify the `initializeMoodExercises()` function to include new mood-exercise pairs:
```cpp
moodExercises["excited"] = {
    "Channel energy: Do a quick energizing activity.",
    "Share enthusiasm: Tell someone about your excitement.",
    // Add more exercises...
};
```

### Adding New Quotes
Extend the `motivationalQuotes` vector in `initializeQuotes()`:
```cpp
motivationalQuotes.push_back("Your custom inspirational quote here.");
```

### Modifying Exercise Recommendations
Update existing mood exercises in the `moodExercises` map to better suit your needs.

## 🤝 Contributing

This is an educational project perfect for learning C++ concepts. Feel free to:
- Add new features (mood analysis graphs, export functionality)
- Improve the user interface
- Add more comprehensive mood categories
- Implement data persistence to files
- Create a graphical user interface

## 📝 Educational Value

This project demonstrates:
- **Data Structure Usage**: Practical application of vectors, maps, and structs
- **Algorithm Implementation**: Search, sort, and statistical analysis
- **Object-Oriented Design**: Class structure and encapsulation
- **User Experience**: Menu systems and input handling
- **Real-World Application**: Mental health awareness and self-care tools

## 🔒 Privacy Note

All mood data is stored locally during the program session and is not transmitted anywhere. The application respects user privacy and provides a safe space for personal reflection.

## ⚠️ Disclaimer

This application is designed for personal wellness tracking and educational purposes. It is not a substitute for professional mental health care. If you're experiencing serious mental health concerns, please consult with a qualified healthcare professional.

## 🏆 Future Enhancements

Potential improvements for advanced learners:
- File I/O for persistent data storage
- Mood trend analysis with graphs
- Integration with calendar systems
- Multi-user support
- Mobile app version
- AI-powered mood analysis
- Integration with wearable devices

## 📞 Support

For technical questions or suggestions about this educational project, consider:
- Reviewing C++ documentation for STL containers
- Exploring additional data structure implementations
- Practicing with different algorithm approaches
- Extending functionality as a learning exercise

---

*Built with ❤️ for mental health awareness and C++ learning*

**Remember**: Taking care of your mental health is just as important as taking care of your physical health. You matter, and your feelings are valid. 🌟
