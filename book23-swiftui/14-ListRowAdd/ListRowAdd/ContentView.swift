//
//  ContentView.swift
//  ListRowAdd
//
//  Created by Marco Bassaletti on 22-08-25.
//

import SwiftUI

struct NumberRow: Identifiable {
    var id = UUID()
    var value: Int
}

struct ContentView: View {
    @State var numbers = [
        NumberRow(value: 1),
        NumberRow(value: 2),
        NumberRow(value: 3),
        NumberRow(value: 4)
    ]
    
    var body: some View {
        NavigationStack {
            List {
                ForEach(self.numbers) {
                    number in Text("\(number.value)")
                }
            }
            .navigationTitle("Number List")
            .navigationBarTitleDisplayMode(.inline)
            .toolbar {
                ToolbarItem(placement: .topBarTrailing) {
                    Button("Add") {
                        addItemToRow()
                    }
                }
            }
        }
    }
    
    private func addItemToRow() {
        self.numbers.append(
            NumberRow(value:Int.random(in: 1 ..< 10))
        )
    }
}

#Preview {
    ContentView()
}
