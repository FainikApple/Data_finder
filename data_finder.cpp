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

int months(int month){
    if (month == 1){
        cout << " €нвар€ ";
    }
    if (month == 2){
        cout << " феврал€ ";
    }
    if (month == 3){
        cout << " марта ";
    }
    if (month == 4){
        cout << " апрел€ ";
    }
    if (month == 5){
        cout << " ма€ ";
    }
    if (month == 6){
        cout << " июн€ ";
    }
    if (month == 7){
        cout << " июл€ ";
    }
    if (month == 8){
        cout << " августа ";
    }
    if (month == 9){
        cout << " сент€бр€ ";
    }
    if (month == 10){
        cout << " окт€бр€ ";
    }
    if (month == 11){
        cout << " но€бр€ ";
    }
    if (month == 12){
        cout << " декабр€ ";
    }

}

int wow(int ch, int d, int m, int y, int h, int mi, int s, int d_1, int m_1, int y_1, int h_1, int mi_1, int s_1){
    int ost;
    int ost_100;
    int day_1;
    int month_1;
    int year_1;
    int hour_1;
    int minute_1;
    int seconds_1;
    int choice = ch;

    //¬–≈ћя "Ќј«јƒ"
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

    //ƒЌ»
    switch(choice){
    case 1:
        cout << day_1;
        switch(sklonenie(day_1)){
        case 0:
            cout<<" день ";
            break;
        case 1:
            cout<<" дней ";
            break;
        case 2:
            cout<< " дн€ ";
            break;
        default:
            cout<<"не бывает";
            break;
        }
        //ћ≈—я÷џ
        cout << month_1;
        switch(sklonenie(month_1)){
        case 0:
            cout<<" мес€ц ";
            break;
        case 1:
            cout<<" мес€цев ";
            break;
        case 2:
            cout<< " мес€ца ";
            break;
        default:
            cout<<"не бывает";
            break;
        }

        //√ќƒј
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


        //„ј—џ
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


        //ћ»Ќ”“џ
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


        //—≈ ”Ќƒџ
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
        break;
    case 2:
        cout << day_1;
        months(month_1);
        cout << year_1;
        cout << " года";
        cout << " в " << hour_1 << " часов ";
        cout << minute_1 << " минут ";
        cout << seconds_1 << " секунд ";
        break;
    default:
        cout << "клавиатараоаврыапрврпыфарпдвымывпф";
        break;
    }
    if(day_1 == 15 & month_1 == 5 & year_1 == 2012 & hour_1 == 6 & minute_1 == 30 & seconds_1 == 0){
        cout<<"My official bday.";
    }
    if(day_1 == 11 & month_1 == 9 & year_1 == 2001 & hour_1 == 9 & minute_1 == 36 & seconds_1 == 18){
        cout<<"Planie crushie :P";
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

    cin >> choice;
    cin >> day_1;
    cin >> month_1;
    cin >> year_1;
    cin >> hours_1;
    cin >> minutes_1;
    cin >> seconds_1;
    wow(choice, day, month, year, hours, minutes, seconds, day_1, month_1, year_1, hours_1, minutes_1, seconds_1);
}
//https://youtu.be/-5wpm-gesOY?si=ILeHpNuHFNuAx7a7
