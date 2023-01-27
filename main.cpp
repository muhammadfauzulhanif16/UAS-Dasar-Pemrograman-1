#include <iostream>
#include <vector>

#include "./data/ticket.cpp"
#include "./data/movies.cpp"
// #include "./data/seats.cpp"
#include "./data/days.cpp"
#include "./data/watchingDates.cpp"
#include "./data/months.cpp"

#include "./service/CreateTicket.h"
#include "./service/ReadSeats.h"
#include "./service/CreateTime.h"
#include "./service/CreateDate.h"

using namespace std;

vector<int> watchingDates;

void CreateDate() {
  for (int i = 1; i <= 32; i++) {
    watchingDates.push_back(i);
  }
}

int main() {
    int movieNumber, watchingDate, watchingDay, watchingMonth;
    string buyerName;
    char menu;

    // CreateDate();

    //  ReadSeats();
    begin:
      ticket.seats.clear();
      cout << "================ Welcome to Cinema ================\n\n";

      cout << "Enter a name : ";
      getline(cin, buyerName);

    // day:
    //   cout << "Enter the day (" << days[0] << " - " << days[6] << ") : ";
    //   cin >> watchingDay;

    //   if (watchingDay > 0 && watchingDay <= days.size()) {
    //     cout << days[watchingDay - 1];
    //   } else {
    //     system("cls");
    //     goto day;
    //   }

    // date:
    // cout << "Enter the date (1 - " << watchingDates.size() << ") : ";
    // cin >> date;
    //
    //  if (date > 0 && date <= watchingDates.size()) {
    //    cout << date;
    //  } else {
    //    cout << "Tidak ada pilihan tanggal!";
    //  }

    //  cout << "Enter the month (" << months[0] << " - " << months[11] << ") : ";
    //  cin >> month;

    //  CreateTime(day, date, month);
    // ticket.wacthingTime.day = watchingDays;
    // ticket.wacthingTime.date = date;
    // ticket.wacthingTime.month = month;

    // cout << ticket.wacthingTime.day;

     ticket.buyerName = buyerName;
    //  ticket.date = date;

    system("cls");

    if (!buyerName.empty()) {
      cout << "==== Movie List ====\n\n";

      for (int i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i].title << "\n";
      }

      cout << "\nSelect a movie (1 - " << movies.size() << ") : "; cin >> movieNumber;

      system("cls");

      if (movieNumber > 0 && movieNumber <= movies.size()) {
        CreateTicket(movies[movieNumber - 1]);
      } else {
        cout << "No movie options!";
      }
    } else {
      cout << "Please fill in the " << (buyerName.empty() ? "name & time watching" : buyerName.empty() ? "name" : "time watching") << " correctly!\n";
    }

    cout << "\nKembali ke menu? (y/t) : ";
    cin >> menu;

    cin.get();
    system("cls");

    if (menu == 'y') goto begin;

}

  
  