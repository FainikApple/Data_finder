#include <iostream>
using namespace std;
int finder(int month_1, int day_1, int year_1){
    month_1 = month_1 % 12;
    if (month_1 == 0){
        month_1 = 12;
    }
    if (day_1 > 31 && (month_1 == 1 || month_1 == 3 || month_1 == 5 || month_1 == 7 || month_1 == 8 || month_1 == 10 || month_1 == 12)){
        return day_1-31;
    }
    else if (day_1 > 30 && (month_1 == 4 || month_1 == 6 || month_1 == 9 || month_1 == 11)){
        return day_1-30;
    }
    else if(day_1 > 29 && month_1 == 2 && year_1 % 4 == 0 && (year_1 % 100 != 0 || year_1 % 100 == 0 && year_1 % 400 == 0)){
            return day_1-29;
    }
    else if(day_1 > 28 && month_1 == 2 && (year_1 % 4 != 0 || (year_1 % 100 == 0 && year_1 % 400 != 0))){
        return day_1-28;
    }
    else{
        return 0;
    }
}

int sigma_function(int day_1){
    if (day_1 % 10 == 1){
        cout << "st";
    }
    else if (day_1 % 10 == 2){
        cout << "nd";
    }
    else if (day_1 % 10 == 3){
        cout << "rd";
    }
    else{
        cout << "th";
    }
}

int sklonenie(int date){
    int ost = date % 10;
    int ost_100 = date % 100;
    if (ost == 1 && ost_100 != 11){
        return 0;
    }
    else if(4 < date && date < 21 || ost == 0 || ost == 5 || ost == 6 || ost == 7 || ost == 8 || ost == 9 || ost_100 == 11 || ost_100 == 12 || ost_100 == 13 || ost_100 == 14){
        return 1;
    }
    else if (ost == 2 || ost == 3 || ost == 4){
        return 2;
    }
}

int months_eng(int month){
    if (month == 1){
        cout << " January ";
    }
    if (month == 2){
        cout << " February ";
    }
    if (month == 3){
        cout << " March ";
    }
    if (month == 4){
        cout << " April ";
    }
    if (month == 5){
        cout << " May ";
    }
    if (month == 6){
        cout << " June ";
    }
    if (month == 7){
        cout << " July ";
    }
    if (month == 8){
        cout << " August ";
    }
    if (month == 9){
        cout << " September ";
    }
    if (month == 10){
        cout << " October ";
    }
    if (month == 11){
        cout << " November ";
    }
    if (month == 12){
        cout << " December ";
    }

}
int months_ru(int month){
    if (month == 1){
        cout << " Января ";
    }
    if (month == 2){
        cout << " Февраля ";
    }
    if (month == 3){
        cout << " Марта ";
    }
    if (month == 4){
        cout << " Апреля ";
    }
    if (month == 5){
        cout << " Мая ";
    }
    if (month == 6){
        cout << " Июня ";
    }
    if (month == 7){
        cout << " Июля ";
    }
    if (month == 8){
        cout << " Августа ";
    }
    if (month == 9){
        cout << " Сентября ";
    }
    if (month == 10){
        cout << " Октября ";
    }
    if (month == 11){
        cout << " Ноября ";
    }
    if (month == 12){
        cout << " Декабря ";
    }
}

