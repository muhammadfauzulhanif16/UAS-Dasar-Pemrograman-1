#ifndef READ_SEATS_H
#define READ_SEATS_H

#include "../data/alphabets.cpp"
#include "../data/seats.cpp"

void ReadSeats() {
  if (seats.size() == 0) {
    for (char alphabet : alphabets) {
    vector<Seat> row;

    for (int i = 0; i < alphabets.size(); i++) {
      row.push_back({alphabet, i + 1, true});
    }

    seats.push_back(row);
  } 
  }

  for (auto & row : seats) {
    for (auto & column : row) {
      cout << column.alphabet << column.number << (column.isAvailable ? "" : "*") << " ";
    }

    cout << "\n";
  }
}

#endif