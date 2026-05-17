#include <iostream>
using namespace std;

int main() {
    char fever, cough, headache, fatigue, vomiting;

    cout << "=== Hospital Expert System ===\n";
    cout << "Answer the following questions (y/n):\n";

    cout << "Do you have fever? ";
    cin >> fever;

    cout << "Do you have cough? ";
    cin >> cough;

    cout << "Do you have headache? ";
    cin >> headache;

    cout << "Do you feel fatigue? ";
    cin >> fatigue;

    cout << "Do you have vomiting? ";
    cin >> vomiting;

    cout << "\n--- Diagnosis Result ---\n";

    // Rule-based decision making
    if (fever == 'y' && cough == 'y' && fatigue == 'y') {
        cout << "Possible Condition: Flu or COVID-like illness\n";
        cout << "Advice: Consult a doctor and take rest.\n";
    }
    else if (fever == 'y' && headache == 'y' && vomiting == 'y') {
        cout << "Possible Condition: Migraine or Viral Fever\n";
        cout << "Advice: Stay hydrated and consult a physician.\n";
    }
    else if (cough == 'y' && fever == 'n') {
        cout << "Possible Condition: Common Cold\n";
        cout << "Advice: Drink warm fluids and rest.\n";
    }
    else if (fatigue == 'y' && headache == 'y') {
        cout << "Possible Condition: Stress or Dehydration\n";
        cout << "Advice: Take rest and drink plenty of water.\n";
    }
    else {
        cout << "Condition unclear.\n";
        cout << "Advice: Please consult a healthcare professional.\n";
    }

    cout << "\nThank you for using the system!\n";

    return 0;
}
