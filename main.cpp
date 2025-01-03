/*Assignment:Norton Dental Office (COMP 218- Data Structures) (Assignment Number): 0
Author(s):Rylie Seaberg
Due Date: Friday, 09/13/2024 11:59:00 PM
Description: This project aims to make a stress-free and easy way for patients at the
 Norton Dental Office to make appointments for the year 2024. Patients can schedule ahead of
 time, and it will be kept track of.
Comments: When inputtiing the month for August (08) and September (09) instead of
 writing 09 for September, you must write 9. While writing the project I was receiving
 errors for invalid octal constant when the 0 was on front of it.
Honor Pledge: I have abided by the Wheaton Honor Code and
all work below was performed by Rylie Seaberg .*/


#include <iostream>
using namespace std;
#include <string>
#include <sstream>

class Calendar {
private:
    int currentDay;
    int currentMonth;
    int currentYear;

    int appointmentDay;
    int appointmentMonth;
    int appointmentYear;

    string currentDate = "1/1/2024";


public:
    /* Calendar: a default constructor setting the current date to January 1, 2024
    *   params: no parameters are taken
    *   returns: there is nothing being returned
    */
    Calendar() {
        currentDay = 1;
        currentMonth = 1;
        currentYear = 2024;
        /*
        appointmentDay;
        appointmentMonth;
        appointmentYear;
        */
    }

    /* Calendar: a default constructor setting the current date to January 1, 2024
    *   params: no parameters are taken
    *   returns: N/A
    */

    Calendar (string date){
        currentDate = date;
    }

    /* &operator<<: displays the date of the appointment in the "month, day, year" format
    *   params: stream variable and an instance of the class as the user defined type
    *   returns: a variable representing the date of the appointment
    */
    friend ostream &operator<<(ostream &co, Calendar c);

    /* &operator>>: takes user input of the current date in the "[m]/[dd]/[yyyy]" format
    *   params: stream variable and an instance of the class as the user defined type
    *   returns: a variable representing the current date
    */
    friend istream &operator>>(istream &is, Calendar &c);

    /* setCurrentDate: a setter function setting the current date variables of class calendar as
     * the user defined current date
    *   params: day: the number of which day in the month we are
     *   month: the number of what month we are currently in
     *   year: 2024, considering we can only make appointments in 2024
    *   returns: N/A
    */
    void setCurrentDate(int day, int month, int year) {
        if (isValidDate(day, month, year)) {
            currentDay = day;
            currentMonth = month;
            currentYear = year;
        }
    }

    /* setAppointmentDate: a setter function setting the user defined appointment date variables of class calendar as
     * the user defined current date
    *   params: day: the number of which day in the month the appointment will be in
     *   month: the number of what month the appointment will be in
     *   year: 2024, considering we can only make appointments in 2024
    *   returns: N/A
    */
    void setAppointmentDate(int day, int month, int year) {
        if (isValidDate(day, month, year)) {
            appointmentDay = day;
            appointmentMonth = month;
            appointmentYear = year;
        }
    }

    /* isValidDate: a function to test whether or not the date (appointment or current) is valid
     * (in 2024, the month number is in the frame 1-12, and the day is not under 1 or over 31)
     * the user defined current date
    *   params: day: the number of which day in the month the user defined
     *   month: the number of what month the user defined
     *   year: 2024, considering we can only make appointments in 2024
    *   returns: a boolean value determining if the date was valid or not for the requirements
    */
    bool isValidDate(int day, int month, int year) const {
        if (year != 2024) return false; // Only 2024
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false;
        return true;
    }


/*
 * take the current date and add the amount of months/days to the next appointment
 * @input: string, ahead ("XmonthsXdays")
 * @return: string representing the next appointment's date formatted: "01/01/2024"
 * */
    string operator+(string ahead) {
        //write january = 01, february = 02 etc.
        //number of days in each month is different,
        //store the number of days in each month in an array
        //can add months to months and days to days
        int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int aheadMonth;
        int aheadDays;
        char m;
        char d;

        int newMonth;
        int newDay;

        string newApp;

        stringstream ss(ahead);

        ss >> aheadMonth >> m >> aheadDays >> d;

        newMonth = aheadMonth + currentMonth;
        newDay = aheadDays + currentDay;

        int daysOver;

        string appointment;

        if (newDay > months[newMonth - 1]) {
            daysOver = newDay - months[newMonth - 1];
            newMonth++;
        }
        else{
            daysOver = currentDay + aheadDays;
        }

        appointmentMonth = newMonth;
        appointmentDay = daysOver;

        appointment = print_appt();

        return appointment;
    }

