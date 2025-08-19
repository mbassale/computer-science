//
//  ContentView.swift
//  TheStacks
//
//  Created by Marco Bassaletti on 18-08-25.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        VStack {
            Text("VStack Item 1")
            Text("VStack Item 2")
            Spacer()
            Divider().background(.black)
            Text("VStack Item 3")
            HStack {
                Text("HStack Item 1")
                Divider().background(.black)
                Text("HStack Item 2")
                Spacer()
                Text("HStack Item 3")
            }.background(.red)
            ZStack {
                Text("ZStack Item 1").padding().background(.green).opacity(0.8)
                Text("ZStack Item 2").padding().background(.green).offset(x: 80, y: -100)
            }
        }
        .background(.blue)
        .padding()
    }
}

#Preview {
    ContentView()
}
