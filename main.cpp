// typing speed test program
#include <iostream>
#include <chrono>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

// vectors to save wpm and accuracy across tests
vector<double> wpmResults;
vector<double> accuracyResults;

// function to display cli instructions
void displayInstructions() {
	cout << "Welcome to the Typing Speed Test!" << endl;
	cout << "You will be given a sentence to type." << endl;
	cout << "Type the sentence as quickly and accurately as possible." << endl;
	cout << "Press Enter when you are done." << endl;
	cout << "Let's begin!" << endl << endl;

	std::string alien = R"(
   .-.
  (o o)        _____________
   |=|        | Let's Type! |
  __|__       ------------- 
 /     \       
/_______\
)";

	cout << alien << endl << endl;
}

// function to calculate typing speed and accuracy
// take a reference to the original sentence and the typed sentence, and also take the
// time taken in seconds as a double
void calculateResults(const string& original, const string& typed, double timeTaken) {
	int correctChars = 0; // for accuracy
	int totalChars = original.length(); // total characters in the original sentence

	// looping up to either the og sentence or typed sentence length to get the correct
	// characters typed
	for (size_t i = 0; i < min(original.length(), typed.length()); ++i) {
		if (original[i] == typed[i]) {
			correctChars++;
		}
	}

	// calculating acc & WPM
	// formatting acc as a percent
	double accuracy = (static_cast<double>(correctChars) / totalChars) * 100;

	// divide by 60 here for per min answer
	// wpm = total words / time in minutes
	// typing tests commonly consider a word as 5 characters
	double wpm = (static_cast<double>(typed.length()) / 5) / (timeTaken / 60);

	// store results in vectors
	wpmResults.push_back(wpm);
	accuracyResults.push_back(accuracy);


	// displaying results
	cout << endl << "Results:" << endl;
	cout << "Time Taken: " << timeTaken << " seconds" << endl;
	cout << "Words Per Minute (WPM): " << wpm << endl;
	cout << "Accuracy: " << accuracy << "%" << endl;
}

// main function
int main() {
	// predefined sentences for the test
	vector<string> sentences = {
		"The quick brown fox jumps over the lazy dog.",
		"Typing speed tests are a fun way to improve your skills.",
		"Practice makes perfect, so keep on typing!",
		"C++ is a powerful programming language used for many applications.",
		"Consistency and accuracy are key to becoming a better typist."
	};

	displayInstructions(); // display top-line instructions

	// add message for user to say they are ready before entering loop
	cout << "Press Enter when you are ready to start the test..." << endl;
	cin.ignore(); // wait for user to press enter

	while (true)
	{
		// randomly select a sentence
		// if sentence has been chosen before, it cannot be selected again
		srand(static_cast<unsigned int>(time(nullptr))); // seed random number generator

		// select a random sentence from the list
		string sentenceToType = sentences[rand() % sentences.size()];

		// get the index of the sentence that was selected
		auto it = find(sentences.begin(), sentences.end(), sentenceToType);

		// remove the sentence from the list so it can't be selected again
		if (it != sentences.end()) {
			sentences.erase(it); // remove the selected sentence from the list
		}

		cout << "Type the following sentence:" << endl;
		cout << "\"" << sentenceToType << "\"" << endl << endl;

		// start timer
		auto startTime = high_resolution_clock::now();

		// get user input
		string userInput;
		getline(cin, userInput);

		// stop timer
		auto endTime = high_resolution_clock::now();

		// calculate time taken in seconds
		duration<double> timeTaken = endTime - startTime;

		// calculate and display results
		calculateResults(sentenceToType, userInput, timeTaken.count());

		// ask if user wants to try again
		cout << endl << "Do you want to try again? (y/n): ";

		char choice;
		cin >> choice;

		cin.ignore(); // to clear the newline character from the input buffer

		// break the loop if user doesn't want to continue
		if (choice != 'y' && choice != 'Y') {
			cout << "Thank you for using the Typing Speed Test. Goodbye!" << endl;
			break;
		}
	}

	// if user did multiple tests, calculate overall accuracy and words per minute
	if (!wpmResults.empty() && !accuracyResults.empty()) {
		// calculating overall averages
		double totalWPM = 0;
		double totalAccuracy = 0;
		// loop through wpm vec
		for (double wpm : wpmResults) {
			totalWPM += wpm; // add to total
		}
		// loop through accuracy vec
		for (double acc : accuracyResults) {
			totalAccuracy += acc; // add to total
		}

		// calc averages
		double averageWPM = totalWPM / wpmResults.size();
		double averageAccuracy = totalAccuracy / accuracyResults.size();

		// display overall results
		cout << endl << "Overall Results:" << endl;
		cout << "Average Words Per Minute (WPM): " << averageWPM << endl;
		cout << "Average Accuracy: " << averageAccuracy << "%" << endl;
	}

	return 0;
}