    /* print_today: a function allowing the current date to be printed in a "month, day, year" format
    *   params: N/A
    *   returns: a string that represents the current date in the format "month, day, year"
    */
    string print_today() {
        string today;

        string monthName;

        if (currentMonth == 01) {
            monthName = "January";
        } else if (currentMonth == 02) {
            monthName = "February";
        } else if (currentMonth == 03) {
            monthName = "March";
        } else if (currentMonth == 04) {
            monthName = "April";
        } else if (currentMonth == 05) {
            monthName = "May";
        } else if (currentMonth == 06) {
            monthName = "June";
        } else if (currentMonth == 07) {
            monthName = "July";
        } else if (currentMonth == 8) {
            monthName = "August";
        } else if (currentMonth == 9) {
            monthName = "September";
        } else if (currentMonth == 10) {
            monthName = "October";
        } else if (currentMonth == 11) {
            monthName = "November";
        } else if (currentMonth == 12) {
            monthName = "December";
        }
        else {
            cout << "This day is not in 2024" <<endl;
        }

        string day;

        if (currentDay == 1){
            day = to_string(currentDay) + "st";
        }
        else if (currentDay == 2){
            day = to_string(currentDay) + "nd";
        }
        else if (currentDay == 3){
            day = to_string(currentDay) + "rd";
        }
        else {
            day = to_string(currentDay) + "th";
        }

        today = monthName + " , " + day + ", 2024";
        return today;

    }

    /* print_today: a function allowing the appointment to be printed in a "month, day, year" format
    *   params: N/A
    *   returns: a string that represents the appointment date in the format "month, day, year"
    */
    string print_appt() {
        string appointment;

        string monthName;

        if (appointmentMonth == 01) {
            monthName = "January";
        } else if (appointmentMonth == 02) {
            monthName = "February";
        } else if (appointmentMonth == 03) {
            monthName = "March";
        } else if (appointmentMonth == 04) {
            monthName = "April";
        } else if (appointmentMonth == 05) {
            monthName = "May";
        } else if (appointmentMonth == 06) {
            monthName = "June";
        } else if (appointmentMonth == 07) {
            monthName = "July";
        } else if (appointmentMonth == 8) {
            monthName = "August";
        } else if (appointmentMonth == 9) {
            monthName = "September";
        } else if (appointmentMonth == 10) {
            monthName = "October";
        } else if (appointmentMonth == 11) {
            monthName = "November";
        } else if (appointmentMonth == 12) {
            monthName = "December";
        }
        else {
            cout << "This appointment is not in 2024" <<endl;
        }


        string day;

        if (appointmentDay == 1|| appointmentDay == 21 || appointmentDay == 31) {
            day = to_string(appointmentDay) + "st";
        } else if (appointmentDay == 2 || appointmentDay == 22) {
            day = to_string(appointmentDay) + "nd";
        } else if (appointmentDay == 3 || appointmentDay == 23) {
            day = to_string(appointmentDay) + "rd";
        } else {
            day = to_string(appointmentDay) + "th";
        }
        appointment = monthName + " , " + day + " , " + "2024";
        return appointment;
    }
};

istream& operator>> (istream& is, Calendar& c){
    is >> c.currentMonth;
    is.get();
    is >> c.currentDay;
    is.get();
    is >> c.currentYear;
    c.isValidDate(c.currentDay,c.currentMonth, c.currentYear );
    return is;
}

ostream& operator<< (ostream& co, Calendar c){
    co << c.print_appt() << endl;
    return co;
}


int main() {
    Calendar calendar;
    cout << "Welcome to Norton Dental!" << endl;
    cout << "Please enter today’s date to start in " << endl;
    cout << "Format: [mm]/[dd]/[yyyy]" << endl;
    cin >> calendar;

    cout << "Today is: " ;
    cout << calendar.print_today() << endl;
    cout << "When is your next appointment?" << endl;
    cout << "Format: [x]m[x]d" << endl;
    cout << "Example: 3m10d means in 3 months and 10 days" << endl;

    string days_str;
    cin >> days_str;

    cout << "Thank you for making your next appointment. "<< endl;
    cout << "We will see you on:";
    cout << calendar + days_str;
    cout << endl;


    return 0;
};
