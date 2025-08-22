//
//  ContentView.swift
//  EditableListsFields
//
//  Created by Marco Bassaletti on 22-08-25.
//

import SwiftUI

struct TodoItem: Identifiable {
    let id = UUID()
    var title: String
}

struct ContentView: View {
    @State private var todos = [
        TodoItem(title: "Eat"),
        TodoItem(title: "Drink"),
        TodoItem(title: "Code"),
    ]
    
    var body: some View {
        List($todos) { $todo in
            TextField("Todo Item", text: $todo.title)
        }
        .padding()
    }
}

#Preview {
    ContentView()
}
