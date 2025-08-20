//
//  PasteButtonView.swift
//  Buttons
//
//  Created by Marco Bassaletti on 20-08-25.
//

import SwiftUI

struct PasteButtonView: View {
    @State var text = String()
    
    var body: some View {
        VStack {
            Text("PasteButton controls how you paste in macOS but is not available in iOS.").padding()
        }.navigationTitle("PasteButton")
    }
}

#Preview {
    NavigationStack {
        PasteButtonView()
    }
}
