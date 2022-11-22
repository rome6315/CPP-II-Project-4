#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class ExamClass {
private:
	std::string studentName;
	float exam1Score;
	float exam2Score;
	float exam3Score;
	float studentAverage;
	void setStudentAverage(); //set students average
public:
	//default constructor
	ExamClass();

	ExamClass(float e1, float e2, float e3, std::string name);

	//set student names
	void setStudentName(std::string name);
	//set student exam scores
	void setExamScores(float e1, float e2, float e3);

	//get student names
	std::string getStudentName();
	//get student exam scores
	float getExamScoresTotal();
	//get student average
	float getStudentAverage();

};
