#include <iostream>
using namespace std;
const int MAX_SCORES = 10;

void inputScores(int scores[], int& count);
void displayScores(const int scores[],int count);
double calculateAverage(const int scores[], int count);

int main(){
	int scores[MAX_SCORES];
	int count = 0;
	
	inputScores(scores, count);
	displayScores(scores, count);
	
	double average = calculateAverage(scores, count);
	cout << "Average score: " << average << endl;
	
	return 0;
}

void inputScores(int scores[], int& count) {
	cout << "Enter up to " << MAX_SCORES << " golf scores (or a negative number to finish):"<<endl;
	for (int i = 0; i< MAX_SCORES; ++i){
		cin >> scores[i];
		if (scores[i]<0){
			count = i;
			return;
		}
	}
	count = MAX_SCORES;
}
void displayScores(const int scores[],int count){
	cout << "Scores: ";
	for (int i =0; i < count ; ++i){
		cout << scores[i] << " ";
	}
	cout << endl;
}
double calculateAverage(const int scores[], int count){
	if (count == 0) {
		return 0.0;
	}
	int sum =0;
	for (int i = 0; i < count; ++i){
		sum += scores[i];
	}
	return static_cast <double> (sum)/count;
}
