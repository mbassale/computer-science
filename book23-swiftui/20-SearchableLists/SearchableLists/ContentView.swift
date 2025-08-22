//
//  ContentView.swift
//  SearchableLists
//
//  Created by Marco Bassaletti on 22-08-25.
//

import SwiftUI

struct ContentView: View {
    @State private var searchText: String = ""
    let food: [Food] = Food.sampleFood
    
    enum FruitSearchScope: Hashable {
        case all
        case food(Food.Category)
    }
    @State private var scope: FruitSearchScope = .all
    
    var body: some View {
        NavigationStack {
            List {
                ForEach(searchResults, id: \.self) { food in
                    LabeledContent(food.name) {
                        Text("\(food.category.rawValue)")
                    }
                }
            }
            .searchable(text: $searchText, prompt: "Search for food")
            .searchScopes($scope, activation: .onSearchPresentation) {
                Text("All").tag(FruitSearchScope.all)
                Text("Fruit").tag(FruitSearchScope.food(.fruit))
                Text("Vegetable").tag(FruitSearchScope.food(.vegetable))
                Text("Meat").tag(FruitSearchScope.food(.meat))
            }
            .navigationTitle("Foods")
        }
    }
    
    var searchResults: [Food] {
        var food: [Food] = self.food
        if case let .food(category) = scope {
            food = food.filter { $0.category == category }
        }
        
        if !searchText.isEmpty {
            food = food.filter {
                $0.name.lowercased().contains(searchText.lowercased())
            }
        }
        
        return food
    }
}

#Preview {
    ContentView()
}
