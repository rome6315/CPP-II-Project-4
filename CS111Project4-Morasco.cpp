#include <fstream>

#include "ExamClass.h"


//Pre-condition: exams is an empty vector
//Post-condition: exams is populated with data from the file
void readData(std::vector<ExamClass> &exams); //must pass by reference 

//Pre-condition: exams is a populated vector
//Post-condition: The class average is returned by using the object data in the exams vector
float classAverage(std::vector<ExamClass> exams);

//Pre-condition: exams is fully populated and the class average has been calculated
//Post-condition: prints the class average as well as the students name, average, and if they scored above the class average
void printResults(std::vector<ExamClass> exams, float classAverage);

int main(void) {
	std::vector<ExamClass> exams;
	float classAvg = 0.0;


	readData(exams); //read in data from file

	classAvg = classAverage(exams); //set class average

	printResults(exams, classAvg); //print the results of each student

	

	return 0;
}

void readData(std::vector<ExamClass> &exams) {
	//declaring variables that will be read in and passed into the class setters in the while loop below
	std::string name = "Undefined";
	float e1 = 0.0, e2 = 0.0, e3 = 0.0;

	std::ifstream inputFile; //declaring input file stream variable

	//opening file
	inputFile.open("data.txt");

	//check to see if file opened
	if (inputFile.fail()) {
		std::cout << "File did not open. \n"; //Display to user
		exit(1); //exits with error code 1
	}

	//checks to see if the file peek is also the same as the end of file, in which case there would be no content in the file
	if (inputFile.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "File is empty. \n"; //Display to user
		exit(1); //exits with error code 1
	}

	//while loop to input from the file until theres nothing left to input
	while (inputFile >> name >> e1 >> e2 >> e3) {
		ExamClass student(e1, e2, e3, name); //new object of ExamClass class
		//student.setStudentName(name); //set name of student
		//student.setExamScores(e1, e2, e3); //set their exam scores and average

		exams.push_back(student); //add this object to the vector
	}

	//closing file
	inputFile.close();
}

//calculates class average
float classAverage(std::vector<ExamClass> exams) {
	float totalClassScore = 0.0;
	int numTests = 0;

	for (int i = 0; i < exams.size(); i++) {
		totalClassScore += exams[i].getExamScoresTotal(); //gets the total of the students exam scores added up for this indice
		numTests += 3; //keeps track of total number of tests, 3 per student
	}

	return totalClassScore / (float)numTests; //return every score in the class added up divided by the number of total tests taken in the class
}

void printResults(std::vector<ExamClass> exams, float classAverage) {
	//output class average and the colkumn titles (student name and student average)
	std::cout << std::fixed << std::setprecision(2) << "Class average: " << classAverage << std::endl << std::endl;
	std::cout << "Name: " << "\t   Student Average: " << std::endl;
	std::cout << "-------------------------------------\n"; //formatting

	for (int i = 0; i < exams.size(); i++) {
		std::cout << std::fixed << std::setprecision(2); //setting precision for output statements
		std::cout << std::left << std::setw(15) << exams[i].getStudentName(); //output student names with the setw coming after the name
		std::cout << std::right << std::setw(10) << exams[i].getStudentAverage(); //output student average with setw coming before the average

		if (exams[i].getStudentAverage() > classAverage) { //if the student scored above the class average, ouput the statement below:
			std::cout << "\tAbove average \n"; //ouput above average if they scored above average
		}
		else {
			std::cout << std::endl; //even if they were below average, still got to start a new line
		}
	}
}