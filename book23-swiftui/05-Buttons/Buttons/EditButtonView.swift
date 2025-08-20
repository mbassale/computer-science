//
//  EditButtonView.swift
//  Buttons
//
//  Created by Marco Bassaletti on 20-08-25.
//

import SwiftUI

struct EditButtonView: View {
    @State private var animals = ["Cats", "Dogs", "Goats"]
    
    var body: some View {
        List {
            ForEach(animals, id: \.self) {
                animal in Text(animal)
            }.onDelete(perform: removeAnimal)
        }.toolbar {
            EditButton()
        }.navigationTitle("EditButtonView")
    }
    
    func removeAnimal(at offsets: IndexSet) {
        animals.remove(atOffsets: offsets)
    }
}

#Preview {
    NavigationStack {
        EditButtonView()
    }
}
