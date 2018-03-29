#include<iostream>
#include<string>
using namespace std;

void calculation(string name, string surname, double mt1, double mt2, double Final, double hw);
void grading(double courseAverage, string name, string surname);
void checkInputFunction(string name, string surname, double mt1, double mt2, double Final, double hw);

void inputFunction(string name, string surname) // This function gets information from user
{
	double mt1, mt2, Final, hw;
	cout << name << surname << ", please enter your midterm and final grades:";
	cin >> mt1 >> mt2 >> Final;
	cout << endl << name << surname << ", please enter the average score of your homeworks:";
	cin >> hw;
	checkInputFunction(name, surname, mt1, mt2, Final, hw);


}

void checkInputFunction(string name, string surname, double mt1, double mt2, double Final, double hw) // Check the input values 
{
	if (mt1 < 0 || mt2 < 0 || Final < 0)
		cout << name << surname << ", your exam grades cannot be below 0, we aren't that harsh" << endl; // 

	else if (mt1 > 100 || mt2>100 || Final>100)
		cout << name << surname << ", over 100 point in an exam? We don't give bonuses, we aren't that nice either" << endl; // put limits for exam grades as 0<=grades<=100

	else if (hw < -100)
	{
		cout << name << surname << ", we never give less than -100 in a homework, sorry" << endl;
	}
	else if (hw > 100)
	{
		cout << name << surname << ", your homework grade cannot be more than 100, we never give out bonuses in a homework, sorry" << endl; // put limits for exam grades as -100<=grades<=100
	}
	else
	{
		calculation(name, surname, mt1, mt2, Final, hw);
	}

}

void calculation(string name, string surname, double mt1, double mt2, double Final, double hw) // Calculate the values and find course and exam average
{
	double courseAverage = (mt1 + mt2) * 0.25 + Final * 0.35 + hw * 0.15;
	double examAverage = ((mt1 + mt2) * 0.25 + Final * 0.35) / 0.85;
	
	if ((mt1 + mt2) < 40)
		cout << name << surname << ", your lack of grades in your midterms disturbs me: You get F" << endl;
	else if (Final < 20)
		cout << name << surname << ", your lack of grades in your final disturbs me: You get F" << endl;
	else if (examAverage < 35)
		cout << name << surname << ", your lack of average grades disturbs me: You get F" << endl; // put three special condition for grades 
	else if (hw > 2 * examAverage) // this part is important. If homework average is larger than the double of the exam average, then the grade will be lowered by a letter grade.
	{
		cout << name << surname << ", unfortunately your grade will be lowered" << endl;

	if ((courseAverage <= 70) && (courseAverage > 60))
		cout << name << surname << ", you get C" << endl;
	else if ((courseAverage <= 60) && (courseAverage > 55))
		cout << name << surname << ", you get C-" << endl;
	else if ((courseAverage <= 55) && (courseAverage > 50))
		cout << name << surname << ", you get D+" << endl;
	else if ((courseAverage <= 50) && (courseAverage > 45))
		cout << name << surname << ", you get D" << endl;
	else if ((courseAverage <= 45) && (courseAverage > 40))
		cout << name << surname << ", you get F" << endl;
	}


	else
	{
		grading(courseAverage, name, surname);
	}

}


void grading(double courseAverage, string name, string surname) // grade for normal situation
{
	
	if (courseAverage > 90)
		cout << name << surname << ", you get A" << endl;
	else if ((courseAverage <= 90) && (courseAverage > 85))
		cout << name << surname << ", you get A-" << endl;
	else if ((courseAverage <= 85) && (courseAverage > 80))
		cout << name << surname << ", you get B+" << endl;
	else if ((courseAverage <= 80) && (courseAverage > 75))
		cout << name << surname << ", you get B" << endl;
	else if ((courseAverage <= 75) && (courseAverage > 70))
		cout << name << surname << ", you get B-" << endl;
	else if ((courseAverage <= 70) && (courseAverage > 60))
		cout << name << surname << ", you get C+" << endl;
	else if ((courseAverage <= 60) && (courseAverage > 55))
		cout << name << surname << ", you get C" << endl;
	else if ((courseAverage <= 55) && (courseAverage > 50))
		cout << name << surname << ", you get C-" << endl;
	else if ((courseAverage <= 50) && (courseAverage > 45))
		cout << name << surname << ", you get D+" << endl;
	else if ((courseAverage <= 45) && (courseAverage > 40))
		cout << name << surname << ", you get D" << endl;
	else 
		cout << name << surname << ", you failed this course: F" << endl;
}

int main()
{
	string name, surname;
	cout << "This program is my Grade Calculater Program!" << endl;

	cout << "Please enter your name and surname:";
	cin >> name >> surname;

	inputFunction(name, surname);

	cout << "Please enter your name and surname:";
	cin >> name >> surname;

	inputFunction(name, surname);

	return 0;
}