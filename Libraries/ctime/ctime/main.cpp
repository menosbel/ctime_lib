#include <iostream>
#include <ctime>
using namespace std;

struct Date {
	int day, month, year;
};

Date today() {
	time_t rawtime;
	time(&rawtime);

	struct tm timeinfo;
	localtime_s(&timeinfo, &rawtime);

	Date aux;
	aux.year = timeinfo.tm_year + 1900;
	aux.month = timeinfo.tm_mon + 1;
	aux.day = timeinfo.tm_mday;

	return aux;
}

void show_date(Date date) {
	cout << date.day << "/" << date.month << "/" << date.year << endl;
}

int main()
{
	Date current;
	current = today();
	show_date(current);

	return 0;
}
