//
//  ContentView.swift
//  WeScroll
//
//  Created by Marco Bassaletti on 21-08-25.
//

import SwiftUI

struct ContentView: View {
    let letters = [
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "l",
        "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w",
        "x", "y", "z"]
    @State private var flashIndicators = false
    
    var body: some View {
        VStack {
            ScrollView {
                ForEach(letters, id: \.self) {
                    letter in Image(systemName: letter)
                        .font(.largeTitle)
                        .foregroundStyle(.yellow)
                        .frame(width: 50, height: 50)
                        .background(.blue)
                        .symbolVariant(.circle.fill)
                }
            }.frame(width: 50, height: 200)
            ScrollView(.horizontal) {
                HStack {
                    ForEach(letters, id: \.self) {
                        name in Image(systemName: name)
                            .font(.largeTitle)
                            .foregroundStyle(.yellow)
                            .frame(width: 50, height: 50)
                            .background(.blue)
                            .symbolVariant(.circle.fill)
                    }
                }
            }.scrollIndicatorsFlash(trigger: flashIndicators)
                .padding(.bottom)
            Button("Flash") {
                self.flashIndicators.toggle()
            }
        }
        .scrollIndicators(.hidden, axes: .vertical)
        .padding()
    }
}

#Preview {
    ContentView()
}
