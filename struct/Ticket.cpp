#include <string>
#include <vector>

#include "./Time.cpp"

using namespace std;

struct WatchingSeat{
  char alphabet;
  int number;
};

struct Ticket{
  string buyerName,
    title,
    time;
  vector<WatchingSeat> seats;
  Time wacthingTime;
  int quantity,
    price;
};