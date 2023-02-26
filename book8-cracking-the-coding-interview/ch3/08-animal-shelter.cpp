#include <cassert>
#include <exception>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Queue {
 public:
  Queue() {}

  void enqueue(const T& value) { data_.push_back(value); }
  T dequeue() {
    auto val = data_.front();
    data_.pop_front();
    return val;
  }

  T& front() { return data_.front(); }
  T& back() { return data_.back(); }

  size_t size() const { return data_.size(); }
  bool empty() const { return data_.empty(); }

 private:
  list<T> data_;
};

enum class AnimalType {
  UNKNOWN = 0,
  CAT,
  DOG,
};

struct AnimalRecord {
  string name;
  size_t index;

  AnimalRecord(const string& name, const size_t index) : name(name), index(index) {}
};

class AnimalShelter {
 public:
  AnimalShelter() {}

  void enqueue(AnimalType type, string name) {
    switch (type) {
      case AnimalType::CAT:
        catQueue.enqueue(AnimalRecord(name, ++lastCatIndex));
        break;
      case AnimalType::DOG:
        dogQueue.enqueue(AnimalRecord(name, ++lastDogIndex));
        break;
      default:
        throw new std::logic_error("Invalid Animal Type");
    }
  }

  size_t size(const AnimalType type = AnimalType::UNKNOWN) const {
    switch (type) {
      case AnimalType::CAT:
        return catQueue.size();
      case AnimalType::DOG:
        return dogQueue.size();
      case AnimalType::UNKNOWN:
        return size(AnimalType::CAT) + size(AnimalType::DOG);
      default:
        throw new std::logic_error("Invalid Animal Type");
    }
  }

  string dequeueAny() {
    auto catsz = catQueue.size();
    auto dogsz = dogQueue.size();
    if (catsz > 0 && dogsz > 0) {
      const auto& catRec = catQueue.front();
      const auto& dogRec = dogQueue.front();
      if (catRec.index <= dogRec.index) {
        return dequeueCat();
      } else {
        return dequeueDog();
      }
    }
    if (dogsz == 0 && catsz > 0) {
      return dequeueCat();
    } else if (catsz == 0 && dogsz > 0) {
      return dequeueDog();
    }
    assert(false);
  }

  string dequeueDog() {
    assert(!dogQueue.empty());
    return dogQueue.dequeue().name;
  }

  string dequeueCat() {
    assert(!catQueue.empty());
    return catQueue.dequeue().name;
  }

 private:
  Queue<AnimalRecord> dogQueue;
  size_t lastDogIndex = 0;
  Queue<AnimalRecord> catQueue;
  size_t lastCatIndex = 0;
};

int main(int argc, char* argv[]) {
  AnimalShelter animalShelter;

  vector<string> cats = {"tomasa", "tom", "benito", "fluffly"};
  vector<string> dogs = {"strech", "momo", "pumking", "marsh"};
  for (size_t i = 0; i < cats.size(); i++) {
    cout << "Enqueue CAT: " << cats[i] << endl;
    animalShelter.enqueue(AnimalType::CAT, cats[i]);
    cout << "Enqueue DOG: " << dogs[i] << endl;
    animalShelter.enqueue(AnimalType::DOG, dogs[i]);
  }
  for (size_t i = animalShelter.size(); i > 0; i--) {
    cout << "Dequeue: " << animalShelter.dequeueAny()
         << " Size: " << animalShelter.size() << endl;
  }
  return EXIT_SUCCESS;
}