#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using namespace std::chrono;

vector<string> splitText(const string& text) {
  vector<string> res;
  auto leftIt = text.begin();
  auto rightIt = text.begin();

  while (leftIt < text.end() && rightIt < text.end()) {

    // eat up beggining whitespace
    while (isspace(*leftIt) && isspace(*rightIt) && leftIt != text.end() &&
           rightIt != text.end()) {
      leftIt++;
      rightIt++;
    }

    // move rightIt to the next whitespace
    while (!isspace(*rightIt) && rightIt != text.end()) {
      rightIt++;
    }

    string token;
    std::copy(leftIt, rightIt, std::back_inserter(token));
    res.push_back(token);

    leftIt = rightIt;
  }

  return res;
}

string randomizeWhitespace(const string& str) {
  string res;
  auto it = str.begin();
  while (it != str.end()) {
    if (isspace(*it)) {
      auto numSpaces = rand() % 10;
      while (numSpaces-- > 0) {
        res.push_back(' ');
      }
    } else {
      res.push_back(*it);
    }
    it++;
  }
  return res;
}

// Time: O(n) Space: O(n)
bool messageFromTextHashMap(const string& text, const string& note) {
  // build frequency table of words from text
  unordered_map<string, size_t> textWordFreqs;
  vector<string> textWords = splitText(text);
  for (const auto& word : textWords) {
    textWordFreqs[word]++;
  }

  // build frequency table of words from note
  unordered_map<string, size_t> noteWordFreqs;
  vector<string> noteWords = splitText(note);
  for (const auto& word : noteWords) {
    noteWordFreqs[word]++;
  }

  // intercept both frequency tables
  auto noteFreqIt = noteWordFreqs.begin();

  while (noteFreqIt != noteWordFreqs.end()) {
    const auto lookupWord = noteFreqIt->first;
    const auto lookupFreq = noteFreqIt->second;
    // Time: O(1) due to hashing
    if (textWordFreqs.find(lookupWord) != textWordFreqs.end() &&
        textWordFreqs[lookupWord] >= lookupFreq) {
      textWordFreqs[lookupWord] -= lookupFreq;
    } else {
      return false;
    }
    noteFreqIt++;
  }

  return true;
}

void invokeMessageFromTextHashMap(const string& text, const string& note) {
  const auto start = high_resolution_clock::now();
  const auto result = messageFromTextHashMap(text, note);
  const auto end = high_resolution_clock::now();
  const auto delta = duration_cast<microseconds>(end - start);
  cout << "Text: " << text << endl;
  cout << "Note: " << note << endl;
  cout << "messageFromTextHashMap(%, %) = " << (result ? "true" : "false")
       << " Runtime: " << delta.count() << "us" << endl;
}

int main(int argc, char* argv[]) {
  // initialize naive random gen
  srand(time(NULL));

  invokeMessageFromTextHashMap(
      "lorem ipsum dolor senet senesque ipsum lorem republicam abbatio laborum "
      "pater",
      "lorem dolor senet");

  invokeMessageFromTextHashMap(
      randomizeWhitespace("lorem isum dolor senet senesque ipsum lorem "
                          "republicam abbatio laborum "
                          "abbatio"),
      "abbatio abbatio abbatio");
  return EXIT_SUCCESS;
}