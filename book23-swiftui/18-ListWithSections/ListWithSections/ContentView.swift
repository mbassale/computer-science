//
//  ContentView.swift
//  ListWithSections
//
//  Created by Marco Bassaletti on 22-08-25.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        NavigationStack {
            List {
                Section(header: Text("North America")) {
                    Text("USA")
                    Text("Canada")
                    Text("Mexico")
                    Text("Panama")
                    Text("Anguilla")
                }
                Section(header: Text("South America")) {
                    Text("Argentina")
                    Text("Brazil")
                    Text("Chile")
                    Text("Peru")
                    Text("Ecuador")
                }
                Section(header: Text("Europe")) {
                    Text("Spain")
                    Text("France")
                    Text("Sweden")
                    Text("Finland")
                    Text("UK")
                }
            }
            .listStyle(.grouped)
            .navigationTitle("Continents and Countries")
            .navigationBarTitleDisplayMode(.inline)
        }
    }
}

#Preview {
    ContentView()
}
