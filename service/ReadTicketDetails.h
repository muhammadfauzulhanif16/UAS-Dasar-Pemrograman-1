#ifndef READ_TICKET_DETAILS_H
#define READ_TICKET_DETAILS_H

void ReadTicketDetails(Ticket detail) {
  cout << "==== Ticket Details ====\n\n";
  cout << "Name\t\t\t:\t" << detail.buyerName << "\n";
  cout << "Title\t\t\t:\t" << detail.title << "\n";
  cout << "Day of date\t\t:\t" << detail.wacthingTime.day << ", " << detail.wacthingTime.date << "--" << detail.wacthingTime.month << "\n";
  cout << "Time\t\t\t:\t" << detail.time << "\n";
  cout << "Seats\t\t\t:\t";
  for (int i = 0; i < detail.seats.size(); i++) {
    cout << detail.seats[i].alphabet << detail.seats[i].number << ", ";
  }

  cout << "\nPrice\t\t\t:\tRp " << detail.price << " vc" << "\n";
  cout << "Total price\t\t:\tRp " << detail.price * detail.quantity << "\n";
}

#endif
