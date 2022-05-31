#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

string tournamentWinner(const vector<vector<string>> &competitions, const vector<int> &results)
{
  string winnerTeam;
  string maxTeam = "";
  int maxTeamScore = numeric_limits<int>::min();
  unordered_map<string, int> scores;
  for (int matchNumber = 0; matchNumber < results.size(); matchNumber++)
  {
    const auto result = results[matchNumber];
    if (result)
    { // home team won
      winnerTeam = competitions[matchNumber][0];
    }
    else
    { // away team won
      winnerTeam = competitions[matchNumber][1];
    }
    scores[winnerTeam] = scores[winnerTeam] + 3;
    if (scores[winnerTeam] > maxTeamScore)
    {
      maxTeam = winnerTeam;
      maxTeamScore = scores[winnerTeam];
    }
  }
  return maxTeam;
}

int main()
{
  string winner;
  const auto printWinner = [&winner]()
  {
    cout << winner << endl;
  };

  winner = tournamentWinner({{"HTML", "C#"},
                             {"C#", "Python"},
                             {"Python", "HTML"}},
                            {0, 0, 1});
  printWinner();

  winner = tournamentWinner({{"Bulls", "Eagles"},
                             {"Bulls", "Bears"},
                             {"Bulls", "Monkeys"},
                             {"Eagles", "Bears"},
                             {"Eagles", "Monkeys"},
                             {"Bears", "Monkeys"}},
                            {1, 1, 1, 1, 1, 1});
  printWinner();
  return 0;
}