//
//  ButtonView.swift
//  Buttons
//
//  Created by Marco Bassaletti on 20-08-25.
//

import SwiftUI

struct ButtonView: View {
    @State var count = 0
    
    var body: some View {
        VStack {
            Text("Welcome to your second view")
            Text("Current count value: \(count)")
                .padding()
            Button {
                count += 1
            } label: {
                Text("Tap to Increment Count")
                    .fontWeight(.bold)
                    .foregroundStyle(.white)
                    .padding()
                    .background(.blue)
                    .clipShape(Capsule())
            }
        }.navigationBarTitle("Button View")
    }
}

#Preview {
    NavigationStack {
        ButtonView()
    }
}
