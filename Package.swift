// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "LongdoMapSDK",
    platforms: [
        .macOS(.v10_15), .iOS(.v12)
    ],
    products: [
        .library(name: "LongdoMapSDK", targets: ["LongdoMapSDK"])
    ],
    targets: [
        .binaryTarget(
            name: "LongdoMapSDK",
            path: "LongdoMapSDK.xcframework"
        )
    ]
)