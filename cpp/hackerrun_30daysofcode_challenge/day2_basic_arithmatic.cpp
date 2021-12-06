#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
void solve(double meal_cost, int tip_percent, int tax_percent) {
  double total_cost = meal_cost*(1.0 + double(tip_percent+tax_percent)/100.0);
  if (total_cost - int(total_cost) > double(0.5)) {
      total_cost = int(total_cost) + 1;      
  } else {
      total_cost = int(total_cost);
  }

  cout << total_cost;
    

}

int main()
{
    double meal_cost;
    cin >> meal_cost;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tip_percent;
    cin >> tip_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tax_percent;
    cin >> tax_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    solve(meal_cost, tip_percent, tax_percent);

    return 0;
}
