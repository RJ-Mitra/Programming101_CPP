
#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;

void DrawProgressBar(int len, double percent) {
  cout << "\x1B[2K"; // Erase the entire current line.
  cout << "\x1B[0E"; // Move to the beginning of the current line.
  string progress;
  for (int i = 0; i < len; ++i) {
    if (i < static_cast<int>(len * percent)) {
      progress += "=";
    } else {
      progress += " ";
    }
    sleep(1);
  }
  cout << "[" << progress << "] " << (static_cast<int>(100 * percent)) << "%";
  flush(cout); // Required.
}

int main(){
    DrawProgressBar(100,1);
}