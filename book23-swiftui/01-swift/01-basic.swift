#!/usr/bin/env swift

// Hello World
print("Hello, World!")

// Variables and Constants
var myVariable = 42
myVariable = 50
print("myVariable is \(myVariable)")

let myConstant = 42
print("myConstant is \(myConstant)")

// Type Annotations
let explicitDouble: Double = 70
let explicitFloat: Float = 4.0
print("explicitDouble is \(explicitDouble), explicitFloat is \(explicitFloat)")

// Type Inference
let label = "The width is "
let width = 94
let widthLabel = label + String(width) + " pixels"
print(widthLabel)

// String Interpolation
let quote1 = "Where shall I begin, please your Majesty?"
let quote2 = "Begin at the beginning,"
let quote3 = "and go on till you come to the end; then stop."
let quotation = """
The White Rabbit put on his spectacles.
\(quote1) he asked.
\(quote2) the King said gravely, \(quote3)
"""
print(quotation)

// Arrays and Dictionaries
var fruits = ["Apple", "Banana", "Cherry"]
fruits.append("Pear")
print("Fruits: \(fruits)")

var jobTitles = ["Alice": "Engineer", "Bob": "Designer"]
jobTitles["Charlie"] = "Manager"
print("Job Titles: \(jobTitles)")

// Control Flow
let individualScores = [75, 43, 103, 87, 12]
var teamScore = 0
for score in individualScores {
    if score > 50 {
        teamScore += 3
    } else {
        teamScore += 1
    }
}
print("Team Score: \(teamScore)")
let scoreEmoji = if teamScore > 10 { "🏆" } else { "😞" }
print("Score Emoji: \(scoreEmoji)")

// Optionals
var optionalString: String? = "Hello"
print("optionalString is \(optionalString == nil ? "nil" : optionalString!)")
optionalString = nil
print("optionalString is \(optionalString ?? "nil")")

// Switch Statement
let vegetable = "red pepper"
switch vegetable {
case "celery":
    print("Add some raisins and make ants on a log.")
case "cucumber", "watercress":
    print("That would make a good tea sandwich.")
case let x where x.hasSuffix("pepper"):
    print("Is it a spicy \(x)?")
default:
    print("Everything tastes good in soup.")
}

// For loops
let interestingNumbers = [
    "Prime": [2, 3, 5, 7, 11, 13],
    "Fibonacci": [1, 1, 2, 3, 5, 8],
    "Square": [1, 4, 9, 16, 25]
]
var largest = 0
for (kind, numbers) in interestingNumbers {
    print("Interesting numbers of type \(kind): \(numbers)")
    for number in numbers {
        if number > largest {
            largest = number
        }
    }
}
print("The largest number is \(largest)")

// Range Operators
let range = 1...5
for index in range {
    print("Index: \(index)")
}

// Functions
func greet(person: String, day: String) -> String {
    return "Hello \(person), today is \(day)."
}
let greeting = greet(person: "Marco", day: "Friday")
print(greeting)

// Function as first-class citizens
func makeIncrementer(step: Int) -> ((Int) -> Int) {
    func addStep(number: Int) -> Int {
        return step + number
    }
    return addStep
}
let incrementByTwo = makeIncrementer(step: 2)
print("Incrementing 7 by 2 gives: \(incrementByTwo(7))")

// Closures
let numbers = [5, 3, 100, 3, 9]
let mappedNumbers = numbers.map({ number in 3 * number})
print("Mapped Numbers: \(mappedNumbers)")

// Tuples
func calculateStatistics(scores: [Int]) -> (min: Int, max: Int, sum: Int) {
    var min = scores[0]
    var max = scores[0]
    var sum = 0
    
    for score in scores {
        if score < min {
            min = score
        }
        if score > max {
            max = score
        }
        sum += score
    }
    
    return (min, max, sum)
}
let stats = calculateStatistics(scores: [5, 3, 100, 3, 9])
print("Min: \(stats.min), Max: \(stats.max), Sum: \(stats.sum)")

// Objects and Classes
class Shape {
    var name: String
    var numberOfSides: Int = 0

    init(name: String, numberOfSides: Int) {
        self.name = name
        self.numberOfSides = numberOfSides
        print("Creating a shape named \(name), which has \(numberOfSides) sides.")
    }
    
    func simpleDescription() -> String {
        return "A shape named \(name), which has \(numberOfSides) sides."
    }
}
var shape = Shape(name: "Hexagon", numberOfSides: 6)
print(shape.simpleDescription())

class Square: Shape {
    var sideLength: Double
    
    init(sideLength: Double) {
        self.sideLength = sideLength
        super.init(name: "Square", numberOfSides: 4)
    }

    var area: Double {
        return sideLength * sideLength
    }

    var perimeter: Double {
        return 4 * sideLength
    }
    
    override func simpleDescription() -> String {
        return "A square with side length \(sideLength)."
    }
}
let square = Square(sideLength: 5.0)
print(square.simpleDescription())
print("Area of square: \(square.area)")
print("Perimeter of square: \(square.perimeter)")

let optionalSquare: Square? = Square(sideLength: 3.0)
let area = optionalSquare?.area ?? 0.0
print("Area of optional square: \(area)")

// Enumerations and Structures
enum Priority: Int {
    case unknown = 0, low, medium, high

    init?(rawValue: Int) {
        switch rawValue {
        case 0:
            self = .unknown
        case 1:
            self = .low
        case 2:
            self = .medium
        case 3:
            self = .high
        default:
            return nil
        }
    }

    func description() -> String {
        switch self {
        case .unknown:
            return "Unknown Priority"
        case .low:
            return "Low Priority"
        case .medium:
            return "Medium Priority"
        case .high:
            return "High Priority"
        }
    }
}
let taskPriority = Priority.high
print("Task Priority: \(taskPriority.description())")
if let convertedPriority = Priority(rawValue: 2) {
    print("Converted Priority: \(convertedPriority.description())")
}

enum ServerResponse {
    case result(String, String)
    case failure(String)

    func description() -> String {
        switch self {
        case .result(let code, let message):
            return "Response code: \(code), message: \(message)"
        case .failure(let error):
            return "Error: \(error)"
        }
    }
}

let successResponse = ServerResponse.result("200", "OK")
switch successResponse {
case .result(_, _):
    print("Success: \(successResponse.description())")
case .failure(let error):
    print("Failure: \(error)")
}

// Structs are value types
// Classes are reference types
struct Card {
    var rank: String
    var suit: String

    func description() -> String {
        return "\(rank) of \(suit)"
    }
}
let card = Card(rank: "Ace", suit: "Spades")
print("Card: \(card.description())")

// Concurrency
func fetchUserID(from server: String) async -> Int {
    // Simulate network delay
    try? await Task.sleep(nanoseconds: 2_000_000_000)
    return 42 // Simulated user ID
}
Task {
    let userID = await fetchUserID(from: "https://example.com")
    print("Fetched User ID: \(userID)")
}