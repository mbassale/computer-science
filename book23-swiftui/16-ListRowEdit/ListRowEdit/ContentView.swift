//
//  ContentView.swift
//  ListRowEdit
//
//  Created by Marco Bassaletti on 22-08-25.
//

import SwiftUI

struct ContentView: View {
    @State private var countries = [
        "France", "Italy", "Spain", "Germany", "United Kingdom",
        "United States", "Canada", "Australia", "Brazil"
    ]
    
    var body: some View {
        NavigationStack {
            List {
                ForEach(countries, id: \.self) { country in
                    Text(country)
                }.onDelete(perform: deleteItem)
            }
            .navigationTitle("Countries")
            .navigationBarTitleDisplayMode(.inline)
            .toolbar { EditButton() }
        }
    }
    
    private func deleteItem(at offsets: IndexSet) {
        countries.remove(atOffsets: offsets)
    }
}

#Preview {
    ContentView()
}
