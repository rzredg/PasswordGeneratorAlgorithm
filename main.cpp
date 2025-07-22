#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

// Allow Uppercase [A-Z] and lowercase [a-z] English alphabet characters
// Also allow spaces 
void algorithm(vector<string> words) {
	vector<char> specialchars = { '!', '@', '#', '/', '$', '%', '^', '&', '*', '~', '?', '|', '_', '(', ')', '[', ']',
	'{', '}', '+', '-', '`', '"', ':', ';', '<', '>', '.', ',' };
	vector<char> digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	string password;

	// Obtain a seed from a truly random source (if available)
	random_device rd;

	// Create a Mersenne Twister engine and seed it
	mt19937 gen(rd());

	// Define a uniform integer distribution
	uniform_int_distribution<> dis(1, specialchars.size());
	// cout << dis(gen) << endl;
	password = password + specialchars.at(dis(gen));

	uniform_int_distribution<> dis2(1, digits.size());
	// cout << dis2(gen) << endl;
	password = password + digits.at(dis2(gen));

	uniform_int_distribution<> dis3(1, words.size());
	// cout << dis3(gen) << endl;
	password = password + words.at(dis3(gen));

	cout << "Your generated password is: " + password << endl;
}

int main() {
	vector<string> keywords;
	string temp;
	cout << "Hello! I am going to help you find a password that you will remember!" << endl;
	cout << "First, answer these questions.\n" << endl;
	cout << "Enter the birth year of the oldest person in your family:" << endl;
	cin >> temp;
	keywords.push_back(temp);
	cout << "Enter the last name of your favorite artist/musician:" << endl;
	cin >> temp;
	keywords.push_back(temp);
	cout << "Enter the name of the first school you attended:" << endl;
	cin >> temp;
	keywords.push_back(temp);

	algorithm(keywords);
	cout << "Run again to generate a new password." << endl;
}