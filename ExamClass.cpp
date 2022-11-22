#include <iostream>
#include "ExamClass.h"


ExamClass::ExamClass() {
	studentName = "Undefined";
	exam1Score = 0.0;
	exam2Score = 0.0;
	exam3Score = 0.0;
	setStudentAverage();
}

ExamClass::ExamClass(float e1, float e2, float e3, std::string name) {
	studentName = name;
	exam1Score = e1;
	exam2Score = e2;
	exam3Score = e3;
	setStudentAverage();
}

//set student names
void ExamClass::setStudentName(std::string name) {
	studentName = name;
}

//set student exam scores
void ExamClass::setExamScores(float e1, float e2, float e3) {
	exam1Score = e1;
	exam2Score = e2;
	exam3Score = e3;
	setStudentAverage();
}

//set student average
void ExamClass::setStudentAverage() {
	studentAverage = (exam1Score + exam2Score + exam3Score) / (float)3.0;
}

//get student names
std::string ExamClass::getStudentName() {
	return studentName;
}

//get student exam scores
//convenience for class average function
float ExamClass::getExamScoresTotal() {
	return exam1Score + exam2Score + exam3Score;
}

//get student average
float ExamClass::getStudentAverage() {
	return studentAverage;
}