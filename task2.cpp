// Build a tool that assesses the strength of a password based on criteria such as length, presence of uppercase and lowercase letters, numbers, and special characters.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int calculatePasswordStrength(const string& password) {
    int score = 0;

    // Criteria flags
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;

    // Length criteria
    if (password.length() >= 8) score += 1;   // Minimum length requirement
    if (password.length() >= 12) score += 1;  // Additional score for a longer password

    // Character type criteria
    for (char ch : password) {
        if (islower(ch)) hasLower = true;
        else if (isupper(ch)) hasUpper = true;
        else if (isdigit(ch)) hasDigit = true;
        else hasSpecial = true;
    }

    if (hasLower) score += 1;
    if (hasUpper) score += 1;
    if (hasDigit) score += 1;
    if (hasSpecial) score += 1;

    return score;
}

string getStrengthMessage(int score) {
    if (score <= 2) return "Weak";
    else if (score == 3) return "Moderate";
    else if (score == 4) return "Strong";
    else return "Very Strong";
}

int main() {
    string password;
    cout << "Enter password to check strength: ";
    getline(cin, password);

    int score = calculatePasswordStrength(password);
    string strength = getStrengthMessage(score);

    cout << "Password strength: " << strength << " (Score: " << score << "/6)" <<endl;

    return 0;
}
