#ifndef READ_MOVIE_DETAILS_H
#define READ_MOVIE_DETAILS_H

void ReadMovieDetails(Movie detail) {
  cout << "==== Movie Details ====\n\n";
  cout << "Title\t\t:\t" << detail.title << "\n";
  cout << "Duration\t:\t" << detail.duration << "\n";
  cout << "Time\t\t:";
  for (int i = 0; i < detail.time.size(); i++) {
    cout << (i == 0 ? "\t" : "\t\t\t\t") <<  i + 1 << ". " << detail.time[i] << "\n";
  }

  cout << "Genre\t\t:";
  for (int i = 0; i < detail.genre.size(); i++) {
    cout << (i == 0 ? "\t" : "\t\t\t\t") <<  i + 1 << ". " << detail.genre[i] << "\n";
  }

  cout << "Rating\t\t:\t" << detail.rating << "\n";
  cout << "Price\t\t:\tRp " << detail.price << "\n\n";
}

#endif