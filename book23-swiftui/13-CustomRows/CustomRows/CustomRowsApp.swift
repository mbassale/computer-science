//
//  CustomRowsApp.swift
//  CustomRows
//
//  Created by Marco Bassaletti on 22-08-25.
//

import SwiftUI

@main
struct CustomRowsApp: App {
    var body: some Scene {
        WindowGroup {
            ContentView(weatherData: WeatherInfo.weatherData)
        }
    }
}
