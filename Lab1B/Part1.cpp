/*
Hubert Bukowski | x00161897 - CREATOR

Worked with:
Jibril Abdulazeez | x00164441
Darius Crisan | x00165316
Stephen Clarke | x00167225
Daniel Cullen | x00168408

*/
#include <iostream>
#include <random>
#include <ctime>

int main()
{
	int numIterations;
	int birthdays[50];
	std::default_random_engine defEngine(time(0));
	std::uniform_int_distribution<int> intDistro(1, 365);
	std::cout << "Enter number of iterations: " << std::endl;
	std::cin >> numIterations;

	// Loop for 2-50 people, calculating the probability for each person each time
	for (int peopleCount = 2; peopleCount <= 50; peopleCount++) {
		int numMatches = 0;
		// Loop for the amount of specified iterations
		for (int iteration = 0; iteration < numIterations; iteration++) {
			bool birthdayMatches = false;
			// Assign random birthdays to the amount of people currently in the loop
			for (int person = 0; person < peopleCount; person++) {
				birthdays[person] = intDistro(defEngine);
			}
			// Loops for each person twice and compare birthdays to find matches
			for (int person = 0; person < peopleCount; person++) {
				for (int person2 = 0; person2 < peopleCount; person2++) {
					if (person != person2) { // Only compare values with different indexes
						if (birthdays[person] == birthdays[person2]) {
							birthdayMatches = true;
						}
					}
				}
			}
			// If there was a match in this iteration, increment number of matches
			if (birthdayMatches) {
				numMatches++;
			}
		}
		std::cout << "For " << peopleCount << " people, the probability of two birthdays is about " << float(numMatches) / float(numIterations) << std::endl;
	}
	return 0;
}