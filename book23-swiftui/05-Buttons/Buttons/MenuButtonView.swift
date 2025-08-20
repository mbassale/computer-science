//
//  MenuButtonView.swift
//  Buttons
//
//  Created by Marco Bassaletti on 20-08-25.
//

import SwiftUI

struct MenuButtonView: View {
    var body: some View {
        Menu("Choose a country") {
            Button("Canada") { print("Selected Canada") }
            Button("Mexico") { print("Selected Mexico") }
            Button("USA") { print("Selected USA") }
        }.navigationTitle("MenuButtons")
    }
}

#Preview {
    NavigationStack {
        MenuButtonView()
    }
}
