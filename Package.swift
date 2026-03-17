// swift-tools-version:5.6
import PackageDescription

let package = Package(
    name: "Qlift",
    platforms: [.macOS(.v10_15)],
    products: [
        .library(name: "Qlift", targets: ["Qlift"]),
    ],
    targets: [
        .target(name: "Qlift",
                dependencies: ["CQlift"]),
        .target(name: "CQlift",
                dependencies: ["CQt6Widgets", "CQt6Quick", "CQt6Gui"],
                cxxSettings: [.headerSearchPath("private")]),
        .systemLibrary(name: "CQt6Widgets", pkgConfig: "Qt6Widgets"),
        .systemLibrary(name: "CQt6Quick", pkgConfig: "Qt6Quick"),
        .systemLibrary(name: "CQt6Gui", pkgConfig: "Qt6Gui"),
    ],
    cxxLanguageStandard: .cxx17
)
