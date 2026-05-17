#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


string toLower(string input) {
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}


string getResponse(string input) {
    input = toLower(input);

    if (input.find("hello") != string::npos || input.find("hi") != string::npos) {
        return "Hello! Welcome to our store. How can I assist you today?";
    }
    else if (input.find("order") != string::npos || input.find("status") != string::npos) {
        return "You can check your order status in the 'My Orders' section.";
    }
    else if (input.find("return") != string::npos || input.find("refund") != string::npos) {
        return "To initiate a return, go to your orders and select 'Return Item'.";
    }
    else if (input.find("product") != string::npos) {
        return "We offer a variety of products. Please specify what you're looking for.";
    }
    else if (input.find("payment") != string::npos) {
        return "We accept credit cards, debit cards, UPI, and net banking.";
    }
    else if (input.find("bye") != string::npos || input.find("exit") != string::npos) {
        return "Thank you for visiting! Have a great day!";
    }
    else {
        return "Sorry, I didn't understand that. Can you please rephrase?";
    }
}

int main() {
    string userInput;

    cout << "=== Customer Support Chatbot ===\n";
    cout << "Type 'exit' to end the chat.\n\n";

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        string response = getResponse(userInput);
        cout << "Bot: " << response << endl;

        if (toLower(userInput).find("exit") != string::npos) {
            break;
        }
    }

    return 0;
}
