//
//  ContentView.swift
//  ScrollViewReaders
//
//  Created by Marco Bassaletti on 24-08-25.
//

import SwiftUI

struct CharacterInfo : Identifiable {
    var id: Int
    var name: String
}

extension CharacterInfo {
    static let charArray: [CharacterInfo] = [
        .init(id: 0, name: "a.circle.fill"),
        .init(id: 1, name: "b.circle.fill"),
        .init(id: 2, name: "c.circle.fill"),
        .init(id: 3, name: "d.circle.fill"),
        .init(id: 4, name: "e.circle.fill"),
        .init(id: 5, name: "f.circle.fill"),
        .init(id: 6, name: "g.circle.fill"),
        .init(id: 7, name: "h.circle.fill"),
        .init(id: 8, name: "i.circle.fill"),
        .init(id: 9, name: "j.circle.fill"),
        .init(id: 10, name: "k.circle.fill"),
        .init(id: 11, name: "l.circle.fill"),
        .init(id: 12, name: "m.circle.fill"),
        .init(id: 13, name: "n.circle.fill"),
        .init(id: 14, name: "o.circle.fill"),
        .init(id: 15, name: "p.circle.fill"),
        .init(id: 16, name: "q.circle.fill"),
    ]
}

struct ContentView: View {
    @State private var scrolledID: CharacterInfo.ID?
    
    var body: some View {
        HStack(spacing: 20) {
            VStack {
                Text("iOS 17+")
                    .foregroundStyle(.blue)
                    .font(.title)
                ScrollView {
                    LazyVStack {
                        Button("Go to letter Q") {
                            withAnimation {
                                scrolledID = 16
                            }
                        }
                        .padding()
                        .background(.blue)
                        .tint(.yellow)
                        ForEach(CharacterInfo.charArray) { image in
                            Image(systemName: image.name)
                                .font(.largeTitle)
                                .foregroundStyle(.blue)
                                .frame(width: 90, height: 90)
                                .background(.yellow)
                                .padding()
                        }
                        Button("Go to letter G") {
                            withAnimation {
                                scrolledID = 6
                            }
                        }
                        .padding()
                        .background(.blue)
                        .tint(.yellow)
                    }
                }
                .scrollPosition(id: $scrolledID)
            }
            VStack {
                Text("iOS 14+")
                    .foregroundStyle(.blue)
                    .font(.title)
                ScrollView {
                    ScrollViewReader { proxy in
                        Button("Go to letter Q") {
                            withAnimation {
                                proxy.scrollTo(16, anchor: .bottom)
                            }
                        }
                        .padding()
                        .background(.yellow)
                        ForEach(CharacterInfo.charArray) { image in
                            Image(systemName: image.name)
                                .font(.largeTitle)
                                .foregroundStyle(.yellow)
                                .frame(width: 90, height: 90)
                                .background(.blue)
                                .padding()
                            
                        }
                        Button("Go to letter G") {
                            withAnimation {
                                proxy.scrollTo(6, anchor: .top)
                            }
                        }
                        .padding()
                        .background(.yellow)
                    }
                }
            }
        }
        .padding()
    }
}

#Preview {
    ContentView()
}
