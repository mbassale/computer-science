//
//  ContentView.swift
//  DisclosureGroups
//
//  Created by Marco Bassaletti on 24-08-25.
//

import SwiftUI

struct ContentView: View {
    @State private var showPlanets = false
    
    var body: some View {
        VStack {
            DisclosureGroup(isExpanded: $showPlanets) {
                Text("Mercury")
                Text("Venus")
                DisclosureGroup("Earth") {
                    Text("North America")
                    Text("South America")
                    Text("Europe")
                    Text("Asia")
                    Text("Africa")
                    Text("Antarctica")
                    Text("Oceania")
                }
            } label: {
                Text("Planets")
            }
            DisclosureGroup {
                Text("Surprise!")
            } label: {
                Label("Tap to reveal", systemImage: "cube.box")
                    .font(.system(size: 25, design: .rounded))
                    .foregroundStyle(.blue)
            }
        }
        .padding()
    }
}

#Preview {
    ContentView()
}
