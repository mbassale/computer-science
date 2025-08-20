//
//  ContentView.swift
//  UsingViewModifiers
//
//  Created by Marco Bassaletti on 20-08-25.
//

import SwiftUI

struct BackgroundStyle : ViewModifier {
    var bgColor: Color
    
    func body(content: Content) -> some View {
        content.frame(width: UIScreen.main.bounds.width * 0.3)
            .foregroundStyle(.black)
            .padding()
            .background(bgColor)
            .cornerRadius(20)
    }
}

extension View {
    func backgroundStyle(color: Color) -> some View {
        self.modifier(BackgroundStyle(bgColor: color))
    }
}

struct ContentView: View {
    var body: some View {
        VStack {
            Text("Perfect").backgroundStyle(color: .red)
        }
        .padding()
    }
}

#Preview {
    ContentView()
}
