#include <iostream>
#include <vector>

using namespace std;

struct Time{
  string day,
    month;
  int date;
};

struct Movie{
 string title,
   duration,
   rating;
 vector<string> time;
 vector<string> genre;
 int price;
};

struct Seat{
  char alphabet;
  int number;
  bool isAvailable;
};

struct Ticket{
  string name,
    movieTitle,
    movieTime;
  vector<Seat> seats;
  Time time;
  int quantity,
    price;
};

vector<string> days{
  "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat",
};

vector<string> months{
  "Jan", "Feb", "Mar", "Apr", "Mei", "Jun", "Jul", "Aug", "Sep", "Okt", "Nov", "Des",
};

vector<Movie> movies{
  {
    "Avatar: The Way of Water (2022)", "192 Menit", "PG-13",
    {"7:00", "13:00", "16:00"},
    {"Action", "Adventure", "Fantasy"},
    30000
  },
  {
    "Puss in Boots: The Last Wish (2022)", "102 Menit", "PG",
    {"7:15", "13:15"},
    {"Adventure", "Animation", "Comedy"},
    25000,
  },
  {"The Invitation (2022)", "102 Menit", "PG-13",
    {"7:30", "13:30", "16:30", "20:30"},
    {"Horror", "Thriller"},
    25000,
  },
};

vector<char> alphabets{
 'A', 'B', 'C', 'D', 'E', 'F',
};

vector<vector<Seat>> seats;

Ticket ticket;

void ReadMovieDetails(Movie detail) {
 cout << "==== Movie Details ====\n\n";
 cout << "Title\t\t:\t" << detail.title << "\n";
 cout << "Duration\t:\t" << detail.duration << "\n";
 cout << "Time\t\t:";
 for (int i = 0; i < detail.time.size(); i++) {
   cout << (i == 0 ? "\t" : "\t\t\t") <<  i + 1 << ". " << detail.time[i] << "\n";
 }

 cout << "Genre\t\t:";
 for (int i = 0; i < detail.genre.size(); i++) {
   cout << (i == 0 ? "\t" : "\t\t\t") <<  i + 1 << ". " << detail.genre[i] << "\n";
 }

 cout << "Rating\t\t:\t" << detail.rating << "\n";
 cout << "Price\t\t:\tRp " << detail.price << "\n\n";
}

void CreateSeats() {
 if (seats.size() == 0) {
   for (char alphabet : alphabets) {
     vector<Seat> row;

     for (int i = 0; i < alphabets.size(); i++) {
       row.push_back({alphabet, i + 1, true});
     }

     seats.push_back(row);
   }
 }
}

void ReadSeats() {
  for (auto & row : seats) {
    for (auto & column : row) {
      cout << column.alphabet << column.number << (column.isAvailable ? "" : "*") << " ";
    }
      
    cout << "\n";
  }
}

void ReadTicketDetails(Ticket detail) {
  cout << "==== Ticket Details ====\n\n";
  cout << "Name\t\t\t:\t" << detail.name << "\n";
  cout << "Title\t\t\t:\t" << detail.movieTitle << "\n";
  cout << "Day of date\t\t:\t" << detail.time.day << ", " << detail.time.date << "--" << detail.time.month << "\n";
  cout << "Time\t\t\t:\t" << detail.movieTime << "\n";
  cout << "Quantity\t\t:\t" << ticket.quantity << "\n";
  cout << "Seats\t\t\t:\t";
  for (int i = 0; i < detail.seats.size(); i++) {
    cout << detail.seats[i].alphabet << detail.seats[i].number << ", ";
  }

  cout << "\nPrice\t\t\t:\tRp " << detail.price << " vc" << "\n";
  cout << "Total price\t\t:\tRp " << detail.price * detail.quantity << "\n";
}

int main() {
  int movieNumber, watchingDate, watchingDay, watchingMonth, movieTimeNumber, quantity, columnSeat;
  char rowSeat, repeat;
  string name;

  name:
    cout << "================ Welcome to Cinema ================\n\n";

    cout << "Enter a name : ";
    getline(cin, name);

    if (!name.empty()) {
      ticket.name = name;
    } else {
      system("cls");
      goto name;
    }

  day:
    cout << "Enter the day (" << days.front() << "[1] - " << days.back() << "[" << days.size() << "]) *use day number* : ";
    cin >> watchingDay;

    if (watchingDay > 0 && watchingDay <= days.size()) {
      ticket.time.day = days[watchingDay - 1];
    } else {
      system("cls");
      goto day;
    }

  date:
    cout << "Enter the date (1 - 32) : ";
    cin >> watchingDate;
    
    if (watchingDate > 0 && watchingDate <= 32) {
      ticket.time.date = watchingDate;
    } else {
      system("cls");
      goto date;
    }

  month:
    cout << "Enter the month (" << months.front() << "[1] - " << months.back() << "[" << months.size() << "]) *use month number* : ";
    cin >> watchingMonth;

    if (watchingMonth > 0 && watchingMonth <= months.size()) {
      ticket.time.month = months[watchingMonth - 1];
    } else {
      system("cls");
      goto month;
    }
    
    cout << ticket.name << "\n";
    cout << ticket.time.day << "\n";
    cout << ticket.time.date << "\n";
    cout << ticket.time.month << "\n";

    system("cls");

  movie:
    cout << "==== Movie List ====\n\n";

    for (int i = 0; i < movies.size(); i++) {
      cout << i + 1 << ". " << movies[i].title << "\n";
    }

    cout << "\nSelect a movie (1 - " << movies.size() << ") : ";
    cin >> movieNumber;
    ticket.movieTitle = movies[movieNumber - 1].title;
    ticket.price = movies[movieNumber - 1].price;

    system("cls");

    if ((movieNumber > 0 && movieNumber <= movies.size())) {
      ReadMovieDetails(movies[movieNumber - 1]);

      cout << "Select time (1 - " << movies[movieNumber - 1].time.size() << ") : ";
      cin >> movieTimeNumber;
      ticket.movieTime = movies[movieNumber - 1].time[movieTimeNumber - 1];

      system("cls");

      cout << "Quantity : ";
      cin >> quantity;
      ticket.quantity = quantity;

      cout << "\n";

      CreateSeats();
      ReadSeats();

      for (int i = 0; i < quantity; i++) {
        cout << "\nMasukkan baris kursi " << i + 1 << " : ";
        cin >> rowSeat;

        cout << "Masukkan angka kursi " << i + 1 << " : ";
        cin >> columnSeat;

        for (auto & row : seats) {
          for (auto & column : row) {
            if (rowSeat == column.alphabet) {
              if (columnSeat == column.number) {
                column.isAvailable = false;
                ticket.seats.push_back({rowSeat, columnSeat});
              }
            }
          }
        }
      }
    } else {
      goto movie;
    }

  system("cls");

  ReadTicketDetails(ticket);

  cout << "\nYou wanna buy another ticket? (y/t) : ";
  cin >> repeat;

  cin.get();

  if (repeat == 'y') {
    system("cls");
    goto name;
  }
}