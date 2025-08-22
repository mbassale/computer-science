//
//  ContentView.swift
//  CustomRows
//
//  Created by Marco Bassaletti on 22-08-25.
//

import SwiftUI

struct ContentView: View {
    var weatherData: [WeatherInfo]
    
    var body: some View {
        List {
            ForEach(weatherData) { weather in
                WeatherRow(weather: weather)
            }
        }
    }
}

#Preview {
    ContentView(weatherData: WeatherInfo.weatherData)
}
