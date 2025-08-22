//
//  ContentView.swift
//  StaticList
//
//  Created by Marco Bassaletti on 21-08-25.
//

import SwiftUI

struct WeatherInfo : Identifiable {
    var id = UUID()
    var image: String
    var temp: Int
    var city: String
}

struct ContentView: View {
    let weatherData: [WeatherInfo] = [
        .init(image: "snow", temp: 25, city: "New York"),
        .init(image: "cloud", temp: 18, city: "London"),
        .init(image: "sun.max", temp: 22, city: "Paris"),
        .init(image: "sun.min", temp: 27, city: "Rome"),
        .init(image: "moon", temp: 15, city: "Tokyo"),
        .init(image: "cloud.rain", temp: 12, city: "Sydney"),
        .init(image: "cloud.rain", temp: 20, city: "Berlin"),
        .init(image: "snow", temp: 23, city: "Moscow"),
        .init(image: "cloud.rain", temp: 19, city: "Rio de Janeiro"),
        .init(image: "sun.max", temp: 24, city: "Bucarest"),
        .init(image: "moon", temp: 14, city: "Dusseldorf"),
        .init(image: "cloud.rain", temp: 11, city: "Madrid"),
        .init(image: "sun.max", temp: 16, city: "Cairo"),
        .init(image: "sun.min", temp: 26, city: "Istanbul"),
        .init(image: "cloud.rain", temp: 17, city: "Santiago"),
    ]
    
    var body: some View {
        List {
            ForEach(weatherData) { weather in
                HStack {
                    Image(systemName: weather.image)
                        .frame(width: 50, alignment: .leading)
                    Text("\(weather.city), \(weather.temp)°C")
                }.font(.system(size: 25))
                    .padding()
            }
        }
    }
}

#Preview {
    ContentView()
}
