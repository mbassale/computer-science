//
//  ContentView.swift
//  UsingViewBuilder
//
//  Created by Marco Bassaletti on 20-08-25.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        VStack {
            BlueCircle {
                Text("some text here")
                Rectangle()
                    .fill(.red)
                    .frame(width: 40, height: 40)
            }
            BlueCircle {
                Text("Another example")
            }
        }
        .padding()
    }
}

#Preview {
    ContentView()
}