int wow(string lang, int ch, int d, int m, int y, int h, int mi, int s, int d_1, int m_1, int y_1, int h_1, int mi_1, int s_1){
    int ost;
    int ost_100;
    int day_1;
    int month_1;
    int year_1;
    int hour_1;
    int minute_1;
    int seconds_1;
    int choice = ch;

    //ВРЕМЯ "НАЗАД"
    day_1 = d-d_1;
    month_1 = m-m_1;
    year_1 = y-y_1;
    hour_1 = h-h_1;
    minute_1 = mi-mi_1;
    seconds_1 = s-s_1;

    if (day_1<0){
        day_1 = day_1 * -1;
    }
    if (month_1<0){
        month_1 = month_1 * -1;
    }
    if (year_1<0){
        year_1 = year_1 * -1;
    }
    if (hour_1<0){
        hour_1 = hour_1 * -1;
    }
    if (minute_1<0){
        minute_1 = minute_1 * -1;
    }
    if (seconds_1<0){
        seconds_1 = seconds_1 * -1;
    }
    if (seconds_1 > 59){
        minute_1 = minute_1 + seconds_1/60;
        seconds_1 = seconds_1 %60;
    }
    if (minute_1 > 59){
        hour_1 = hour_1 + minute_1/60;
        minute_1 = minute_1 %60;
    }
    if (hour_1 > 23){
        day_1 = day_1 + hour_1 / 24;
        hour_1 = hour_1 % 24;
    }
     while (finder(month_1, day_1, year_1)!= 0){
            day_1 = finder(month_1,day_1,year_1);
            month_1++;
    }
    if (month_1 > 12){
        year_1 = year_1 + month_1/12;
        month_1 = month_1 %12;
    }

    //ДНИ
    switch(choice){
    case 1:
        if (lang == "ru"){
            cout << day_1;
            switch(sklonenie(day_1)){
            case 0:
                cout<<" день ";
                break;
            case 1:
                cout<<" дней ";
                break;
            case 2:
                cout<< " дня ";
                break;
            default:
                cout<<"не бывает";
                break;
            }
            //МЕСЯЦЫ
            cout << month_1;
            switch(sklonenie(month_1)){
            case 0:
                cout<<" месяц ";
                break;
            case 1:
                cout<<" месяцев ";
                break;
            case 2:
                cout<< " месяца ";
                break;
            default:
                cout<<"не бывает";
                break;
            }

            //ГОДА
            cout << year_1;
            switch(sklonenie(year_1)){
            case 0:
                cout<<" год ";
                break;
            case 1:
                cout<<" лет ";
                break;
            case 2:
                cout<< " года ";
                break;
            default:
                cout<<"не бывает";
                break;
            }


            //ЧАСЫ
            cout << hour_1;
            switch(sklonenie(hour_1)){
            case 0:
                cout<<" час ";
                break;
            case 1:
                cout<<" часов ";
                break;
            case 2:
                cout<< " часа ";
                break;
            default:
                cout<<"не бывает";
                break;
            }


            //МИНУТЫ
            cout << minute_1;
            switch(sklonenie(minute_1)){
            case 0:
                cout<<" минута ";
                break;
            case 1:
                cout<<" минут ";
                break;
            case 2:
                cout<< " минуты ";
                break;
            default:
                cout<<"не бывает";
                break;
            }


            //СЕКУНДЫ
            cout << seconds_1;
            switch(sklonenie(seconds_1)){
            case 0:
                cout<<" секунда ";
                break;
            case 1:
                cout<<" секунд ";
                break;
            case 2:
                cout<< " секунды ";
                break;
            default:
                cout<<"не бывает";
                break;
        }

        cout << "назад" << endl;
        }
        else{
            cout << year_1;
            if (year_1 == 1){
                cout << " year ";
            }
            else{
                cout << " years ";
            }

            cout << month_1;
            if (month_1 == 1){
                cout << " month ";
            }
            else{
                cout << " months ";
            }

            cout << day_1;
            if (day_1 == 1){
                cout << " day ";
            }
            else{
                cout << " days ";
            }

            cout << hour_1;
            if (hour_1 == 1){
                cout << "hour";
            }
            else{
                cout << " hours ";
            }

            cout << minute_1;
            if (minute_1 == 1){
                cout << " minute ";
            }
            else{
                cout << " minutes ";
            }

            cout << seconds_1;
            if (seconds_1 == 1){
                cout << " second ";
            }
            else{
                cout << " seconds ";
            }

            cout << "ago";
        }
        break;
    case 2:
        if(lang == "ru"){
            cout << day_1;
            months_ru(month_1);
            cout << year_1;
            cout << " года";
            cout << " в " << hour_1 << " часов ";
            cout << minute_1 << " минут ";
            cout << seconds_1 << " секунд ";
            }
        else{
            cout << "The ";
            cout << day_1;
            sigma_function(day_1);
            cout << " of";
            months_eng(month_1);
            cout << "of ";
            cout << year_1;
            cout << " ";
            cout << hour_1;
            if (0 > hour_1 & hour_1 < 2){
                cout << "hour";
            }
            else{
                cout << " hours ";
            }
            cout << minute_1;
            if (0 < minute_1 & minute_1 < 2){
                cout << " minute ";
            }
            else{
                cout << " minutes ";
            }
            cout << seconds_1;
            if (0 < seconds_1 & seconds_1 < 2){
                cout << " second ";
            }
            else{
                cout << " seconds ";
            }
        }
        break;
    default:
        cout << "клавиатараоаврыапрврпыфарпдвымывпф";
        break;
    }
    if(day_1 == 15 & month_1 == 5 & year_1 == 2012 & hour_1 == 6 & minute_1 == 30 & seconds_1 == 0){
        cout<<"My official bday.";
    }
    if(day_1 == 11 & month_1 == 9 & year_1 == 2001 & hour_1 == 9 & minute_1 == 36 & seconds_1 == 18){
        cout<<"This was indeed a 'Planie crushie' day.";
    }
}
int main(){
    setlocale(LC_ALL, "Russian");
    int day = 0;
    int month = 0;
    int year = 0;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int day_1;
    int month_1;
    int year_1;
    int hours_1;
    int minutes_1;
    int seconds_1;
    int choice;
    string language;

    cin >> language;
    cin >> choice;
    cin >> day_1;
    cin >> month_1;
    cin >> year_1;
    cin >> hours_1;
    cin >> minutes_1;
    cin >> seconds_1;
    wow(language, choice, day, month, year, hours, minutes, seconds, day_1, month_1, year_1, hours_1, minutes_1, seconds_1);
}
//https://youtu.be/-5wpm-gesOY?si=ILeHpNuHFNuAx7a7
