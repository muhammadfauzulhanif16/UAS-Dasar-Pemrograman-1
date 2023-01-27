#ifndef CREATE_TICKET_H
#define CREATE_TICKET_H

#include "./ReadMovieDetails.h"
#include "./ReadTicketDetails.h"
#include "./ReadSeats.h"

void CreateTicket(Movie detail) {
  int movieTimeNumber, quantity, columnSeat;
  char rowSeat;

  ReadMovieDetails(detail);

  cout << "Select time (1 - " << detail.time.size() << ") : ";
  cin >> movieTimeNumber;

  system("cls");

  cout << "Quantity : ";
  cin >> quantity;

  cout << "\n\n";
  ReadSeats();
  cout << "\n";

  for (int i = 0; i < quantity; i++) {
    cout << "Masukkan baris kursi " << i + 1 << " : ";
    cin >> rowSeat;

    cout << "Masukkan angka kursi " << i + 1 << " : ";
    cin >> columnSeat;

//    for (int j = 0; j < seats.size(); i++) {
//      for (int k = 0; k < seats[j].size(); i++) {
//        if (rowSeat == seats[j][k].alphabet) {
//          if (columnSeat == seats[j][k].number) {
//            seats[j][k].isAvailable = false;
//            ticket.seats.push_back({rowSeat, columnSeat});
//          }
//        }
//      }    
//    }

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
  

  ticket.time = detail.time[movieTimeNumber - 1];
  ticket.quantity = quantity;
  ticket.title = detail.title;
  ticket.price = detail.price;

  system("cls");

  ReadTicketDetails(ticket);
}

#endif
