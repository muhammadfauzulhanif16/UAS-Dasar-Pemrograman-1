#include <string>
#include <vector>

using namespace std;

struct Movie{
  string title,
    duration,
    rating;
  vector<string> time;
  vector<string> genre;
  int price;
};