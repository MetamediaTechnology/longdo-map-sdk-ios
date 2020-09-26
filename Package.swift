// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "LongdoMapSDK",
    platforms: [
        .macOS(.v10_15), .iOS(.v10)
    ],
    products: [
        .library(name: "LongdoMapSDK", targets: ["LongdoMapSDK"])
    ],
    targets: [
        .target(name: "LongdoMapSDK"),
        .binaryTarget(
            name: "LongdoMapSDK",
            path: "LongdoMapSDK.xcframework"
        )
    ]
)