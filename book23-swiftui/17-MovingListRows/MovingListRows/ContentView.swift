//
//  ContentView.swift
//  MovingListRows
//
//  Created by Marco Bassaletti on 22-08-25.
//

import SwiftUI

struct ContentView: View {
    @State private var countries = ["United States", "Italy", "France", "Spain", "Germany", "United Kingdom", "Japan", "Brazil", "Russia", "Canada"]
    
    var body: some View {
        NavigationStack {
            List {
                ForEach(countries, id: \.self) { country in
                    Text(country)
                }.onMove(perform: moveRow)
            }
            .navigationTitle(Text("Countries"))
            .navigationBarTitleDisplayMode(.inline)
            .toolbar {
                EditButton()
            }
        }
    }
    
    private func moveRow(source: IndexSet, destination: Int) {
        countries.move(fromOffsets: source, toOffset: destination)
    }
}

#Preview {
    ContentView()
}
